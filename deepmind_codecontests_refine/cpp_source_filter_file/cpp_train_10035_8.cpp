#include <bits/stdc++.h>
using namespace std;
bool used[1600][1600];
int mark[1600][1600];
int c[1600][1600];
int ans[10000];
int cnt;
int n, m;
int q[2560000][2];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int size;
bool isray(int x, int y) {
  if (x <= 4 || x >= n - 4 || y <= 4 || y >= m - 4) return false;
  bool l = false, r = false, u = false, d = false;
  if (c[x - 1][y] == 0 || c[x - 2][y] == 0 || c[x - 3][y] == 0 ||
      c[x - 4][y] == 0)
    l = true;
  if (c[x + 1][y] == 0 || c[x + 2][y] == 0 || c[x + 3][y] == 0 ||
      c[x + 4][y] == 0)
    r = true;
  if (c[x][y - 1] == 0 || c[x][y - 2] == 0 || c[x][y - 3] == 0 ||
      c[x][y - 4] == 0)
    u = true;
  if (c[x][y + 1] == 0 || c[x][y + 2] == 0 || c[x][y + 3] == 0 ||
      c[x][y + 4] == 0)
    d = true;
  return (l && r) || (u && d);
}
void bfs(int x, int y, int num) {
  int l = 0, r = 0;
  q[0][0] = x, q[0][1] = y;
  used[x][y] = true;
  while (l <= r) {
    x = q[l][0], y = q[l][1];
    if (isray(x, y)) mark[x][y] = num;
    for (int i = 0; i < 4; ++i) {
      int xx = x + dir[i][0], yy = y + dir[i][1];
      if (xx >= 0 && xx < n && yy >= 0 && yy < m)
        if (c[xx][yy] == 1 && !used[xx][yy]) {
          ++r;
          q[r][0] = xx;
          q[r][1] = yy;
          used[xx][yy] = true;
        }
    }
    ++l;
  }
}
void bfs1(int x, int y, int col) {
  int l = 0, r = 0;
  q[0][0] = x, q[0][1] = y;
  mark[x][y] = 0;
  while (l <= r) {
    x = q[l][0], y = q[l][1];
    for (int i = 0; i < 4; ++i) {
      int xx = x + dir[i][0], yy = y + dir[i][1];
      if (xx >= 0 && xx < n && yy >= 0 && yy < m)
        if (mark[xx][yy] == col) {
          ++r;
          q[r][0] = xx;
          q[r][1] = yy;
          mark[xx][yy] = 0;
        }
    }
    ++l;
  }
  size = r;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &c[i][j]);
  memset(used, false, sizeof(used));
  memset(mark, 0, sizeof(mark));
  cnt = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!used[i][j] && c[i][j] == 1) {
        ++cnt;
        bfs(i, j, cnt);
      }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (mark[i][j] > 0) {
        int p = mark[i][j];
        bfs1(i, j, mark[i][j]);
        if (size > 15) ans[p]++;
      }
  printf("%d\n", cnt);
  sort(ans + 1, ans + cnt + 1);
  for (int i = 1; i <= cnt; ++i) {
    if (i != 1) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
}
