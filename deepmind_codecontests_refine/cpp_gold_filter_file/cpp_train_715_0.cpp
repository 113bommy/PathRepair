#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

const int IINF = INT_MAX;
int N,M,D[1002],C[1002],dp[1002][1002];

int main(){
  cin >> N >> M;
  rep(i,N) cin >> D[i];
  rep(i,M) cin >> C[i];
  rep(i,M+1) rep(j,N+1) dp[i][j] = IINF;
  dp[0][0] = 0;
  rep(day,M){
    rep(city,N){
      if( dp[day][city] == IINF ) continue;
      dp[day+1][city] = min(dp[day+1][city],dp[day][city]);
      dp[day+1][city+1] = min(dp[day+1][city+1],dp[day][city]+D[city]*C[day]);
    }
  }
  int mini = IINF;
  rep(i,M+1) mini = min(mini,dp[i][N]);
  cout << mini << endl;
  return 0;
}