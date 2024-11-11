#include <bits/stdc++.h>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ') {
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
const int N = 2e5 + 5;
struct Edge {
  int next, to;
  Edge(int next = 0, int to = 0) : next(next), to(to){};
} edge[N << 1];
int tot, head[N];
void _add(int x, int y) { edge[++tot] = Edge(head[x], y), head[x] = tot; }
void add(int x, int y) { _add(x, y), _add(y, x); }
int n, m, d[N], fa[N], path[N], u, v;
void dfs(int x, int f) {
  fa[x] = f, d[x] = d[f] + 1;
  for (int i = head[x]; i; i = edge[i].next) {
    int y = edge[i].to;
    if (y == f) continue;
    dfs(y, x);
  }
}
int meth[3][N];
long long ans;
void solve(int x, int topf, int w) {
  if (path[x]) topf = x, w = d[x] - d[u] > d[v] - d[x] ? u : v;
  for (int i = head[x]; i; i = edge[i].next) {
    int y = edge[i].to;
    if (y == fa[x]) continue;
    solve(y, x, w);
  }
  if (!path[x])
    meth[0][++m] = x, meth[1][m] = w, meth[2][m] = x,
    ans += d[x] - d[topf] + abs(d[topf] - d[w]);
}
int main() {
  n = read();
  for (int i = 1, x, y; i < n; ++i) x = read(), y = read(), add(x, y);
  dfs(1, 0);
  for (int i = 1; i <= n; ++i)
    if (d[i] > d[u]) u = i;
  dfs(u, 0);
  for (int i = 1; i <= n; ++i)
    if (d[i] > d[v]) v = i;
  for (int x = v; x; x = fa[x]) path[x] = 1;
  solve(u, 0, 0);
  for (int x = v; x != u; x = fa[x])
    meth[0][++m] = x, meth[1][m] = u, meth[2][m] = x, ans += d[x] - 1;
  printf("%I64d\n", ans);
  for (int i = 1; i < n; ++i, puts(""))
    for (int k = 0; k < 3; ++k) printf("%d ", meth[k][i]);
  return 0;
}
