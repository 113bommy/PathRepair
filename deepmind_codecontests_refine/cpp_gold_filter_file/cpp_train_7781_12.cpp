#include <bits/stdc++.h>
const int maxn = 2007, inf = 0x3f3f3f3f;
int n, u[maxn], v[maxn], f[maxn][11][11][11][11];
int dist(int a, int b) { return abs(a - b); }
int min(int a, int b) { return a < b ? a : b; }
int dfs(int i, int cur, int a, int b, int c) {
  if (~f[i][cur][a][b][c]) return f[i][cur][a][b][c];
  int ret = inf;
  if (i > n) {
    if (a == 0 && b == 0 && c == 0) return 0;
    if (a) ret = min(ret, dfs(i, a, 0, b, c) + dist(cur, a) + 1);
    if (b) ret = min(ret, dfs(i, b, a, 0, c) + dist(cur, b) + 1);
    if (c) ret = min(ret, dfs(i, c, a, b, 0) + dist(cur, c) + 1);
    return f[i][cur][a][b][c] = ret;
  }
  if (a) ret = min(ret, dfs(i, a, 0, b, c) + dist(cur, a) + 1);
  if (b) ret = min(ret, dfs(i, b, a, 0, c) + dist(cur, b) + 1);
  if (c) ret = min(ret, dfs(i, c, a, b, 0) + dist(cur, c) + 1);
  if (a && b && c) {
    ret = min(ret, dfs(i + 1, v[i], a, b, c) + dist(cur, u[i]) +
                       dist(u[i], v[i]) + 2);
    ret = min(ret,
              dfs(i + 1, a, v[i], b, c) + dist(cur, u[i]) + dist(u[i], a) + 2);
    ret = min(ret,
              dfs(i + 1, b, a, v[i], c) + dist(cur, u[i]) + dist(u[i], b) + 2);
    ret = min(ret,
              dfs(i + 1, c, a, b, v[i]) + dist(cur, u[i]) + dist(u[i], c) + 2);
  } else {
    if (!a)
      ret = min(ret, dfs(i + 1, u[i], v[i], b, c) + dist(cur, u[i]) + 1);
    else if (!b)
      ret = min(ret, dfs(i + 1, u[i], a, v[i], c) + dist(cur, u[i]) + 1);
    else
      ret = min(ret, dfs(i + 1, u[i], a, b, v[i]) + dist(cur, u[i]) + 1);
  }
  return f[i][cur][a][b][c] = ret;
}
int main() {
  memset(f, 0xff, sizeof(f));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", u + i, v + i);
  printf("%d\n", dfs(1, 1, 0, 0, 0));
  return 0;
}
