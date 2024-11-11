#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

// dp[i][j]: 左にi個、右にj個詰めた時の最大値
ll dp[2020][2020];

int main() {
  int N;
  cin >> N;
  vector< pair<ll, ll> > A(N);
  REP(i,N) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A.begin(), A.end(), greater<pair<ll,ll> >());
  REP(i,N) {
    for( ll j=0; i+j<N; j++ ) {
      // left
      dp[i+1][j] = max(dp[i+1][j], dp[i][j] + A[i+j].first * (A[i+j].second - i));
      // right
      dp[i][j+1] = max(dp[i][j+1], dp[i][j] + A[i+j].first * (N-1-j - A[i+j].second));
    }
  }
  int ans = 0;
  REP(i,N+1) {
    ans = max( ans, dp[i][N-i] );
  }
  cout << ans << endl;
}

