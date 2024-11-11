#include <bits/stdc++.h>
using namespace std;
int a[305][305];
int b[305][305];
int c[305][305];
int d[305][305];
int n, m, t, tp, ta, td;
int g[305][305];
inline int abs(int x) {
  if (x < 0) return -x;
  return x;
}
int main() {
  int i, j, k, l;
  scanf("%d%d%d", &n, &m, &t);
  scanf("%d%d%d", &tp, &ta, &td);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%d", &g[i][j]);
    }
  }
  for (i = 1; i <= n; i++) {
    a[i][1] = 0;
    for (j = 2; j <= m; j++) {
      if (g[i][j] > g[i][j - 1]) {
        a[i][j] = a[i][j - 1] + ta;
        continue;
      }
      if (g[i][j] < g[i][j - 1]) {
        a[i][j] = a[i][j - 1] + td;
        continue;
      }
      if (g[i][j] == g[i][j - 1]) {
        a[i][j] = a[i][j - 1] + tp;
        continue;
      }
    }
  }
  for (i = 1; i <= m; i++) {
    b[i][1] = 0;
    for (j = 2; j <= n; j++) {
      if (g[j - 1][i] > g[j][i]) {
        b[i][j] = b[i][j - 1] + td;
        continue;
      }
      if (g[j - 1][i] < g[j][i]) {
        b[i][j] = b[i][j - 1] + ta;
        continue;
      }
      if (g[j - 1][i] == g[j][i]) {
        b[i][j] = b[i][j - 1] + tp;
        continue;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    c[i][m] = 0;
    for (j = m - 1; j >= 1; j--) {
      if (g[i][j] > g[i][j + 1]) {
        c[i][j] = c[i][j + 1] + ta;
        continue;
      }
      if (g[i][j] < g[i][j + 1]) {
        c[i][j] = c[i][j + 1] + td;
        continue;
      }
      if (g[i][j] == g[i][j + 1]) {
        c[i][j] = c[i][j + 1] + tp;
        continue;
      }
    }
  }
  for (i = 1; i <= m; i++) {
    d[i][n] = 0;
    for (j = n - 1; j >= 1; j--) {
      if (g[j + 1][i] > g[j][i]) {
        d[i][j] = d[i][j + 1] + td;
        continue;
      }
      if (g[j + 1][i] < g[j][i]) {
        d[i][j] = d[i][j + 1] + ta;
        continue;
      }
      if (g[j + 1][i] == g[j][i]) {
        d[i][j] = d[i][j + 1] + tp;
        continue;
      }
    }
  }
  int dt = 2000000000, pa, pb, pc, pd, tr, t1, t2;
  for (i = 1; i <= n; i++) {
    if (dt == 0) {
      break;
    }
    for (j = 1; j <= m; j++) {
      t1 = -a[i][j] + d[j][i];
      for (k = i + 2; k <= n; k++) {
        t2 = -d[j][k] + c[k][j];
        for (l = j + 2; l <= m; l++) {
          tr = t1 + t2 + a[i][l] - c[k][l] + b[l][k] - b[l][i] - t;
          if (tr < 0) {
            tr = -tr;
          }
          if (tr < dt) {
            dt = tr, pa = i, pb = j, pc = k, pd = l;
          }
        }
      }
    }
  }
  printf("%d %d %d %d\n", pa, pb, pc, pd);
  return 0;
}
