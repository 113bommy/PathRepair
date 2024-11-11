#include <iostream>
#include <cmath>
using namespace std;
int main(){
int n,t;cin>>n>>t;
int a=100453;
for(int i=0;i<n;i++){
int c,s;
  cin>>c>>s;
  if(s>t){continue;}
  a=min(a,c);
}
  if(a==100453){cout<<"TLE"<<endl;return 0;}
  cout<<a<<endl;
}
