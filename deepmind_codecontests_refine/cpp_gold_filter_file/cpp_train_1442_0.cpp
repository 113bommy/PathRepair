#include<iostream>
using namespace std;
int main(){
  int r,g,b,ans;
  cin>>r>>g>>b;
  ans=r*100+g*10+b;
  cout<<(ans%4==0?"YES":"NO");
}
