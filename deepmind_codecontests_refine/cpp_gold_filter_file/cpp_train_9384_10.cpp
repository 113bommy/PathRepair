#include <bits/stdc++.h>
using namespace std;
const long long maxn = 600005;
long long n, q;
vector<pair<long long, long long>> to[maxn];
vector<pair<long long, long long>> qry[maxn << 1];
struct edge {
  long long to, next;
  long long w1, w2;
} e[maxn * 2];
long long h[maxn], tot;
long long rt, T, beg, Siz, siz[maxn], mxsz[maxn], t[maxn];
long long d[maxn], f[maxn << 1][2], ans[maxn];
bool vis[maxn];
inline long long gi() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  long long sum = 0;
  while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return sum;
}
inline void add(long long u, long long v, long long w1, long long w2) {
  e[++tot] = (edge){v, h[u], w1, w2};
  h[u] = tot;
  e[++tot] = (edge){u, h[v], w1, w2};
  h[v] = tot;
}
void dijkstra() {
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      q;
  static bool vis[maxn];
  fill(vis + 1, vis + n + 1, 0);
  for (long long i = 1; i <= n; ++i) q.push(make_pair(d[i], i));
  while (!q.empty()) {
    long long u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto e : to[u]) {
      if (d[e.first] > d[u] + e.second) {
        d[e.first] = d[u] + e.second;
        q.push(make_pair(d[e.first], e.first));
      }
    }
  }
}
void get_rt(long long u, long long fa) {
  siz[u] = 1;
  mxsz[u] = 0;
  for (long long i = h[u], v; v = e[i].to, i; i = e[i].next)
    if (v != fa && !vis[v]) {
      get_rt(v, u);
      siz[u] += siz[v];
      if (mxsz[u] < siz[v]) mxsz[u] = siz[v];
    }
  mxsz[u] = max(mxsz[u], Siz - mxsz[u]);
  if (mxsz[u] < mxsz[rt]) rt = u;
}
void dfs(long long u, long long fa) {
  t[u] = T;
  for (long long i = h[u], v; v = e[i].to, i; i = e[i].next)
    if (v != fa && !vis[v]) {
      for (long long j = 0; j < 2; ++j) {
        f[v * 2 - 1][j] =
            min(f[u * 2 - 1][j] + e[i].w1, f[u * 2][j] + e[i].w2 + d[v]);
        f[v * 2][j] =
            min(f[u * 2 - 1][j] + e[i].w1 + d[v], f[u * 2][j] + e[i].w2);
      }
      dfs(v, u);
    }
  for (auto p : qry[u * 2 - 1]) {
    long long v = p.first / 2 + (p.first & 1);
    if (beg < t[v] && t[v] < T)
      ans[p.second] =
          min(f[u * 2 - 1][0] + f[p.first][0], f[u * 2 - 1][1] + f[p.first][1]);
  }
  for (auto p : qry[u * 2]) {
    long long v = p.first / 2 + (p.first & 1);
    if (beg < t[v] && t[v] < T)
      ans[p.second] =
          min(f[u * 2][0] + f[p.first][0], f[u * 2][1] + f[p.first][1]);
  }
}
void solve(long long u) {
  rt = 0;
  get_rt(u, 0);
  u = rt;
  vis[u] = 1;
  beg = T;
  f[u * 2 - 1][0] = f[u * 2][1] = 0;
  f[u * 2 - 1][1] = f[u * 2][0] = d[u];
  t[u] = ++T;
  for (long long i = h[u], v; v = e[i].to, i; i = e[i].next)
    if (!vis[v]) {
      for (long long j = 0; j < 2; ++j) {
        f[v * 2 - 1][j] =
            min(f[u * 2 - 1][j] + e[i].w1, f[u * 2][j] + e[i].w2 + d[v]);
        f[v * 2][j] =
            min(f[u * 2 - 1][j] + e[i].w1 + d[v], f[u * 2][j] + e[i].w2);
      }
      ++T, dfs(v, u);
    }
  for (long long i = h[u], v; v = e[i].to, i; i = e[i].next)
    if (!vis[v]) Siz = siz[v], solve(v);
}
signed main() {
  n = gi();
  for (long long i = 1; i <= n; ++i) {
    d[i] = gi();
    to[1].push_back(make_pair(i, d[i]));
  }
  long long w1, w2;
  for (long long u, v, i = 1; i < n; ++i) {
    u = gi();
    v = gi();
    w1 = gi();
    w2 = gi();
    add(u, v, w1, w2);
    to[u].push_back(make_pair(v, w1 + w2));
    to[v].push_back(make_pair(u, w1 + w2));
  }
  dijkstra();
  q = gi();
  for (long long u, v, i = 1; i <= q; ++i) {
    u = gi();
    v = gi();
    if (u / 2 + (u & 1) == v / 2 + (v & 1))
      ans[i] = u == v ? 0 : d[u / 2 + (u & 1)];
    else
      qry[u].push_back(make_pair(v, i)), qry[v].push_back(make_pair(u, i));
  }
  Siz = n;
  mxsz[0] = n + 1;
  solve(1);
  for (long long i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
