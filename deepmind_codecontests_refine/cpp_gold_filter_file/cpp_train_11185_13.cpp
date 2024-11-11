#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int b[1000][1000];
int l[1000][1000] = {};
int r[1000][1000] = {};
int u[1000][1000] = {};
int d[1000][1000] = {};
inline void calculateRow(int i) {
  l[i][0] = b[i][0];
  for (int z = 1; z < m; ++z) {
    if (b[i][z] == 1)
      l[i][z] = l[i][z - 1] + 1;
    else
      l[i][z] = 0;
  }
  r[i][m - 1] = b[i][m - 1];
  for (int z = m - 2; z >= 0; --z) {
    if (b[i][z] == 1)
      r[i][z] = r[i][z + 1] + 1;
    else
      r[i][z] = 0;
  }
}
inline void calculateCol(int j) {
  u[0][j] = b[0][j];
  for (int z = 1; z < n; ++z) {
    if (b[z][j] == 1)
      u[z][j] = u[z - 1][j] + 1;
    else
      u[z][j] = 0;
  }
  d[n - 1][j] = b[n - 1][j];
  for (int z = n - 2; z >= 0; --z) {
    if (b[z][j] == 1)
      d[z][j] = d[z + 1][j] + 1;
    else
      d[z][j] = 0;
  }
}
inline void updateOne(int x, int y) {
  calculateRow(y);
  calculateCol(x);
}
inline void initCalculate() {
  for (int i = 0; i < n; ++i) calculateRow(i);
  for (int j = 0; j < m; ++j) calculateCol(j);
}
inline int mxF(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
inline int getMaxRow(int x, int y) {
  int c = 0;
  if (b[y][x] == 0) return 0;
  int l = x, r = x;
  int mn = u[y][x];
  while (mn > 0 && (l >= 0 || r < m)) {
    while (l >= 0 && u[y][l] >= mn) l--;
    while (r < m && u[y][r] >= mn) r++;
    c = mxF(c, mn * (r - l - 1));
    if (l >= 0 && r < m) {
      mn = mxF(u[y][l], u[y][r]);
    } else if (l >= 0) {
      mn = u[y][l];
    } else if (r < m) {
      mn = u[y][r];
    }
  }
  l = x;
  r = x;
  mn = d[y][x];
  while (mn > 0 && (l >= 0 || r < m)) {
    while (l >= 0 && d[y][l] >= mn) l--;
    while (r < m && d[y][r] >= mn) r++;
    c = mxF(c, mn * (r - l - 1));
    if (l >= 0 && r < m) {
      mn = mxF(d[y][l], d[y][r]);
    } else if (l >= 0) {
      mn = d[y][l];
    } else if (r < m) {
      mn = d[y][r];
    }
  }
  return c;
}
inline int getMaxCol(int x, int y) {
  int c = 0;
  if (b[y][x] == 0) return 0;
  int uu = y, dd = y;
  int mn = l[y][x];
  while (mn > 0 && (dd >= 0 || uu < n)) {
    while (dd >= 0 && l[dd][x] >= mn) dd--;
    while (uu < n && l[uu][x] >= mn) uu++;
    c = mxF(c, mn * (uu - dd - 1));
    if (dd >= 0 && uu < n) {
      mn = mxF(l[dd][x], l[uu][x]);
    } else if (dd >= 0) {
      mn = l[dd][x];
    } else if (uu < n) {
      mn = l[uu][x];
    }
  }
  dd = y;
  uu = y;
  mn = r[y][x];
  while (mn > 0 && (dd >= 0 || uu < n)) {
    while (dd >= 0 && r[dd][x] >= mn) dd--;
    while (uu < n && r[uu][x] >= mn) uu++;
    c = mxF(c, mn * (uu - dd - 1));
    if (dd >= 0 && uu < n) {
      mn = mxF(r[dd][x], r[uu][x]);
    } else if (dd >= 0) {
      mn = r[dd][x];
    } else if (uu < n) {
      mn = r[uu][x];
    }
  }
  return c;
}
int main(int argc, const char* argv[]) {
  cin >> n >> m >> q;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &b[i][j]);
  initCalculate();
  for (int z = 0; z < q; ++z) {
    int op, x, y;
    cin >> op >> x >> y;
    x--;
    y--;
    swap(x, y);
    if (op == 1) {
      b[y][x] = !b[y][x];
      updateOne(x, y);
    }
    if (op == 2) {
      int ans = mxF(getMaxCol(x, y), getMaxRow(x, y));
      printf("%d\n", ans);
    }
  }
  return 0;
}
