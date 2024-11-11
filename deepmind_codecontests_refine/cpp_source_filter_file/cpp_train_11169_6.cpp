#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j])
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
      else
        dp[i][j] = max(dp[i][j], max(dp[i - 1][j] - 1, dp[i][j - 1] - 1));
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
}
