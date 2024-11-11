#include <bits/stdc++.h>
int n, m, sx, sy, ml, mr;
char tmps[2222];
char map[2222][2222];
int nl[2222][2222], nr[2222][2222];
bool vis[2222][2222];
int q[4000010][2];
int head, tail;
int main() {
  scanf("%d %d %d %d %d %d", &n, &m, &sx, &sy, &ml, &mr);
  for (int i = 1; i <= n; i++) {
    scanf("%s", tmps + 1);
    for (int j = 1; j <= m; j++) map[i][j] = tmps[j];
  }
  for (int i = 0; i <= n; i++) map[i][0] = map[i][m + 1] = '*';
  for (int j = 0; j <= m; j++) map[0][j] = map[n + 1][j] = '*';
  vis[sx][sy] = 1;
  int ans = 1;
  nl[sx][sy] = ml, nr[sx][sy] = mr;
  q[++tail][0] = sx, q[tail][1] = sy;
  while (head < tail) {
    int nx = q[++head][0], ny = q[head][1];
    if (!vis[nx - 1][ny] && map[nx - 1][ny] == '.') {
      q[head--][0] = nx - 1, q[head][1] = ny;
      nl[nx - 1][ny] = nl[nx][ny], nr[nx - 1][ny] = nr[nx][ny];
      vis[nx - 1][ny] = 1, ans++;
    }
    if (!vis[nx + 1][ny] && map[nx + 1][ny] == '.') {
      q[head--][0] = nx + 1, q[head][1] = ny;
      nl[nx + 1][ny] = nl[nx][ny], nr[nx + 1][ny] = nr[nx][ny];
      vis[nx + 1][ny] = 1, ans++;
    }
    if (!vis[nx][ny - 1] && map[nx][ny - 1] == '.' && nl[nx][ny]) {
      q[++tail][0] = nx, q[tail][1] = ny - 1;
      nl[nx][ny - 1] = nl[nx][ny] - 1, nr[nx][ny - 1] = nr[nx][ny];
      vis[nx][ny - 1] = 1, ans++;
    }
    if (!vis[nx][ny + 1] && map[nx][ny + 1] == '.' && nr[nx][ny]) {
      q[++tail][0] = nx, q[tail][1] = ny + 1;
      nl[nx][ny + 1] = nl[nx][ny], nr[nx][ny + 1] = nr[nx][ny] - 1;
      vis[nx][ny + 1] = 1, ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
