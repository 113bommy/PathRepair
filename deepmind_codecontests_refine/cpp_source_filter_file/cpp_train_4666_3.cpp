#include<bits/stdc++.h>
using namespace std;
int main(){
  int x=0,y=0,z=0,w=0;
  for(int i=0;i<6;i++){
    int n;cin>>n;
    if(n==1)x++;
    else if(n==2)y++;
    else if(n==3)z++;
    else w++;
  }
  if(x*y*z*w==4)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  ]
  