#include <bits/stdc++.h>
inline int getint() {
  register char ch;
  while (!isdigit(ch = getchar()))
    ;
  register int x = ch ^ '0';
  while (isdigit(ch = getchar())) x = (((x << 2) + x) << 1) + (ch ^ '0');
  return x;
}
const int N = 3001, M = 301;
double p[N][M], f[M][N], g[N], cnt[M], del[M];
int main() {
  const int n = getint(), m = getint();
  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; j <= m; j++) {
      p[i][j] = getint() / 1000.;
    }
  }
  for (register int i = 1; i <= m; i++) {
    f[i][0] = 1;
    for (register int j = 1; j <= n; j++) {
      f[i][j] = f[i][j - 1] * (1 - p[j][i]);
    }
    del[i] = 1 - f[i][n];
  }
  double ans = 0;
  for (register int i = 0; i < n; i++) {
    const int k = std::max_element(&del[1], &del[m] + 1) - del;
    cnt[k]++;
    ans += del[k];
    std::copy(&f[k][0], &f[k][n] + 1, g);
    f[k][0] = 0;
    for (register int i = 1; i <= n; i++) {
      f[k][i] = f[k][i - 1] * (1 - p[i][k]) + g[i - 1] * p[i][k];
    }
    del[k] -= f[k][n];
  }
  printf("%.12f\n", ans);
  return 0;
}
