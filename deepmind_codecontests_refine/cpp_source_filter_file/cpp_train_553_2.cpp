#include <bits/stdc++.h>
int y[65][65], d[65][65], a[65][65][65];
int main() {
  int n, m, r, u, v, k;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &r);
  for (int t = 0; t < m; t++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) scanf("%d", &y[i][j]);
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          y[i][j] = (y[i][j] < y[i][k] + y[k][j] ? y[i][j] : y[i][k] + y[k][j]);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (t == 0 || d[i][j] > y[i][j]) d[i][j] = y[i][j];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n + 1; k++) a[i][j][k] = d[i][j];
  for (int k = 0; k < n; k++)
    if (k)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          for (int u = 0; u < n; u++)
            a[i][j][k] = (a[i][j][k] < a[i][u][k - 1] + d[u][j]
                              ? a[i][j][k]
                              : a[i][u][k - 1] + d[u][j]);
  for (int i = 0; i < r; i++) {
    scanf("%d", &u);
    scanf("%d", &v);
    scanf("%d", &k);
    printf("%d\n", a[u - 1][v - 1][(k < n ? k : n)]);
  }
  return 0;
}
