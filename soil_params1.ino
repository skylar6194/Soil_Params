#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);
int moisture;
float moisture_percentage;
int temp_celcius=0;
int light = 0;



void setup(){
 lcd.begin(16, 2);
 lcd.setCursor(0,0);
 lcd.print(" SOIL PARAMETERS");//Initial Welcome Screen 
 delay(3000);
 
 pinMode(A2, INPUT);
 pinMode(A1,INPUT);
  
 Serial.begin(9600);}

void loop(){
/*For Ambient Lighting in the field area*/
light = analogRead(A2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("*AMBIENT LIGHT*");lcd.setCursor(5,1);lcd.print(light);lcd.print(" Lux");   
delay(5000);
  
  
  
/*For Moisture % in soil*/
moisture=analogRead(A0);
moisture_percentage=((moisture/539.00)*100);
lcd.clear();
lcd.setCursor(3,0);
lcd.print("*MOISTURE*");lcd.setCursor(2,1);lcd.print(moisture);lcd.print(" | ");lcd.print(moisture_percentage);lcd.print("%");      
delay(5000);  
  
  
/*For Temperature of the soil*/
int temp_raw = analogRead(A1);
float temp_voltage = temp_raw*(5.0/1024.0);
float temperatureC=(temp_voltage-0.5)*100;
float temperatureF =(temperatureC*9.0/5.0) + 32.0;
lcd.clear();
lcd.setCursor(2,0);
lcd.print("*TEMPERATURE*");lcd.setCursor(0,1);lcd.print(temperatureC);lcd.print("C | ");lcd.print(temperatureF);lcd.print("F");      
delay(5000);
  
}