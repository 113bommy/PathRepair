#include <bits/stdc++.h>
int dis[70][70][70], ans[70][70][70];
int main() {
  int n, m, r, i, j, k, t, tt;
  scanf("%d%d%d", &n, &m, &r);
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
      for (k = 1; k <= n; k++) scanf("%d", &dis[i][j][k]);
  for (t = 1; t <= m; t++) {
    for (k = 1; k <= n; k++)
      for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
          if (dis[t][i][j] > dis[t][i][k] + dis[t][k][j])
            dis[t][i][j] = dis[t][i][k] + dis[t][k][j];
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      t = 2100000000;
      for (k = 1; k <= m; k++)
        if (dis[k][i][j] < t) t = dis[k][i][j];
      ans[1][i][j] = t;
    };
  for (k = 2; k <= n + 1; k++)
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) {
        if (i - j)
          ans[k][i][j] = t = 2100000000;
        else
          ans[k][i][j] = 0;
        for (tt = 1; tt <= n; tt++)
          if (t > ans[1][i][tt] + ans[k - 1][tt][j])
            t = ans[1][i][tt] + ans[k - 1][tt][j];
        ans[k][i][j] = t;
      };
  while (r--) {
    scanf("%d%d%d", &i, &j, &k);
    if (k > n) k = n + 1;
    printf("%d\n", ans[k + 1][i][j]);
  }
}
