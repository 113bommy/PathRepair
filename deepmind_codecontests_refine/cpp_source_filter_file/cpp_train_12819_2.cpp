#include <bits/stdc++.h>
using namespace std;
char G[55][55];
int vis[55][55];
int lx[55 * 55], rx[55 * 55], ly[55 * 55], ry[55 * 55], n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void dfs(int x, int y, int f) {
  vis[x][y] = f;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
    if (G[nx][ny] == '1' || vis[nx][ny] > 0) continue;
    dfs(nx, ny, f);
  }
  return;
}
int main() {
  int sx, sy, tx, ty;
  scanf("%d%d%d%d%d", &n, &sx, &sy, &tx, &ty);
  for (int i = 1; i <= n; i++) scanf("%s", G[i] + 1);
  dfs(sx, sy, 1);
  dfs(tx, ty, 2);
  int cntl = 0;
  int cntr = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (vis[i][j] == 1) {
        lx[cntl] = i;
        ly[cntl++] = j;
      } else if (vis[i][j] == 2) {
        rx[cntr] = i;
        ry[cntr++] = j;
      }
    }
  if (vis[sx][sy] == vis[tx][ty]) {
    cout << "0" << endl;
    return 0;
  }
  int res = 0x7fffffff;
  for (int i = 0; i < cntl; i++) {
    for (int j = 0; j < cntr; j++) {
      int cur =
          (lx[i] - rx[j]) * (lx[i] - rx[j]) + (ly[i] - ry[j]) * (ly[i] - ry[j]);
      res = min(res, cur);
    }
  }
  cout << res << endl;
}
