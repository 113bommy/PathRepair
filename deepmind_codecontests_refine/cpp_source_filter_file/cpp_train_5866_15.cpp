#include <bits/stdc++.h>
using namespace std;
const int S = 3007, N = 307;
char buf[1000000], *p1, *p2;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int rd() {
  register int f = 0;
  register char c = gc();
  while (c < 48 || c > 57) c = gc();
  while (c > 47 && c < 58) f = f * 10 + (c ^ 48), c = gc();
  return f;
}
double p[S][N], f[N][S], d[N], g[S];
int main() {
  register int n = rd(), m = rd(), i, j, x;
  double o = 0;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) x = rd(), p[i][j] = (double)x / 1000.;
  for (i = 1; i <= m; ++i) {
    f[i][0] = 1;
    for (j = 1; j <= n; ++j) f[i][j] = f[i][j - 1] * (1. - p[j][i]);
    d[i] = 1. - f[i][n];
  }
  for (i = 1; i <= n; ++i) {
    x = 0;
    for (j = 1; j <= m; ++j)
      if (d[j] > d[x]) x = j;
    o += d[x];
    for (j = 0; j <= n; ++j) g[j] = f[x][j];
    f[x][0] = 0;
    for (j = 1; j <= n; ++j)
      f[x][i] = f[x][i - 1] * (1 - p[i][x]) + g[i - 1] * p[i][x];
    d[x] -= f[x][n];
  }
  printf("%.10lf", o);
  return 0;
}
