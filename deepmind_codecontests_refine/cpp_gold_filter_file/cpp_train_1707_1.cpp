#include <bits/stdc++.h>
typedef int mang[100001];
int n, m, da[100][100];
mang fx, fy, x, y, bx, by, q;
int a[6441][6441], Free[10069];
int cal(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m) return 0;
  return (y - 1) * n + x;
}
void nhap() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) scanf("%d", &da[j][i]);
  }
  for (int i = 0; i <= 6400; ++i)
    for (int j = 0; j <= 6400; ++j) a[i][j] = 500000;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i + j) % 2 == 0) {
        Free[cal(j, i)] = 1;
        a[cal(j, i)][cal(j - 1, i)] = !(da[j][i] == da[j - 1][i]);
        a[cal(j, i)][cal(j + 1, i)] = !(da[j][i] == da[j + 1][i]);
        a[cal(j, i)][cal(j, i + 1)] = !(da[j][i] == da[j][i + 1]);
        a[cal(j, i)][cal(j, i - 1)] = !(da[j][i] == da[j][i - 1]);
      }
    }
  }
  n = n * m;
}
void tangcap(int v) {
  int u, k;
  while (v > 0) {
    u = by[v];
    k = x[u];
    x[u] = v;
    y[v] = u;
    v = k;
  }
}
bool bfs(int i) {
  int L, R;
  q[L = R = 1] = i;
  memset(by, 0, sizeof(by));
  memset(bx, 0, sizeof(bx));
  bx[i] = 1;
  while (L <= R) {
    int u = q[L++];
    for (int v = 1; v <= n; ++v)
      if (by[v] == 0 && fx[u] + a[u][v] - fy[v] == 0) {
        by[v] = u;
        if (y[v] == 0) {
          tangcap(v);
          return true;
        }
        q[++R] = y[v];
        bx[y[v]] = 1;
      }
  }
  return false;
}
void suanhan() {
  int dt = 500000;
  for (int i = 1; i <= n; ++i)
    if (bx[i] == 1)
      for (int j = 1; j <= n; ++j)
        if (by[j] == 0)
          if (dt > fx[i] + a[i][j] - fy[j]) dt = fx[i] + a[i][j] - fy[j];
  for (int i = 1; i <= n; ++i)
    if (bx[i] == 0) fx[i] += dt;
  for (int i = 1; i <= n; ++i)
    if (by[i] == 0) fy[i] += dt;
}
void xuly() {
  for (int i = 1; i <= n; ++i) {
    if (Free[i])
      while (!bfs(i)) suanhan();
  }
  int res = 0;
  for (int i = 1; i <= n; ++i)
    if (Free[i]) res += a[i][x[i]];
  printf("%d\n", res);
}
int main() {
  nhap();
  xuly();
  return 0;
}
