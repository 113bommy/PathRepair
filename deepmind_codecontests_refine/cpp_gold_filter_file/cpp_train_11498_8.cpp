#include <bits/stdc++.h>
int n, i, j, k, m, g[510][510], f[510][510], c[510][510], s[510];
int main() {
  memset(g, 0x3f, sizeof(g));
  scanf("%d%d", &n, &m);
  while (m--) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    g[x][y] = g[y][x] = z;
  }
  memcpy(f, g, sizeof(f));
  for (k = 1; k <= n; ++k)
    for (i = 1; i <= n; ++i)
      for (j = 1; j <= n; ++j)
        if (f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k] + f[k][j];
  for (i = 1; i <= n; ++i) f[i][i] = 0;
  for (i = 1; i <= n; ++i) {
    memset(s, 0, sizeof(s));
    for (j = 1; j <= n; ++j) {
      if (f[j][i] == 0x3f3f3f3f) continue;
      for (k = 1; k <= n; ++k)
        if (g[j][k] + f[k][i] == f[j][i]) ++s[j];
    }
    for (j = 1; j <= n; ++j) {
      if (f[j][i] == 0x3f3f3f3f) continue;
      for (k = 1; k <= n; ++k)
        if (f[j][k] + f[k][i] == f[j][i]) c[j][i] += s[k];
    }
  }
  for (i = 1; i <= n; ++i)
    for (j = i + 1; j <= n; ++j) printf("%d ", c[i][j]);
  return 0;
}
