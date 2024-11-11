#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int mod = 1e9 + 7;
int dp[N][N], d[N][N];
int n, c[N], m;
int main() {
  srand(time(0));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &d[i][j]);
  int T = 512 * 20, ans = 1e9;
  while (T--) {
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) c[i] = rand() & 1;
    dp[1][0] = 0;
    for (int t = 1; t <= m; t++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          if (c[i] != c[j]) dp[i][j] = min(dp[i][t], dp[j][t - 1] + d[j][i]);
    ans = min(ans, dp[1][m]);
  }
  printf("%d\n", ans);
}
