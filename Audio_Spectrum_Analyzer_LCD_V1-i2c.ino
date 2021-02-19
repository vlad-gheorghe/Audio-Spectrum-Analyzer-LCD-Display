// HAZI TECH
// By Hasitha Jayasundara
// Visit my YouTube Channel - http://www.youtube.com/c/HAZITECH?sub_confirmation=1
//A0 signal input

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define AUTO_GAIN 1       // auto adjust by volume
#define VOL_THR 45        // silence threshold (below it there will be no display on the matrix)
#define LOW_PASS 40       // lower threshold of noise sensitivity (no jumps in the absence of sound)
#define DEF_GAIN 120      // default maximum threshold 
#define FHT_N 256         // spectrum width x2
#define LOG_OUT 1

#include <FHT.h> 
#include <EEPROM.h>
//#include <LiquidCrystal.h>
//LiquidCrystal lcd(7, 6, 5, 4, 3, 2);// RS,E,D4,D5,D6,D7
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte posOffset[16] = {2, 3, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
byte maxValue, maxValue_f,set=1,gain_sp = DEF_GAIN;
float k = 0.1;
int i,j,pattern;
unsigned long gainTimer;
int buttonPin = 9;

void setup()
{ 
Serial.begin(9600);
ADMUX  = 0b01100000; ADCSRA = 0b11010100; 
//lcd.begin( 16,2 );
lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  
pinMode(buttonPin, INPUT);
digitalWrite(buttonPin, LOW);     // Initializing
digitalWrite(buttonPin, HIGH);    // button pin is HIGH, so it drops to 0 if pressed
pattern = EEPROM.read(100);
}

void loop()
{
if(digitalRead(buttonPin)==LOW){pattern++;EEPROM.update(100,pattern); set=1;if(pattern>5){pattern=0;}delay(300);}

      if(pattern==0&&set==1){
      byte v1[8] = {0, 0, 0, 0, 0, 0, 0, 31};
      byte v2[8] = {0, 0, 0, 0, 0, 0, 31, 31};
      byte v3[8] = {0, 0, 0, 0, 0, 0, 31, 31};
      byte v4[8] = {0, 0, 0, 0, 31, 0, 31, 31};
      byte v5[8] = {0, 0, 0, 31, 31, 0, 31, 31};
      byte v6[8] = {0, 0, 0, 31, 31, 0, 31, 31};
      byte v7[8] = {0, 31, 0, 31, 31, 0, 31, 31};
      byte v8[8] = {31, 31, 0, 31, 31, 0, 31, 31};
      lcd.createChar(0, v1);lcd.createChar(1, v2);lcd.createChar(2, v3);lcd.createChar(3, v4);lcd.createChar(4, v5);lcd.createChar(5, v6);lcd.createChar(6, v7);lcd.createChar(7, v8);
      set=0;}

      if(pattern==1&&set==1){
      byte v1[8] = {0, 0, 0, 0, 0, 0, 0, 27};
      byte v2[8] = {0, 0, 0, 0, 0, 0, 27, 27};
      byte v3[8] = {0, 0, 0, 0, 0, 0, 27, 27};
      byte v4[8] = {0, 0, 0, 0, 27, 0, 27, 27};
      byte v5[8] = {0, 0, 0, 27, 27, 0, 27, 27};
      byte v6[8] = {0, 0, 0, 27, 27, 0, 27, 27};
      byte v7[8] = {0, 27, 0, 27, 27, 0, 27, 27};
      byte v8[8] = {27, 27, 0, 27, 27, 0, 27, 27};
      lcd.createChar(0, v1);lcd.createChar(1, v2);lcd.createChar(2, v3);lcd.createChar(3, v4);lcd.createChar(4, v5);lcd.createChar(5, v6);lcd.createChar(6, v7);lcd.createChar(7, v8);
      set=0;}

      if(pattern==2&&set==1){
      byte v1[8] = {0, 0, 0, 0, 0, 0, 0, 14};
      byte v2[8] = {0, 0, 0, 0, 0, 0, 14, 14};
      byte v3[8] = {0, 0, 0, 0, 0, 0, 14, 14};
      byte v4[8] = {0, 0, 0, 0, 14, 0, 14, 14};
      byte v5[8] = {0, 0, 0, 14, 14, 0, 14, 14};
      byte v6[8] = {0, 0, 0, 14, 14, 0, 14, 14};
      byte v7[8] = {0, 14, 0, 14, 14, 0, 14, 14};
      byte v8[8] = {14, 14, 0, 14, 14, 0, 14, 14};
      lcd.createChar(0, v1);lcd.createChar(1, v2);lcd.createChar(2, v3);lcd.createChar(3, v4);lcd.createChar(4, v5);lcd.createChar(5, v6);lcd.createChar(6, v7);lcd.createChar(7, v8);
      set=0;}
      
      if(pattern==3&&set==1){
      byte v1[8] = {0, 0, 0, 0, 0, 0, 0, 31};
      byte v2[8] = {0, 0, 0, 0, 0, 0, 31, 31};
      byte v3[8] = {0, 0, 0, 0, 0, 31, 31, 31};
      byte v4[8] = {0, 0, 0, 0, 31, 31, 31, 31};
      byte v5[8] = {0, 0, 0, 31, 31, 31, 31, 31};
      byte v6[8] = {0, 0, 31, 31, 31, 31, 31, 31};
      byte v7[8] = {0, 31, 31, 31, 31, 31, 31, 31};
      byte v8[8] = {31, 31, 31, 31, 31, 31, 31, 31};
      lcd.createChar(0, v1);lcd.createChar(1, v2);lcd.createChar(2, v3);lcd.createChar(3, v4);lcd.createChar(4, v5);lcd.createChar(5, v6);lcd.createChar(6, v7);lcd.createChar(7, v8);
      set=0;}

      if(pattern==4&&set==1){
      byte v1[8] = {0, 0, 0, 0, 0, 0, 0, 27};
      byte v2[8] = {0, 0, 0, 0, 0, 0, 27, 27};
      byte v3[8] = {0, 0, 0, 0, 0, 27, 27, 27};
      byte v4[8] = {0, 0, 0, 0, 27, 27, 27, 27};
      byte v5[8] = {0, 0, 0, 27, 27, 27, 27, 27};
      byte v6[8] = {0, 0, 27, 27, 27, 27, 27, 27};
      byte v7[8] = {0, 27, 27, 27, 27, 27, 27, 27};
      byte v8[8] = {27, 27, 27, 27, 27, 27, 27, 27};
      lcd.createChar(0, v1);lcd.createChar(1, v2);lcd.createChar(2, v3);lcd.createChar(3, v4);lcd.createChar(4, v5);lcd.createChar(5, v6);lcd.createChar(6, v7);lcd.createChar(7, v8);
      set=0;}
      
      if(pattern==5&&set==1){
      byte v1[8] = {0, 0, 0, 0, 0, 0, 0, 14};
      byte v2[8] = {0, 0, 0, 0, 0, 0, 14, 14};
      byte v3[8] = {0, 0, 0, 0, 0, 14, 14, 14};
      byte v4[8] = {0, 0, 0, 0, 14, 14, 14, 14};
      byte v5[8] = {0, 0, 0, 14, 14, 14, 14, 14};
      byte v6[8] = {0, 0, 14, 14, 14, 14, 14, 14};
      byte v7[8] = {0, 14, 14, 14, 14, 14, 14, 14};
      byte v8[8] = {14, 14, 14, 14, 14, 14, 14, 14};
      lcd.createChar(0, v1);lcd.createChar(1, v2);lcd.createChar(2, v3);lcd.createChar(3, v4);lcd.createChar(4, v5);lcd.createChar(5, v6);lcd.createChar(6, v7);lcd.createChar(7, v8);
      set=0;}
    
analyzeAudio();   // FHT function, clogs the fht_log_out [] array with values ​​along the spectrum

   for (int pos = 0; pos < 16; pos++) 
    {  
    if (fht_log_out[posOffset[pos]] > maxValue) maxValue = fht_log_out[posOffset[pos]];
    lcd.setCursor(pos, 0);
    int posLevel = map(fht_log_out[posOffset[pos]], LOW_PASS, gain_sp, 0, 15);posLevel = constrain(posLevel, 0, 15);
        
  while(j<2){j++;delay(2);
    if (posLevel > 7) {lcd.write((uint8_t)posLevel-8);lcd.setCursor(pos, 1);lcd.write((uint8_t)7);} 
     else {lcd.print(" ");lcd.setCursor(pos, 1);lcd.write((uint8_t)posLevel); }}j=0;}

  if (AUTO_GAIN) {
    maxValue_f = maxValue * k + maxValue_f * (1 - k);
    if (millis() - gainTimer > 1500) {   
    if (maxValue_f > VOL_THR) gain_sp = maxValue_f;
      else gain_sp = 150;gainTimer = millis();}
      else {gain_sp = DEF_GAIN;}}
}                       // loop


void analyzeAudio() 
{ 
while(i < FHT_N){i++; 
do{ADCSRA |= (1 << ADSC);} 
while((ADCSRA & (1 << ADIF)) == 0);fht_input[i] = (ADCL|ADCH << 8);}i=0;
fht_window();         // window the data for better frequency response
fht_reorder();        // reorder the data before doing the fht
fht_run();            // process the data in the fht
fht_mag_log();        // take the output of the fht
}
