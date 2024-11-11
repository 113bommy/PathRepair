#include <bits/stdc++.h>
using namespace std;

int main(){
  int a=0,b=0,c=0,d=0;
  for(int i=0; i<6; i++){
    int x;
    xin>>x;
    if(x==1)a++;
    if(x==2)b++;
    if(x==3)c++;
    if(x==4)d++;
  }
  if(a<3 && b<3 && c<<3 && d<3)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}