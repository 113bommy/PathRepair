#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,d,x,;
  cin>>r>>d>>x;
  for(int i=0;i<10;i++){
    cout<<r*x-d<<endl;
    x=r*x-d;
  }
}