#include <bits/stdc++.h>
int n, m;
std::bitset<105> dp[505][2][505], f, g;
long long ans = 0;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y, opt;
    scanf("%d%d%d", &x, &y, &opt);
    dp[0][opt][x][y] = 1;
  }
  for (int k = 1; k <= 60; k++)
    for (int x = 0; x <= 1; x++)
      for (int i = 1; i <= n; i++)
        for (int p = 1; p <= n; p++)
          if (dp[k - 1][x][i][p])
            dp[k][x][i] = dp[k][x][i] | dp[k - 1][x ^ 1][p];
  for (int i = 1; i <= n; i++)
    if (dp[60][0][1][i]) return puts("-1"), 0;
  int opt = 0;
  f.reset();
  f[1] = 1;
  for (int k = 59; k >= 0; k--) {
    int flag = 0;
    g.reset();
    for (int i = 1; i <= n; i++) {
      if (!f[i]) continue;
      for (int j = 1; j <= n; j++)
        if (dp[k][opt][i][j]) g[j] = 1, flag = 1;
    }
    if (!flag) continue;
    opt = opt ^ 1;
    for (int i = 1; i <= n; i++) f[i] = g[i];
    ans = ans + (1ll << k);
    if (ans > 1000000000000000000) return puts("-1"), 0;
  }
  printf("%lld\n", ans);
  return 0;
}
