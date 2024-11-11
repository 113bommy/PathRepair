#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,x,n) for(int i=(x);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define int long long
using namespace std;
const int MOD=1e9+7;
const int INF=1e10;

signed main(){
  int N,W;
  cin>>N>>W;
  vector<int> v(N+10),w(N+10);
  rep(i,N)cin>>v[i]>>w[i];

  vector<vector<int>> dp(N+10,vector<int>(10004,INF));

  dp[0][0]=0;

  rep(i,N+1){
    rep(j,10004){
      if(j-v[i]>=0)
        dp[i+1][j]=min(dp[i+1][j],dp[i][j-v[i]]+w[i]);
      dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
    }
  }
  for(int j=10003;i>=0;i--){
    if(dp[N][j]<=W){
      cout<<j<<endl;
      return 0;
    }
  }

  return 0;
}

