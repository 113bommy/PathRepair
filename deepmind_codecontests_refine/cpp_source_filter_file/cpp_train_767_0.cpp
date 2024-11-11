#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
int r, c, n, ans = 0;
int d[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
               {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
int fa[maxn * maxn * 2];
bool note[maxn][maxn];
inline int id(int x, int y) { return (x - 1) * (2 * c) + y; }
bool exist(int &x, int &y) {
  if (!y)
    y = 2 * c;
  else if (y == 2 * c + 1)
    y = 1;
  return (x > 0 && x <= r && note[x][y]);
}
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) {
  int xx = find(x), yy = find(y);
  fa[xx] = yy;
}
bool ok(int x, int y) {
  int xx = x, yy = y + c;
  for (int i = 0; i < 8; i++) {
    int dx = x + d[i][0], dy = y + d[i][1];
    if (!exist(dx, dy)) continue;
    for (int j = 0; j < 8; j++) {
      int dxx = xx + d[j][0], dyy = yy + d[j][1];
      if (!exist(dxx, dyy)) continue;
      if (find(id(dx, dy)) == find(id(dxx, dyy))) return false;
    }
  }
  return true;
}
void del(int x, int y) {
  int xx = x, yy = y + c;
  for (int i = 0; i < 8; i++) {
    int dx = x + d[i][0], dy = y + d[i][1];
    if (exist(dx, dy)) merge(id(x, y), id(dx, dy));
    dx = xx + d[i][0], dy = yy + d[i][1];
    if (exist(dx, dy)) merge(id(xx, yy), id(dx, dy));
  }
  note[xx][yy] = note[x][y] = true;
}
int main() {
  scanf("%d%d%d", &r, &c, &n);
  if (c <= 1) {
    printf("0");
    return 0;
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      fa[id(i, j + c)] = id(i, j + c);
      fa[id(i, j)] = id(i, j);
    }
  }
  int x, y;
  while (n--) {
    scanf("%d%d", &x, &y);
    if (ok(x, y)) {
      ans++;
      del(x, y);
    }
  }
  printf("%d", ans);
  return 0;
}
