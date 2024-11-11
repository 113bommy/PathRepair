#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long n, k, a[85][85], col[85], ans = 1e18, dp[15][85];
long long check() {
  for (long long i = 2; i <= n; i++) col[i] = rng() % 2;
  for (long long i = 1; i <= n; i++) {
    dp[0][i] = 1e15;
  }
  dp[0][1] = 0;
  for (long long i = 1; i <= k; i++) {
    for (long long j = 1; j <= n; j++) {
      dp[i][j] = 1e15;
      for (long long t = 1; t <= n; t++) {
        if (t != j && col[t] != col[j]) {
          dp[i][j] = min(dp[i][j], dp[i - 1][t] + a[t][j]);
        }
      }
    }
  }
  return dp[k][1];
}
int32_t main() {
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  col[1] = 0;
  for (long long i = 1; i <= 1500; i++) {
    ans = min(check(), ans);
  }
  cout << ans << '\n';
}
