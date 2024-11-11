#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
inline char gc() {
  static const int L = 1000;
  static char sxd[L], *sss = sxd, *ttt = sxd;
  if (sss == ttt) {
    ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
    if (sss == ttt) return EOF;
  }
  return *sss++;
}
inline int read(int& x) {
  x = 0;
  char c = getchar();
  bool f = false;
  for (; !isdigit(c); c = getchar()) {
    if (c == EOF) return -1;
    if (c == '-') f = true;
  }
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return 1;
}
int i, j, f, n, m, g[1000][1000], a[1000][1000], b[1000], c[1000], num;
int main() {
  read(n);
  read(m);
  for (i = 0; i < n; i++) b[i] = 1000;
  for (i = 0; i < m; i++) c[i] = 1000;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) read(g[i][j]);
  if (n <= m) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) b[i] = min(b[i], g[i][j]);
      for (j = 0; j < m; j++) g[i][j] -= b[i];
      num += b[i];
    }
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) c[i] = min(c[i], g[j][i]);
      for (j = 0; j < n; j++) g[j][i] -= c[i];
      num += c[i];
    }
  } else {
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) c[i] = min(c[i], g[j][i]);
      for (j = 0; j < n; j++) g[j][i] -= c[i];
      num += c[i];
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) b[i] = min(b[i], g[i][j]);
      for (j = 0; j < m; j++) g[i][j] -= b[i];
      num += b[i];
    }
  }
  f = 1;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (g[i][j]) {
        f = 0;
        break;
      }
  if (f) {
    cout << num << endl;
    for (i = 0; i < n; i++)
      for (j = 0; j < b[i]; j++) printf("row %d\n", i + 1);
    for (i = 0; i < m; i++)
      for (j = 0; j < c[i]; j++) printf("col %d\n", i + 1);
  } else
    puts("-1");
  return 0;
}
