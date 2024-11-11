#include <bits/stdc++.h>
using std::min;
const int fin = 0, maxn = 2010, maxm = 200010;
int n, m, M, tim;
int fs[maxn], oth[maxm], next[maxm];
int v[maxn], low[maxn], dfn[maxn];
int p[maxn], P[maxn], d[maxn];
bool g[maxn][maxn], cut[maxm];
int q[maxn], D[maxn];
void dfs(int x, int p) {
  int t;
  dfn[x] = low[x] = ++tim, v[x] = 1;
  for (int i = fs[x]; i; i = next[i])
    if (t = oth[i], !v[t]) {
      dfs(t, i ^ 1), low[x] = min(low[x], low[t]);
      if (dfn[x] < low[t]) cut[i] = cut[i ^ 1] = 1;
    } else if (v[t] == 1 && i != p)
      low[x] = min(low[x], dfn[t]);
  v[x] = 2;
}
int getf(int *p, int x) {
  if (p[x] != x && p[p[x]] != p[x]) p[x] = getf(p, p[x]);
  return p[x];
}
void merge(int *p, int x, int y) {
  if (x = getf(p, x), y = getf(p, y), x != y) p[y] = x;
}
int bfs(int s) {
  int i, u, t, head, tail;
  for (i = 1; i <= n; ++i)
    if (p[i] == i && P[s] == P[i]) v[i] = 0;
  q[head = tail = 1] = s, v[s] = 0, D[s] = 1;
  while (head <= tail)
    for (u = q[head++], t = 1; t <= n; ++t)
      if (g[u][t] && !v[t]) v[t] = 1, D[t] = D[u] + 1, q[++tail] = t;
  return q[tail];
}
int sol(int x) {
  int s = 0, i;
  for (i = 1; i <= n; ++i)
    if (p[i] == i && P[x] == P[i] && d[i] > 1) ++s;
  if (!s) return 0;
  s -= D[bfs(bfs(x))] - 2;
  return s;
}
int main() {
  if (fin) {
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
  }
  int i, x, y, ans = -1, t;
  scanf("%d%d", &n, &M), m = 1;
  while (M--) {
    scanf("%d%d", &x, &y);
    if (x == y) continue;
    oth[++m] = y, next[m] = fs[x], fs[x] = m;
    oth[++m] = x, next[m] = fs[y], fs[y] = m;
  }
  for (i = 1; i <= n; ++i)
    if (!v[i]) ++ans, dfs(i, 0);
  for (i = 1; i <= n; ++i) p[i] = i;
  for (x = 1; x <= n; ++x)
    for (int i = fs[x]; i; i = next[i])
      if (!cut[i]) merge(p, x, oth[i]);
  for (i = 1; i <= n; ++i) p[i] = getf(p, i);
  for (i = 1; i <= n; ++i)
    if (i != p[i])
      ++ans;
    else
      P[i] = i;
  for (x = 1; x <= n; ++x)
    for (int i = fs[x]; i; i = next[i])
      if (cut[i])
        if (t = oth[i], x < t) {
          g[p[x]][p[t]] = g[p[t]][p[x]] = 1;
          ++d[p[x]], ++d[p[t]];
          merge(P, p[x], p[t]);
        }
  for (i = 1; i <= n; ++i)
    if (p[i] == i) P[i] = getf(P, i);
  memset(v, 0, sizeof(v));
  for (i = 1; i <= n; ++i)
    if (i == p[i] && i == P[i]) ans += sol(i);
  printf("%d\n", ans);
  return 0;
}
