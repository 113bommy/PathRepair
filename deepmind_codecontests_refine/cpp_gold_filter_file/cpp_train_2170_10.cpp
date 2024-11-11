#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,ev=0,ans1=1; cin>>n;
  for(int i=0;i<n;i++){
    int a; cin>>a;
    if(a%2==0)ev++;
    ans1*=3;
  }
  
  int ans2=1;
  for(int i=0;i<ev;i++)ans2*=2;
  
  cout<<ans1-ans2<<endl;
  return 0;
}