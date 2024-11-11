#include <bits/stdc++.h>
using namespace std;
const int N = 1605, M = N * N, dist = 6, ray = 4, u[] = {1, 0, -1, 0},
          v[] = {0, 1, 0, -1};
int n, m, h, t, x, y, T, last, near, cnt, o[N * 10], a[N][N], d[N][N], e[N][N],
    f[M], g[M], X[N * 10], Y[N * 10];
void read(int &x) {
  char ch;
  x = 0;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - 48, ch = getchar())
    ;
}
void bfs(int x, int y) {
  h = 0, t = 1, f[1] = x, g[1] = y, d[x][y] = 1;
  while (h < t) {
    x = f[++h], y = g[h];
    for (int k = 1; k <= 4; k++) {
      int x0 = x + u[k - 1], y0 = y + v[k - 1];
      if (a[x0][y0] && !d[x0][y0])
        d[x0][y0] = d[x][y] + 1, f[++t] = x0, g[t] = y0;
    }
  }
}
int find() {
  int h = 0, t = 1, last;
  X[1] = x, Y[1] = y, e[x][y] = 1;
  while (h < t) {
    x = X[++h], y = Y[h];
    if (e[x][y] != last && t - h > ray) break;
    last = e[x][y];
    for (int k = 1; k <= 4; k++) {
      int x0 = x + u[k - 1], y0 = y + v[k - 1];
      if (a[x0][y0] && !e[x0][y0])
        e[x0][y0] = e[x][y] + 1, X[++t] = x0, Y[t] = y0;
    }
  }
  int E = e[X[t]][Y[t]];
  if (E <= dist)
    for (int i = 1; i <= t; i++) e[X[i]][Y[i]] = 0;
  return E > dist;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) read(a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] && !d[i][j]) {
        bfs(i, j), cnt = 0;
        x = i, y = j, cnt += find();
        for (int i = t; i; i--) {
          x = f[i], y = g[i];
          if (!e[x][y] && find()) cnt++;
        }
        for (int i = 1; i <= t; i++) d[f[i]][g[i]] = -100, e[f[i]][g[i]] = 0;
        o[++*o] = cnt;
      }
  sort(o + 1, o + *o + 1);
  printf("%d\n", *o);
  for (int i = 1; i <= *o; i++) printf("%d%s", o[i], i < *o ? " " : "\n");
  return 0;
}
