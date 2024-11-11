#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
char a[N][N];
int v[N][N][4][2], m, n;
int q[N * N * 4 * 2][4];
int check(int x, int y) {
  if (x >= 1 && x <= m && y >= 1 && y <= n && a[x][y] == 'B')
    return 1;
  else
    return 0;
}
int bfs(int sx, int sy) {
  int l = 1, r = 0, i, j, x, y, k, t, nx, ny, nk;
  memset(v, 0, sizeof(v));
  for (i = 0; i < 4; i++) {
    v[i][sx][sy][0] = 1;
    r++;
    q[r][0] = i;
    q[r][1] = sx;
    q[r][2] = sy;
    q[r][3] = 0;
  }
  while (l <= r) {
    x = q[l][1];
    y = q[l][2];
    k = q[l][0];
    t = q[l][3];
    l++;
    nx = x + d[k][0];
    ny = y + d[k][1];
    if (check(nx, ny))
      if (!v[k][nx][ny][t]) {
        v[k][nx][ny][t] = 1;
        r++;
        q[r][0] = k;
        q[r][1] = nx;
        q[r][2] = ny;
        q[r][3] = t;
      }
    if (t == 0) {
      for (i = -1; i <= 1; i += 2) {
        nk = (k + 4 + i) % 4;
        if (!v[nk][x][y][1]) {
          v[nk][x][y][1] = 1;
          r++;
          q[r][0] = nk;
          q[r][1] = x;
          q[r][2] = y;
          q[r][3] = 1;
        }
      }
    }
  }
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
      if (a[i][j] == 'B') {
        int f = 0;
        for (k = 0; k < 4; k++)
          for (t = 0; t <= 1; t++)
            if (v[k][i][j][t]) f = 1;
        if (f == 0) return 0;
      }
  return 1;
}
int main() {
  int i, j;
  scanf("%d%d", &m, &n);
  for (i = 1; i <= m; i++) scanf("%s", a[i] + 1);
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
      if (a[i][j] == 'B') {
        if (bfs(i, j) == 0) {
          printf("NO\n");
          return 0;
        }
      }
  printf("YES\n");
}
