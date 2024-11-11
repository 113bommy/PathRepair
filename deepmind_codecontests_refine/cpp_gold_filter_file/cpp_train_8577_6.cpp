#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N = 100005, M = 3005;
int n, m = 3000, xl[N], xr[N], yl[N], yr[N], a[M][M], r[M][M], c[M][M];
vector<int> v;
inline int geta(int x1, int x2, int y1, int y2) {
  return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}
inline int getr(int r1, int c1, int c2) { return r[r1][c2] - r[r1][c1 - 1]; }
inline int getc(int c1, int r1, int r2) { return c[r2][c1] - c[r1 - 1][c1]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &xl[i], &yl[i], &xr[i], &yr[i]);
    xl[i]++, yl[i]++;
    for (int x = xl[i]; x <= xr[i]; x++)
      for (int y = yl[i]; y <= yr[i]; y++) a[x][y] = 1;
    for (int x = xl[i] + 1; x <= xr[i]; x++)
      for (int y = yl[i]; y <= yr[i]; y++) r[x][y] = 1;
    for (int x = xl[i]; x <= xr[i]; x++)
      for (int y = yl[i] + 1; y <= yr[i]; y++) c[x][y] = 1;
  }
  for (int x = 1; x <= m; x++)
    for (int y = 1; y <= m; y++)
      a[x][y] += a[x - 1][y] + a[x][y - 1] - a[x - 1][y - 1];
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) r[i][j] += r[i][j - 1], c[i][j] += c[i - 1][j];
  for (int i = 1; i <= n; i++) {
    int lx = xl[i], ly = yl[i];
    for (int s = 1; s <= m; s++) {
      int rx = lx + s - 1, ry = ly + s - 1;
      if (rx > m || ry > m) break;
      if (geta(lx, rx, ly, ry) != s * s) break;
      if (getr(lx, ly, ry) || getc(ly, lx, rx)) break;
      if (getr(rx + 1, ly, ry) || getc(ry + 1, lx, rx)) continue;
      for (int j = 1; j <= n; j++)
        if (lx <= xl[j] && xl[j] <= rx && ly <= yl[j] && yl[j] <= ry)
          v.push_back(j);
      printf("YES %d\n", v.size());
      for (auto k : v) printf("%d ", k);
      return 0;
    }
  }
  puts("NO");
  return 0;
}
