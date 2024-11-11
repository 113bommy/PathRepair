#include <bits/stdc++.h>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ') {
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
const int N = 3e2 + 5, M = 2e6 + 5;
int n, m, q, tot, id[N][N], col[N][N], ans[M], t[M], u[M], v[M], w[M],
    fa[M + N * N], now;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x ^ y) --now, fa[x] = y;
}
void solve(int i, int j) {
  if (col[i - 1][j] == col[i][j]) merge(id[i - 1][j], id[i][j]);
  if (col[i][j - 1] == col[i][j]) merge(id[i][j - 1], id[i][j]);
  if (col[i + 1][j] == col[i][j]) merge(id[i + 1][j], id[i][j]);
  if (col[i][j + 1] == col[i][j]) merge(id[i][j + 1], id[i][j]);
}
int main() {
  n = read(), m = read(), q = read(), memset(col, -1, sizeof(col));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) id[i][j] = ++tot, col[i][j] = 0, fa[tot] = tot;
  for (int i = 1; i <= q; ++i) {
    u[i] = read(), v[i] = read(), w[i] = read();
    int x = u[i], y = v[i], c = w[i];
    t[i] = col[x][y];
    if (t[i] == w[i]) continue;
    col[x][y] = c, id[x][y] = ++tot, fa[tot] = tot, now = 1, solve(x, y),
    ans[i] += now;
  }
  tot = 0, ans[0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) id[i][j] = ++tot, fa[tot] = tot;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) solve(i, j);
  for (int i = q; i; --i) {
    int x = u[i], y = v[i], c = t[i];
    if (t[i] == w[i]) continue;
    col[x][y] = c, id[x][y] = ++tot, fa[tot] = tot, now = 1, solve(x, y),
    ans[i] -= now;
  }
  for (int i = 1; i <= q; ++i) ans[i] += ans[i - 1], printf("%d\n", ans[i]);
  return 0;
}
