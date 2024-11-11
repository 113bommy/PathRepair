#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef complex<double> P;
static const double EPS = 1e-8;
static const int INF = (int)1e8;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
unsigned int dp[101][101];
int main(void){
  int n;  cin>>n;
  vector<PII> v(n);
  REP(i,n)cin>>v[i].first>>v[i].second;

  REP(i,n+1)REP(j,n+1)dp[i][j] = (i==j)?0:INF;

  FOR(i,1,n){
    REP(j,n-i+1){
      FOR(k,j,j+i){
        int cost = v[j].first * v[k].second * v[k+1].first * v[j+i].second;
        dp[j][j+i] = min(dp[j][j+1],cost+dp[j][k]+dp[k+1][j+i]);
      }
    }
  }
  cout<<dp[0][n-1]

  return 0;
}