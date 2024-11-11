#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,ans;
  cin>>n;
  ans=n;
  for(int i=0;i<=n;i++){
    int k=0;
    int t=i;
    while(t){k+=t%6;t/=6;}
    t=n-i;
    while(t){k+=t%9;t/=9;}
    ans=min(ans,k);
  }
  cout<<ans;
}