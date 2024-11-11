#include<iostream>
#include<algorithm>
using namesapce std;
int main(){
  int a,b,c;cin >> a >> b >> c;
  cout << a+b+c-max({a,b,c}) << endl;
}