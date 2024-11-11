#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  vector<vector<long long>> dp(n + 5, vector<long long>(n + 5, -1e12));
  for (long long i = 0; i < n; i++) cin >> v[i];
  dp[0][0] = dp[0][1] = 0;
  if (v[0] == 1) dp[0][0] = 1;
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j < i; j++) {
      if (dp[i - 1][j] >= 0) {
        long long add = 0;
        if (v[i] == i + 1 - j) add = 1;
        dp[i][j] = max(dp[i][j], dp[i - 1][j] + add);
        if (j + 1 <= n) {
          dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j]);
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    if (dp[n - 1][i] >= k) {
      cout << i << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
