#include <bits/stdc++.h>
using namespace std;
int a[1010][1010][4], q[4000010][4], ans, n, m;
bool vis[1010][1010][4];
int turn[14] = {0, 1, 3, 2, 5, 7, 4, 6, 10, 11, 9, 8, 12};
int up[6] = {1, 3, 4, 8, 9, 11}, dw[6] = {1, 3, 7, 8, 9, 10};
int lf[6] = {1, 2, 6, 9, 10, 11}, rg[6] = {1, 2, 5, 8, 10, 11};
bool bfs(int sx, int sy, int ex, int ey) {
  int he = 0, ta = 0, x, y, z, d;
  bool flag1, flag2;
  q[++ta][0] = sx, q[ta][1] = sy, q[ta][2] = 0, q[ta][3] = 0;
  while (he != ta) {
    x = q[++he][0], y = q[he][1], z = q[he][2], d = q[he][3] + 1;
    if (x == ex && y == ey) {
      ans = q[he][3];
      return true;
    }
    if (x > 1) {
      flag1 = false, flag2 = false;
      for (int i = 0; i <= 5; i++)
        if (a[x][y][z] == up[i]) flag1 = true;
      for (int i = 0; i <= 5; i++)
        if (a[x - 1][y][z] == dw[i]) flag2 = true;
      if (flag1 && flag2 && !vis[x - 1][y][z]) {
        q[++ta][0] = x - 1, q[ta][1] = y, q[ta][2] = z, q[ta][3] = d;
        vis[x - 1][y][z] = true;
      }
    }
    if (x < n) {
      flag1 = false, flag2 = false;
      for (int i = 0; i <= 5; i++)
        if (a[x][y][z] == dw[i]) flag1 = true;
      for (int i = 0; i <= 5; i++)
        if (a[x + 1][y][z] == up[i]) flag2 = true;
      if (flag1 && flag2 && !vis[x + 1][y][z]) {
        q[++ta][0] = x + 1, q[ta][1] = y, q[ta][2] = z, q[ta][3] = d;
        vis[x + 1][y][z] = true;
      }
    }
    if (y > 1) {
      flag1 = false, flag2 = false;
      for (int i = 0; i <= 5; i++)
        if (a[x][y][z] == lf[i]) flag1 = true;
      for (int i = 0; i <= 5; i++)
        if (a[x][y - 1][z] == rg[i]) flag2 = true;
      if (flag1 && flag2 && !vis[x][y - 1][z]) {
        q[++ta][0] = x, q[ta][1] = y - 1, q[ta][2] = z, q[ta][3] = d;
        vis[x][y - 1][z] = true;
      }
    }
    if (y < m) {
      flag1 = false, flag2 = false;
      for (int i = 0; i <= 5; i++)
        if (a[x][y][z] == rg[i]) flag1 = true;
      for (int i = 0; i <= 5; i++)
        if (a[x][y + 1][z] == lf[i]) flag2 = true;
      if (flag1 && flag2 && !vis[x][y + 1][z]) {
        q[++ta][0] = x, q[ta][1] = y + 1, q[ta][2] = z, q[ta][3] = d;
        vis[x][y + 1][z] = true;
      }
    }
    if (!vis[x][y][(z + 1) % 4]) {
      q[++ta][0] = x, q[ta][1] = y, q[ta][2] = (z + 1) % 4, q[ta][3] = d;
      vis[x][y][(z + 1) % 4] = true;
    }
  }
  return false;
}
int main() {
  int x1, y1, x2, y2;
  char c;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> c;
      if (c == '+')
        a[i][j][0] = 1;
      else if (c == '-')
        a[i][j][0] = 2;
      else if (c == '|')
        a[i][j][0] = 3;
      else if (c == '^')
        a[i][j][0] = 4;
      else if (c == '>')
        a[i][j][0] = 5;
      else if (c == '<')
        a[i][j][0] = 6;
      else if (c == 'v')
        a[i][j][0] = 7;
      else if (c == 'L')
        a[i][j][0] = 8;
      else if (c == 'R')
        a[i][j][0] = 9;
      else if (c == 'U')
        a[i][j][0] = 10;
      else if (c == 'D')
        a[i][j][0] = 11;
      else if (c == '*')
        a[i][j][0] = 12;
      a[i][j][1] = turn[a[i][j][0]];
      a[i][j][2] = turn[a[i][j][1]];
      a[i][j][3] = turn[a[i][j][2]];
    }
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  if (bfs(x1, y1, x2, y2))
    printf("%d\n", ans);
  else
    printf("-1\n");
  return 0;
}
