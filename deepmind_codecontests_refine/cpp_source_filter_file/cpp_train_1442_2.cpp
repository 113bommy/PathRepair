#include<iostream>
using namespace std
int main(){
  int r,g,b;
  cin>>r>>g>>b;
  ((10*g+r)%4==0)?cout<<"YES":cout<<"NO";
  return 0;
}
