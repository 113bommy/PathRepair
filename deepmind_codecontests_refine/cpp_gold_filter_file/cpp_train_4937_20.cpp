#include <bits/stdc++.h>
using namespace std;
int n = 4;
int dep[1250000];
int f[1250000][30];
int c[40];
int query(int x, int y) {
  int ans = 0;
  if (dep[x] > dep[y]) swap(x, y);
  for (int p = 25; p >= 0; p--) {
    if (dep[x] <= dep[f[y][p]]) {
      y = f[y][p];
      ans += c[p];
    }
  }
  if (x == y) return ans;
  for (int p = 25; p >= 0; p--)
    if (f[x][p] != f[y][p]) {
      x = f[x][p];
      y = f[y][p];
      ans = ans + 2 * c[p];
    }
  x = f[x][0];
  y = f[y][0];
  ans += 2;
  return ans;
}
int main() {
  c[0] = 1;
  for (int i = 1; i <= 30; i++) c[i] = c[i - 1] * 2;
  dep[1] = 1;
  dep[2] = dep[3] = dep[4] = 2;
  f[2][0] = f[3][0] = f[4][0] = 1;
  int q, xx = 2, yy = 3;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int v, ans = 0;
    scanf("%d", &v);
    f[n + 1][0] = v;
    f[n + 2][0] = v;
    dep[n + 1] = dep[n + 2] = dep[v] + 1;
    for (int j = 1; j <= 20; j++) {
      f[n + 1][j] = f[f[n + 1][j - 1]][j - 1];
      f[n + 2][j] = f[f[n + 2][j - 1]][j - 1];
    }
    int c1 = query(xx, n + 1), c2 = query(yy, n + 1), c3 = query(xx, yy);
    if (c1 < c2) {
      if (c2 > c3) {
        xx = n + 1;
        ans = c2;
      } else
        ans = c3;
    } else {
      if (c1 > c3) {
        yy = n + 1;
        ans = c1;
      } else
        ans = c3;
    }
    printf("%d\n", ans);
    n += 2;
  }
  return 0;
}
