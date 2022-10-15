int lowerThreshold = 300;
int upperThreshold = 800;
#include "DHT.h"
#include<LiquidCrystal.h>
#define DHTPIN A1
#define DHTTYPE DHT11
#define sensorPower 7
#define sensorPin A0
#define sensorPower 7
LiquidCrystal lcd(12,11,5,4,3,2);
DHT dht(DHTPIN,DHTTYPE);

// Value for water level
int val = 0;


void setup() {
  Serial.begin(9600);
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);
  delay(500);
  lcd.begin(16,2);
  dht.begin();
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);
}

void loop() {
  int level = readSensor();
  Serial.print("Water level: ");
  Serial.println(level);
  delay(1000);
  if (level == 0) {
    Serial.println("Water Level: Empty");
  }
  else if (level > 0 && level <= lowerThreshold) {
    lcd.print("No water! ");
    delay(100);
  }
  else if (level > lowerThreshold && level <= upperThreshold) {
    lcd.print("Water!  ");
    delay(100);
  }
  else if (level > upperThreshold) {
    lcd.print("Water!!! ");
    delay(100);
  }
  delay(5000);
  lcd.clear();
}

//This is a function used to get the reading
int readSensor() {
  digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
  delay(5);              // wait 10 milliseconds
  val = analogRead(sensorPin);    // Read the analog value form sensor
  digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
  return val;             // send current reading
}
