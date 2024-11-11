#include <bits/stdc++.h>
using namespace std;
int n, k;
int t[4005], d[4005];
int f[2][4005], g[2][4005];
void Gao() {
  int i, j, tf, tp, tg, cnt, ans, oo;
  memset(f, 0xff, sizeof f);
  memset(g, 0x3f, sizeof g);
  oo = g[0][0];
  f[0][0] = 0;
  g[0][0] = 1;
  for (i = 1; i <= n; ++i) {
    for (j = 0; j <= k; ++j) {
      f[1][j] = f[0][j];
      g[1][j] = g[0][j];
      f[0][j] = -1;
      g[0][j] = oo;
    }
    for (j = 0; j <= k; ++j) {
      tg = -1;
      if (f[1][j] != -1) {
        f[0][j] = f[1][j];
        cnt = t[i] - g[1][j];
        if (cnt < 0) cnt = 0;
        if (f[0][j] < cnt) f[0][j] = cnt;
        if (t[i] > g[1][j])
          tg = t[i] + d[i];
        else
          tg = g[1][j] + d[i];
      }
      if (tg != -1) {
        g[0][j] = tg;
      }
      if (j == 0) continue;
      if (f[1][j - 1] != -1) {
        tf = f[1][j - 1];
        if (f[0][j] < tf) {
          f[0][j] = tf;
        }
        if (tg == -1)
          g[0][j] = g[1][j - 1];
        else if (g[0][j] > g[1][j - 1])
          g[0][j] = g[1][j - 1];
      }
    }
  }
  ans = 0;
  for (i = 0; i <= k; ++i) {
    if (ans < f[0][i]) ans = f[0][i];
    if (g[0][i] < 86401) {
      cnt = 86401 - g[0][i];
      if (ans < cnt) ans = cnt;
    }
  }
  printf("%d\n", ans);
}
int main() {
  int i;
  scanf("%d %d", &n, &k);
  for (i = 1; i <= n; ++i) scanf("%d %d", &t[i], &d[i]);
  Gao();
  return 0;
}
