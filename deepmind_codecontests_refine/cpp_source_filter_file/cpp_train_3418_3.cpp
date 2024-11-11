#include <iostream>
using namesapce std;

int main(){
  int a,b,c,d,e,f,g,h,i;
  cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
  bool ans=false;
  if(a+e+i==c+d+h && a+e+i==b+f+g && c+e+g==a+f+h && c+e+g==b+d+i){
    ans=true;
  }
  cout << (ans?"Yes":"No") << endl;
}