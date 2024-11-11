#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010][2];
int a[1010];
int main() {
  for (int i = 0; i < 1010; ++i)
    for (int j = 0; j < 1010; ++j) {
      dp[i][j][0] = (1 << 30);
      dp[i][j][1] = (1 << 30);
    }
  dp[0][0][0] = dp[0][0][1] = 0;
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  string str[1010];
  for (int i = 0; i < n; ++i) cin >> str[i];
  memset(a, 0, sizeof(a));
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      if (str[i][j] == '#') a[j]++;
  for (int i = 0; i <= m; ++i)
    for (int j = 0; j <= m; ++j) {
      if (i + 1 <= m) {
        if (j + 1 <= y) {
          {
            if (dp[i + 1][j + 1][0] > (dp[i][j][0] + a[i]))
              dp[i + 1][j + 1][0] = (dp[i][j][0] + a[i]);
          };
          {
            if (dp[i + 1][j + 1][1] > (dp[i][j][1] + (n - a[i])))
              dp[i + 1][j + 1][1] = (dp[i][j][1] + (n - a[i]));
          };
        }
        if (j + 1 > x) {
          {
            if (dp[i + 1][1][0] > (dp[i][j][1] + a[i]))
              dp[i + 1][1][0] = (dp[i][j][1] + a[i]);
          };
          {
            if (dp[i + 1][1][1] > (dp[i][j][0] + (n - a[i])))
              dp[i + 1][1][1] = (dp[i][j][0] + (n - a[i]));
          };
        }
      }
    }
  int ans = (1 << 30);
  for (int len = x; len <= y; ++len) {
    {
      if (ans > (dp[m][len][0])) ans = (dp[m][len][0]);
    };
    {
      if (ans > (dp[m][len][1])) ans = (dp[m][len][1]);
    };
  }
  cout << ans << endl;
  return 0;
}
