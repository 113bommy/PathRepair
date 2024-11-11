#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, q, x, y, d, t, z;
long long dp[2][N][N], a[N][N];
vector<pair<int, int> > v1[N][N], v2[N][N];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  while (q--) {
    scanf("%d%d%d%d%d", &x, &y, &d, &t, &z);
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    if (t <= x + y && (x + y - t) % 4 == 0) a[x][y] += z, flag1 = 1;
    if (t + 1 <= x + y && (x + y - t) % 4 == 1) a[x + d][y - d] += z, flag2 = 1;
    if (t + 2 <= x + y + d && (x + y + d - t) % 4 == 2)
      a[x + d][y] += z, flag3 = 1;
    if (t + 3 <= x + y + d && (x + y + d - t) % 4 == 3)
      a[x][y + d] += z, flag4 = 1;
    if (flag1 && flag3) v2[x + d][y].push_back(make_pair(d, z));
    if (flag1 && flag4) v1[x][y + d].push_back(make_pair(d, z));
    if (flag2 && flag3) v1[x + d][y].push_back(make_pair(d, z));
  }
  memset(dp, 0x3f3f3f3f, sizeof dp);
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    int t = i & 1;
    for (int j = 0; j < m; j++)
      for (int k = 0; k <= 1000; k++) {
        dp[t][j][k] += a[i][j];
        for (int p = 0; p < (int)v1[i][j].size(); p++)
          if (v1[i][j][p].first <= k && k <= 500)
            dp[t][j][k] -= v1[i][j][p].second;
        for (int p = 0; p < (int)v2[i][j].size(); p++)
          if (v2[i][j][p].first <= k - 500) dp[t][j][k] -= v2[i][j][p].second;
        if (k <= 500)
          dp[t ^ 1][j][501] = min(dp[t ^ 1][j][501], dp[t][j][k]);
        else
          dp[t ^ 1][j][k + 1] = min(dp[t ^ 1][j][k + 1], dp[t][j][k]);
        if (k > 500)
          dp[t][j + 1][1] = min(dp[t][j + 1][1], dp[t][j][k]);
        else
          dp[t][j + 1][k + 1] = min(dp[t][j + 1][k + 1], dp[t][j][k]);
      }
    if (i != n - 1) memset(dp[t], 0x3f, sizeof dp[t]);
  }
  long long ans = 1e18;
  for (int i = 0; i <= 1000; i++) ans = min(ans, dp[(n - 1) & 1][m - 1][i]);
  printf("%lld\n", ans);
}
