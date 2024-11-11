#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int offset = 100 * 100 * 10;
  long long int mxbal = offset + offset;
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a(n + 1), b(n + 1);
  for (long long int i = 0; i < n; ++i) cin >> a[i];
  for (long long int i = 0; i < n; ++i) cin >> b[i];
  vector<vector<long long int>> dp(n + 1, vector<long long int>(mxbal, -1));
  dp[0][offset] = 0;
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < mxbal; ++j) {
      if (dp[i][j] != -1) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        dp[i + 1][j - a[i] + b[i] * k] =
            max(dp[i + 1][j - a[i] + b[i] * k], dp[i][j] + a[i]);
      }
    }
  }
  if (dp[n][offset] == 0) dp[n][offset] = -1;
  cout << dp[n][offset] << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int T = 1;
  for (long long int i = 1; i <= T; ++i) {
    solve();
  }
  return 0;
}
