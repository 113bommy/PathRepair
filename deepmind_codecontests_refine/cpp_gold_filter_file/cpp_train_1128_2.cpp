#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(i=0;i<n;i++)

int main(){
  ll i,N,x,ans=0,t=0;
  cin>>N;
  vector<ll> color(13,0);
  while(N--){
    cin>>x;
    color[x/400]++;
  }
  rep(i,13){
    if(i<8&&color[i]>0)ans++;
    if(i>=8)t+=color[i];
  }
  if(ans==0){t--;ans++;}
  cout<<ans<<" "<<ans+t<<endl;
  return 0;
}
