#include <bits/stdc++.h>
using namespace std;
bool img[2][2005][2005], vis[2005][2005], vis2[2005][2005];
int dir[8][2] = {{0, 1}, {0, -1},  {-1, 0}, {1, 0},
                 {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
int n, sz, cir, squ;
double xs, ys, mxdis, mndis;
double dis(int x1, int y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void Do(int x) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int cnt = 0;
      for (int k = 0; k < 8; k++)
        if (img[x ^ 1][i + dir[k][0]][j + dir[k][1]]) cnt++;
      img[x][i][j] = cnt >= 4;
    }
  }
}
void dfs(int x, int y) {
  vis[x][y] = 1;
  sz++;
  xs += x;
  ys += y;
  for (int i = 0; i < 4; i++)
    if (!vis[x + dir[i][0]][y + dir[i][1]] &&
        img[1][x + dir[i][0]][y + dir[i][1]])
      dfs(x + dir[i][0], y + dir[i][1]);
}
void dfs2(int x, int y) {
  vis2[x][y] = 1;
  mxdis = max(mxdis, dis(x, y, xs, ys));
  int sum = 0;
  for (int i = 0; i < 8; i++)
    if (img[1][x + dir[i][0]][y + dir[i][1]] == 0) sum++;
  if (sum >= 4) mndis = min(mndis, dis(x, y, xs, ys));
  for (int i = 0; i < 4; i++)
    if (!vis2[x + dir[i][0]][y + dir[i][1]] &&
        img[1][x + dir[i][0]][y + dir[i][1]])
      dfs2(x + dir[i][0], y + dir[i][1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int a;
      scanf("%d", &a);
      img[0][i][j] = a;
    }
  for (int i = 1; i <= 5; i++) Do(i & 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (img[1][i][j] && !vis[i][j]) {
        xs = ys = sz = 0;
        dfs(i, j);
        xs /= sz;
        ys /= sz;
        mxdis = 0;
        mndis = 9999999;
        if (sz > 70) {
          dfs2(i, j);
          if (mxdis / mndis > 1.2)
            squ++;
          else
            cir++;
        }
      }
  printf("%d %d\n", cir, squ);
}
