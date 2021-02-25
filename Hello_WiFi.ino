#define BLINKER_WIFI
 
#include <Blinker.h>
 
char auth[] = "d6bc979a458b";
char ssid[] = "D1";
char pswd[] = "01234567890";
 
// 新建组件对象
BlinkerButton Button1("btn-abc");
int deng=12;
 
// 按下按键即会执行该函数
void button1_callback(const String & state) {
    BLINKER_LOG("get button state: ", state);
    digitalWrite(deng, !digitalRead(deng));
    Blinker.vibrate();
}
 
void setup() {
    // 初始化串口，并开启调试信息
    Serial.begin(115200);    
    BLINKER_DEBUG.stream(Serial);
    // 初始化有LED的IO
    pinMode(deng, OUTPUT);
    digitalWrite(deng, HIGH);
    // 初始化blinker
    Blinker.begin(auth, ssid, pswd);
    Button1.attach(button1_callback);
}
 
void loop() {
    Blinker.run();
}
