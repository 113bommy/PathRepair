#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  vector<int> a(n + 1), b(m + 1);
  vector<vector<int>> bp(1e5 + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    bp[b[i]].push_back(i);
  }
  int k = s / e;
  int N = min(s, n);
  vector<vector<int>> dp(N + 1, vector<int>(k + 1, MOD));
  for (int i = 0; i <= N; i++) {
    dp[i][0] = 0;
  }
  int ans = 0;
  for (int u = 1; u <= k; u++) {
    for (int i = 1; i <= N; i++) {
      int x = a[i];
      dp[i][u] = dp[i - 1][u];
      int pos = dp[i - 1][u - 1];
      auto it = upper_bound(bp[x].begin(), bp[x].end(), pos);
      if (it != bp[x].end()) {
        dp[i][u] = min(dp[i][u], *it);
      }
      if (dp[i][u] + i + u * e <= s) ans = max(ans, u);
    }
  }
  cout << ans;
  return 0;
}
