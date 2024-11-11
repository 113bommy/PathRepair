#include <bits/stdc++.h>
using namespace std;
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      res = max(res,
                dp[i + 1][j + 1] = max({0, dp[i + 1][j] - 1, dp[i][j + 1] - 1,
                                        dp[i][j] - 2 + 4 * (a[i] == b[j])}));
  cout << res << "\n";
}
