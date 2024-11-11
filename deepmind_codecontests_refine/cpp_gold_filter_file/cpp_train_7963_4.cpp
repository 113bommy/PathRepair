#include <bits/stdc++.h>
using std::min;
const int inf = 0X1FFFFFFF;
const int dx[] = {-1, 0, +1, 0};
const int dy[] = {0, -1, 0, +1};
int n, m, x, y, ans, AB, AC, BA, BC, CA, CB;
int a[1009][1009], b[1009][1009], c[1009][1009];
char g[1009][1009];
int l, r, qx[1000009], qy[1000009];
bool inq[1009][1009];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", g[i] + 1);
  r = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[i][j] = inf;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (g[i][j] == '1') {
        a[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
          x = i + dx[k], y = j + dy[k];
          if (g[x][y] == '.' && !inq[x][y]) {
            a[x][y] = 1;
            inq[x][y] = true;
            qx[r] = x, qy[r] = y, ++r;
          }
          if (g[x][y] == '2') a[x][y] = 0;
          if (g[x][y] == '3') a[x][y] = 0;
        }
      }
  for (l = 0; l < r; ++l) {
    inq[qx[l]][qy[l]] = false;
    for (int k = 0; k < 4; ++k) {
      x = qx[l] + dx[k], y = qy[l] + dy[k];
      if (g[x][y] == '2' && a[x][y] == inf) a[x][y] = a[qx[l]][qy[l]];
      if (g[x][y] == '3' && a[x][y] == inf) a[x][y] = a[qx[l]][qy[l]];
      if (g[x][y] == '.' && a[qx[l]][qy[l]] + 1 < a[x][y]) {
        a[x][y] = a[qx[l]][qy[l]] + 1;
        if (!inq[x][y]) {
          inq[x][y] = true;
          qx[r] = x, qy[r] = y, ++r;
        }
      }
    }
  }
  r = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) b[i][j] = inf;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (g[i][j] == '2') {
        b[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
          x = i + dx[k], y = j + dy[k];
          if (g[x][y] == '.' && !inq[x][y]) {
            b[x][y] = 1;
            inq[x][y] = true;
            qx[r] = x, qy[r] = y, ++r;
          }
          if (g[x][y] == '1') b[x][y] = 0;
          if (g[x][y] == '3') b[x][y] = 0;
        }
      }
  for (l = 0; l < r; ++l) {
    inq[qx[l]][qy[l]] = false;
    for (int k = 0; k < 4; ++k) {
      x = qx[l] + dx[k], y = qy[l] + dy[k];
      if (g[x][y] == '1' && b[x][y] == inf) b[x][y] = b[qx[l]][qy[l]];
      if (g[x][y] == '3' && b[x][y] == inf) b[x][y] = b[qx[l]][qy[l]];
      if (g[x][y] == '.' && b[qx[l]][qy[l]] + 1 < b[x][y]) {
        b[x][y] = b[qx[l]][qy[l]] + 1;
        if (!inq[x][y]) {
          inq[x][y] = true;
          qx[r] = x, qy[r] = y, ++r;
        }
      }
    }
  }
  r = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) c[i][j] = inf;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (g[i][j] == '3') {
        c[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
          x = i + dx[k], y = j + dy[k];
          if (g[x][y] == '.' && !inq[x][y]) {
            c[x][y] = 1;
            inq[x][y] = true;
            qx[r] = x, qy[r] = y, ++r;
          }
          if (g[x][y] == '1') c[x][y] = 0;
          if (g[x][y] == '2') c[x][y] = 0;
        }
      }
  for (l = 0; l < r; ++l) {
    inq[qx[l]][qy[l]] = false;
    for (int k = 0; k < 4; ++k) {
      x = qx[l] + dx[k], y = qy[l] + dy[k];
      if (g[x][y] == '1' && c[x][y] == inf) c[x][y] = c[qx[l]][qy[l]];
      if (g[x][y] == '2' && c[x][y] == inf) c[x][y] = c[qx[l]][qy[l]];
      if (g[x][y] == '.' && c[qx[l]][qy[l]] + 1 < c[x][y]) {
        c[x][y] = c[qx[l]][qy[l]] + 1;
        if (!inq[x][y]) {
          inq[x][y] = true;
          qx[r] = x, qy[r] = y, ++r;
        }
      }
    }
  }
  AB = AC = BA = BC = CA = CB = inf;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (g[i][j] == '1') {
        AB = min(AB, b[i][j]);
        AC = min(AC, c[i][j]);
      }
      if (g[i][j] == '2') {
        BA = min(BA, a[i][j]);
        BC = min(BC, c[i][j]);
      }
      if (g[i][j] == '3') {
        CA = min(CA, a[i][j]);
        CB = min(CB, b[i][j]);
      }
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (g[i][j] == '1') b[i][j] = AB, c[i][j] = AC;
      if (g[i][j] == '2') a[i][j] = BA, c[i][j] = BC;
      if (g[i][j] == '3') a[i][j] = CA, b[i][j] = CB;
    }
  ans = inf;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (g[i][j] == '.')
        ans = min(ans, a[i][j] + b[i][j] + c[i][j] - 2);
      else
        ans = min(ans, a[i][j] + b[i][j] + c[i][j]);
    }
  printf("%d\n", ans < inf ? ans : -1);
  return 0;
}
