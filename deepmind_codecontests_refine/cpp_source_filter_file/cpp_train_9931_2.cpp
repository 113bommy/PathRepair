#include <bits/stdc++.h>
using namespace std;
int s[1700][1700];
char c[1700][1700];
char b[1700][1700];
int que[4000000][2];
int mm[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int g[1700][1700];
int p, q, dx, dy;
void fill(int x, int y, int id) {
  p = 0;
  q = -1;
  g[x][y] = id;
  que[0][0] = x;
  que[0][1] = y;
  while (p != q) {
    x = que[++q][0];
    y = que[q][1];
    for (int i = 0; i < 4; i++) {
      dx = x + mm[i][0];
      dy = y + mm[i][1];
      if (g[dx][dy] != id && c[dx][dy]) {
        g[dx][dy] = id;
        que[++p][0] = dx;
        que[p][1] = dy;
      }
    }
  }
}
int ct[10000];
int main() {
  int n, m, i, j, x, y, gid;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &x);
      c[i + 15][j + 15] = x;
    }
  }
  n += 30;
  m += 30;
  gid = 0;
  for (i = 1; i < n; i++) {
    for (j = 1; j < m; j++) {
      if (c[i][j] && g[i][j] == 0) {
        gid++;
        fill(i, j, gid);
      }
    }
  }
  for (i = 1; i < n; i++) {
    for (j = 1; j < m; j++) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + c[i][j];
    }
  }
  for (i = 10; i < n - 10; i++) {
    for (j = 10; j < m - 10; j++) {
      x = s[i + 2][j + 2] + s[i - 3][j - 3] - s[i - 3][j + 2] - s[i + 2][j - 3];
      if (x == 25) {
        b[i][j] = 1;
      }
    }
  }
  for (i = 1; i < n; i++) {
    for (j = 1; j < m; j++) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + b[i][j];
    }
  }
  for (i = 14; i < n - 14; i++) {
    for (j = 14; j < m - 14; j++) {
      x = s[i + 6][j + 6] + s[i - 7][j - 7] - s[i - 7][j + 6] - s[i + 6][j - 7];
      if (x) {
        c[i][j] = 0;
      }
    }
  }
  for (i = 1; i < n; i++) {
    for (j = 1; j < m; j++) {
      if (c[i][j] && g[i][j]) {
        int x = g[i][j];
        fill(i, j, 0);
        ct[x - 1]++;
      }
    }
  }
  sort(ct, ct + gid);
  printf("%d\n", gid);
  if (gid) {
    for (i = 0; i < gid - 1; i++) {
      printf("%d ", ct[i]);
    }
    printf("%d\n", ct[gid - 1]);
  }
  return 0;
}
