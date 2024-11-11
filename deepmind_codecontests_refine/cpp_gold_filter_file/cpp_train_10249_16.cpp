#include <bits/stdc++.h>
int n, s, ans, c[110], v[110][110], t[110][110];
int main() {
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    for (int j = 0; j < c[i]; j++)
      scanf("%d%d", &v[i][j + 1], &t[i][j + 1]), t[i][j + 1] += t[i][j];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) {
      int x = 1, y = 1, sx = 0, sy = 0, nx, ny, ct = 0, dt;
      while (x <= c[i] || y <= c[j]) {
        nx = v[i][x], ny = v[j][y];
        if (y > c[j] || x <= c[i] && t[i][x] <= t[j][y])
          dt = t[i][x] - ct, y += (t[i][x++] == t[j][y]);
        else
          dt = t[j][y] - ct, y++;
        nx *= dt, ny *= dt;
        ans += (1ll * (sx - sy) * (sx + nx - sy - ny) < 0);
        sx += nx, sy += ny;
        ct += dt;
        if (sx == sy) ans += (1ll * (nx - ny) * (v[i][x] - v[j][y]) > 0);
      }
    }
  printf("%d\n", ans);
}
