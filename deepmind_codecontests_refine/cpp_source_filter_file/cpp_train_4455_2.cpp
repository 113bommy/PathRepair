#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll N,K,a,b,ans=0;
  cin>>N>>K;
  for(ll i=K;i<=N+1;i++){
  a=(2*N-i+1)*i/2;
  else{b=(i-1)*i/2;}
  ans+=a-b+1;
  }
  cout<<ans%1000000007<<endl;
}