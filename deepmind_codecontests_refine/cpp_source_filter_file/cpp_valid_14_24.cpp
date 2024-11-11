#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const int mxN = 2000;
int t, n, k;
int a[mxN];
int dp[mxN + 1][mxN + 1];
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
      if (a[i - 1] == j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
    }
  }
  for (int i = n; i >= 0; --i) {
    if (dp[n][i] >= k) {
      cout << n - i << '\n';
      return;
    }
  }
  cout << -1 << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> t;
  for (int x = 0; x < t; ++x) {
    solve();
  }
}
