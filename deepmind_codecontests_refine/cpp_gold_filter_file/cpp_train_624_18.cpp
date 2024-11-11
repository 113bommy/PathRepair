#include<iostream>

using namespace std;

int main(){
  int a,b,c,cnt=0;
  cin >> a >> b >>c;
  for(a=a;a<=b;a++){
    if(c%a==0) cnt++;
  }
  cout << cnt << endl;
}
