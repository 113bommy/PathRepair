#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll N,i,ans;string S;cin>>N>>S;
  ll w[N+1];w[0]=0;ans=N;
  REP(i,N){
    w[i+1]=w[i];if(S[i]=='.')w[i+1]++;
  }
  REP(i,N+1)ans=min(ans,i-2*w[i]+w[N]);
  cout<<ans<<endl;
  return 0;
}
