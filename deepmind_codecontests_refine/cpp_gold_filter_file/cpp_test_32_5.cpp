#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t n;
  cin >> n;
  vector<int64_t> v(n + 1);
  vector<vector<int64_t>> dp(
      n + 2, vector<int64_t>((int64_t)(448), -(int64_t)(1e17 + 1)));
  for (int64_t i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] += v[i - 1];
  }
  dp[n + 1][0] = (int64_t)(1e17 + 1);
  for (int64_t i = n; i > 0; i--) {
    for (int64_t j = 0; j < (int64_t)(448); j++) {
      if (j + i - 1 > n) continue;
      if (j && dp[j + i][j - 1] > v[j + i - 1] - v[i - 1])
        dp[i][j] = max(dp[i][j], v[j + i - 1] - v[i - 1]);
      dp[i][j] = max(dp[i][j], dp[i + 1][j]);
    }
  }
  for (int64_t i = (int64_t)(448) - 1; i; i--)
    if (dp[1][i] > 0) {
      cout << i << "\n";
      break;
    }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
