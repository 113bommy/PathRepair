#include <bits/stdc++.h>
using namespace std;
const int tx[4] = {0, 1, 0, -1};
const int ty[4] = {1, 0, -1, 0};
const double pi = acos(-1);
const int N = 2000, m = 2;
int a[N + 3][N + 3], b[N + 3][N + 3], n, S, lx, rx, ly, ry, ansx, ansy;
double g[10][10];
void dfs(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > n) return;
  if (!a[x][y]) return;
  S++;
  a[x][y] = 0;
  if (x < lx || (x == lx && y < ly)) lx = x, ly = y;
  if (x > rx || (x == rx && y > ry)) rx = x, ry = y;
  for (int i = 0; i < 4; i++) dfs(x + tx[i], y + ty[i]);
}
double dist(int x1, int y1, int x2, int y2) {
  return 1. * (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
void Work() {
  for (int i = -m; i <= m; i++)
    for (int j = -m; j <= m; j++)
      g[m + i][m + j] = 1. / (m * 2 + 1) / (m * 2 + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      double x = 0;
      for (int k = -m; k <= m; k++)
        for (int l = -m; l <= m; l++) {
          if (i + k < 1 || i + k > n || j + l < 1 || j + l > n) continue;
          if (a[i + k][j + l]) x += g[m + k][m + l];
        }
      if (x > 0.6) b[i][j] = 1;
    }
  memcpy(a, b, sizeof(a));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  Work();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j]) {
        lx = ly = n, rx = ry = 0;
        S = 0;
        dfs(i, j);
        if (S < 100) continue;
        double dd = dist(lx, ly, rx, ry);
        if (abs(dd * pi / 4 - S) / abs(dd / 2.0 - S) < 0.8)
          ansx++;
        else
          ansy++;
      }
  printf("%d %d", ansx, ansy);
}
