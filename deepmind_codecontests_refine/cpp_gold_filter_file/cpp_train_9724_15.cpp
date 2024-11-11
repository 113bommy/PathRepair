#include <bits/stdc++.h>
using namespace std;
const int maxn = 855, maxm = 3005;
int n, m, T, q, ans, sum, mark[maxn], a[maxn], tmp[maxn];
inline int gi() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return sum;
}
const int Maxn = 855, Maxm = 8505 * 2, Inf = 2147483641;
struct edge {
  int to, next, cap;
} e[Maxm];
int h[Maxn], tot, s, t;
int ecnt, eu[maxm], ev[maxm], ew[maxm], fa[maxn];
inline void add(int u, int v, int w) {
  e[++tot] = (edge){v, h[u], w};
  h[u] = tot;
  e[++tot] = (edge){u, h[v], w};
  h[v] = tot;
}
bool vis[Maxn];
int l, r, que[Maxn], d[Maxn], cur[Maxn];
inline bool bfs() {
  memset(vis, 0, sizeof(bool) * (n + 1));
  l = 0;
  r = 1;
  que[r] = s;
  vis[s] = true;
  do {
    int u = que[++l];
    for (int i = h[u], v; ~i; i = e[i].next)
      if (e[i].cap && !vis[v = e[i].to]) {
        vis[v] = true;
        d[v] = d[u] + 1;
        que[++r] = v;
      }
  } while (l < r);
  return vis[t];
}
int dfs(int u, int a) {
  if (u == t || a == 0) return a;
  int f, flow = 0;
  for (int &i = cur[u], v; ~i; i = e[i].next) {
    if (d[u] + 1 == d[v = e[i].to] && (f = dfs(v, min(a, e[i].cap)))) {
      e[i].cap -= f;
      e[i ^ 1].cap += f;
      flow += f;
      a -= f;
      if (a == 0) break;
    }
  }
  return flow;
}
void dfs(int u) {
  mark[u] = 1;
  for (int i = h[u]; ~i; i = e[i].next)
    if (e[i].cap && !mark[e[i].to]) dfs(e[i].to);
}
int C[maxn], cnt;
void solve(int l, int r) {
  if (l >= r) return;
  for (int i = 0; i <= tot; i += 2)
    e[i].cap = e[i ^ 1].cap = (e[i].cap + e[i ^ 1].cap) >> 1;
  int flow = 0;
  s = a[l];
  t = a[r];
  while (bfs()) {
    memcpy(cur, h, sizeof(int) * (n + 1));
    flow += dfs(s, Inf);
  }
  ans += flow;
  memset(mark, 0, sizeof(mark));
  dfs(s);
  int i = l, j = r;
  for (int k = l; k <= r; ++k)
    if (mark[a[k]])
      tmp[i++] = a[k];
    else
      tmp[j--] = a[k];
  for (int k = l; k <= r; ++k) a[k] = tmp[k];
  ++ecnt;
  eu[ecnt] = s;
  ev[ecnt] = t;
  ew[ecnt] = flow;
  solve(l, i - 1);
  solve(j + 1, r);
}
vector<int> vec[maxn];
int Id[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int main() {
  n = gi();
  m = gi();
  memset(h, -1, sizeof(h));
  tot = -1;
  for (int u, v, c, i = 1; i <= m; ++i) {
    u = gi();
    v = gi();
    c = gi();
    add(u, v, c);
  }
  ans = 0;
  for (int i = 1; i <= n; ++i) a[i] = i;
  solve(1, n);
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) fa[i] = i, vec[i].push_back(i), Id[i] = i;
  sort(Id + 1, Id + n, [](int a, int b) { return ew[a] > ew[b]; });
  for (int x, y, i = 1; i < n; ++i) {
    fa[x = find(eu[Id[i]])] = y = find(ev[Id[i]]);
    for (int j : vec[x]) vec[y].push_back(j);
  }
  for (int i : vec[find(1)]) printf("%d ", i);
  return 0;
}
