#include <bits/stdc++.h>
using namespace std;
char c[1010][1010];
int u[1010][1010], d[1010][1010];
int ud[1010][1010];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m, t = 1, ans, ss, pt = 1, xo, yo, so;
int fl;
bool pd(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= m) return false;
  return true;
}
void ddfs(int x, int y) {
  int xx, yy, i, t = 0;
  so++;
  ud[x][y] = 1;
  for (i = 0; i < 4; i++) {
    xx = x + dx[i];
    yy = y + dy[i];
    if (pd(xx, yy) && d[xx][yy] == d[xo][yo]) {
      t++;
    }
    if (pd(xx, yy) && d[xx][yy] == d[xo][yo] && ud[xx][yy] == 0) {
      ddfs(xx, yy);
    }
  }
  if (t != 2) fl = 0;
}
bool dfs(int x, int y) {
  int xx, yy, i, j;
  u[x][y] = pt;
  for (i = -1; i < 2; i++) {
    for (j = -1; j < 2; j++) {
      if (i == 0 && j == 0) continue;
      xx = x + i, yy = y + j;
      if (!pd(xx, yy)) {
        fl = 0;
        continue;
      }
      if (c[xx][yy] == '0' && u[xx][yy] == 0) {
        dfs(xx, yy);
      }
    }
  }
  for (i = -1; i < 2; i++) {
    for (j = -1; j < 2; j++) {
      if (i == 0 && j == 0) continue;
      xx = x + i, yy = y + j;
      if (c[xx][yy] == '1' && d[xx][yy] != t) {
        d[xx][yy] = t;
        ud[xx][yy] = 0;
        xo = xx;
        yo = yy;
        ss++;
      }
    }
  }
  return true;
}
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (c[i][j] == '0' && u[i][j] == 0) {
        ss = 0;
        fl = 1;
        dfs(i, j);
        if (fl) {
          so = 0;
          fl = 1;
          ddfs(xo, yo);
          if (fl && so == ss) {
            ans = max(ans, ss);
          }
        }
        t++;
        pt++;
      }
    }
  }
  for (i = 0; i < n - 1; i++) {
    t = 0;
    for (j = 0; j < m; j++) {
      if (c[i][j] == '1' && c[i + 1][j] == '1') {
        t++;
        if (t > 1) {
          ans = max(ans, t * 2);
        }
      } else {
        t = 0;
      }
    }
  }
  for (j = 0; j < m - 1; j++) {
    t = 0;
    for (i = 0; i < n; i++) {
      if (c[i][j] == '1' && c[i][j + 1] == '1') {
        t++;
        if (t > 1) {
          ans = max(ans, t * 2);
        }
      } else {
        t = 0;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
