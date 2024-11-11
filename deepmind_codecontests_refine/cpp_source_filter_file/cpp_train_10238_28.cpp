#include <bits/stdc++.h>
using namespace std;
const int maxN = 2005;
const int dx[10] = {0, 0, 0, 1, -1, 1, 1, -1, -1};
const int dy[10] = {0, 1, -1, 0, 0, -1, 1, -1, 1};
int n, area, sx, sy;
bool p[maxN][maxN], vis[maxN][maxN];
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) scanf("%d", &p[i][j]);
}
void fixNoise() {
  int cnt;
  for (int tme = 1; tme <= 5; ++tme)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) {
        cnt = 0;
        for (int k = 0; k <= 8; ++k) cnt += p[i + dx[k]][j + dy[k]];
        if (cnt < 4)
          p[i][j] = 0;
        else
          p[i][j] = 1;
      }
}
void dfs(int x, int y) {
  int xx, yy;
  vis[x][y] = 1;
  ++area;
  sx += x;
  sy += y;
  for (int i = 1; i <= 4; ++i) {
    xx = x + dx[i];
    yy = y + dy[i];
    if (xx < 1 || yy < 1 || xx > n || yy > n || !p[xx][yy] || vis[xx][yy])
      continue;
    dfs(xx, yy);
  }
}
void work() {
  double ox, oy, r;
  int circle = 0, rectangle = 0;
  fixNoise();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (p[i][j] && !vis[i][j]) {
        area = 0;
        sx = 0;
        sy = 0;
        dfs(i, j);
        if (area >= 108) {
          ox = double(sx) / area;
          oy = double(sy) / area;
          r = ((i - ox) * (i - ox)) + ((j - oy) * (j - oy));
          if (area / r > 2.7)
            ++circle;
          else
            ++rectangle;
        }
      }
  printf("%d %d\n", circle, rectangle);
}
int main() {
  init();
  work();
  return 0;
}
