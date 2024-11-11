#include <bits/stdc++.h>
const int mn = 5101, mo = 1000000009;
struct node {
  int x, y;
} po[mn];
int g[mn][mn], c[mn];
int lo, hi, mid;
int n, i, j, cnt, lim;
int abs(int x) { return x > 0 ? x : -x; }
bool sol;
void dfs(int r, int v) {
  int i;
  c[r] = v;
  for (i = 1; i <= n; ++i)
    if (g[r][i] > lim) {
      if (c[i] == v) {
        sol = 0;
        return;
      }
      if (c[i] == -1) dfs(i, v ^ 1);
    }
}
bool calc(int len) {
  int i;
  memset(c, 255, sizeof c);
  lim = len, cnt = 1, sol = 1;
  for (i = 1; i <= n; ++i)
    if (c[i] == -1) {
      cnt = cnt * 2 % mo;
      dfs(i, 1);
      if (!sol) return 0;
    }
  return sol;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d%d", &po[i].x, &po[i].y);
  for (i = 1; i <= n; ++i)
    for (j = i; j <= n; ++j)
      g[i][j] = g[j][i] = abs(po[i].x - po[j].x) + abs(po[i].y - po[j].y);
  lo = 0, hi = 20000;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (calc(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  calc(lo);
  printf("%d\n", lo);
  printf("%d\n", cnt);
  return 0;
}
