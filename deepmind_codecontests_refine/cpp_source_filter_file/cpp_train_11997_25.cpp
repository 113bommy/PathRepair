#include <bits/stdc++.h>
using namespace std;
char c[60][60];
int u[4000], n, m;
int a[60][60][4][2];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int f(int x, int y) { return x * m + y; }
int pd(int x) {
  if (u[x] == x) return x;
  return u[x] = pd(u[x]);
}
bool ck(int x, int y) {
  if (x < 0 || y < 0) return false;
  if (x < n && y < m && c[x][y] != '0') return true;
  return false;
}
int main() {
  int s, i, j, k, x, y, p, q, an, xx, yy;
  scanf("%d%d", &n, &s);
  for (i = 0; i < n; i++) {
    scanf("%s", c[i]);
    m = strlen(c[i]);
    for (j = 0; j < m; j++) {
      u[f(i, j)] = f(i, j);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      for (k = 0; k < 4; k++) {
        x = i + dx[k];
        y = j + dy[k];
        if (ck(x, y) && c[x][y] == c[i][j]) {
          u[pd(f(x, y))] = pd(f(i, j));
        }
      }
    }
  }
  x = y = p = q = 0;
  an = 1;
  s++;
  while (1) {
    if (an == s) {
      printf("%c\n", c[x][y]);
      return 0;
    }
    if (a[x][y][p][q]) {
      yy = an - a[x][y][p][q];
      xx = (m - a[x][y][p][q]) % yy + a[x][y][p][q];
      for (x = 0; x < n; x++) {
        for (y = 0; y < m; y++) {
          for (p = 0; p < 4; p++) {
            for (q = 0; q < 2; q++) {
              if (a[x][y][p][q] == xx) {
                printf("%c\n", c[x][y]);
                return 0;
              }
            }
          }
        }
      }
    }
    a[x][y][p][q] = an++;
    xx = x;
    yy = y;
    if (p == 0) {
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          if (pd(f(i, j)) == pd(f(x, y))) {
            if (yy < j) {
              yy = j;
              xx = i;
            } else if (yy == j) {
              if (q == 0) {
                xx = min(xx, i);
              } else {
                xx = max(xx, i);
              }
            }
          }
        }
      }
    } else if (p == 1) {
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          if (pd(f(i, j)) == pd(f(x, y))) {
            if (xx < i) {
              yy = j;
              xx = i;
            } else if (xx == i) {
              if (q == 0) {
                yy = max(yy, j);
              } else {
                yy = min(yy, j);
              }
            }
          }
        }
      }
    } else if (p == 2) {
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          if (pd(f(i, j)) == pd(f(x, y))) {
            if (yy > j) {
              yy = j;
              xx = i;
            } else if (yy == j) {
              if (q == 0) {
                xx = max(xx, i);
              } else {
                xx = min(xx, i);
              }
            }
          }
        }
      }
    } else {
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          if (pd(f(i, j)) == pd(f(x, y))) {
            if (xx > i) {
              yy = j;
              xx = i;
            } else if (xx == i) {
              if (q == 0) {
                yy = min(yy, j);
              } else {
                yy = max(yy, j);
              }
            }
          }
        }
      }
    }
    xx = xx + dx[p];
    yy = yy + dy[p];
    if (ck(xx, yy)) {
      x = xx;
      y = yy;
    } else {
      q++;
      if (q == 2) {
        p = (p + 1) % 4;
        q = 0;
      }
    }
  }
  return 0;
}
