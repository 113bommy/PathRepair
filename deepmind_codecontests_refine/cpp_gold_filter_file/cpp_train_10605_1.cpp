#include <iostream>
using namespace std;
int main(){
  double xa1,ya1,xa2,ya2,xb1,yb1,xb2,yb2;
  while( cin >>xa1>>ya1>>xa2>>ya2>>xb1>>yb1>>xb2>>yb2 ){
  if(!(xb2 < xa1 || xa2 < xb1 || ya1 > yb2 || ya2 < yb1 ))cout << "YES"<<endl;
  else cout << "NO" << endl;
  }
  return 0;
}