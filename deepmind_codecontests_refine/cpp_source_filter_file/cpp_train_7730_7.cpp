#include <bits/stdc++.h>
using namespace std;
long long read() {
  char ch = getchar();
  long long f = 1, x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
const long long maxn = 3e5 + 10;
long long n = 0, m = 0, k = 0, h[maxn] = {}, cnt = 0, low[maxn] = {},
          dfn[maxn] = {}, col[maxn] = {}, num[maxn] = {}, size[maxn] = {},
          d[maxn] = {}, tot = 0;
long long col_cnt = 0, time_cnt = 0, w[maxn] = {}, c[maxn] = {}, val[maxn] = {},
          spe[maxn] = {}, f[maxn] = {}, dp[maxn] = {};
vector<pair<long long, long long> > g[maxn];
bool vis[maxn] = {}, spec[maxn];
struct edge {
  long long v, w, next;
} e[maxn << 1];
void addedge(long long u, long long v, long long w) {
  e[++cnt].v = v;
  e[cnt].w = w;
  e[cnt].next = h[u];
  h[u] = cnt;
}
void insert(long long u, long long v, long long w) {
  addedge(u, v, w);
  addedge(v, u, w);
}
void dfs1(long long u, long long fa) {
  vis[u] = 1;
  low[u] = dfn[u] = ++time_cnt;
  long long sz = g[u].size();
  for (long long i = 0; i < sz; i++) {
    long long v = g[u][i].first;
    if (v != fa) {
      if (!vis[v]) {
        dfs1(v, u);
        low[u] = min(low[u], low[v]);
      } else {
        low[u] = min(low[u], dfn[v]);
      }
    }
  }
  d[++tot] = u;
}
void dfs2(long long u, long long fa) {
  col[u] = col_cnt;
  spe[col_cnt] += spec[u] ? 1 : 0;
  val[col_cnt] += c[u];
  long long sz = g[u].size();
  for (long long i = 0; i < sz; i++) {
    long long v = g[u][i].first;
    if (dfn[u] > dfn[v] || low[v] > dfn[u]) {
      continue;
    }
    if (!col[v]) {
      dfs2(v, u);
    }
  }
}
void tarjan() {
  dfs1(1, 0);
  for (long long i = n; i; i--) {
    if (!col[d[i]]) {
      col_cnt++;
      dfs2(d[i], 0);
    }
  }
  for (long long u = 1; u <= n; u++) {
    long long sz = g[u].size();
    for (long long i = 0; i < sz; i++) {
      long long v = g[u][i].first;
      if (u < v && col[u] != col[v]) {
        insert(col[u], col[v], w[g[u][i].second]);
      }
    }
  }
}
void dfs3(long long u, long long fa) {
  f[u] = val[u];
  size[u] = spe[u];
  for (long long i = h[u]; i; i = e[i].next) {
    long long v = e[i].v;
    if (v != fa) {
      dfs3(v, u);
      size[u] += size[v];
      if (size[v] == 0 || size[v] == k) {
        f[u] += f[v];
      } else {
        f[u] += max(0LL, f[v] - e[i].w);
      }
    }
  }
}
void dfs4(long long u, long long fa) {
  long long sum = 0;
  for (long long i = h[u]; i; i = e[i].next) {
    long long v = e[i].v;
    if (v != fa) {
      if (size[v] == k || size[v] == 0) {
        sum += f[v];
      } else {
        sum += max(0LL, f[v] - e[i].w);
      }
    }
  }
  for (long long i = h[u]; i; i = e[i].next) {
    long long v = e[i].v;
    if (v != fa) {
      dp[v] = val[v];
      if (size[v] == 0 || size[v] == k) {
        dp[v] += dp[u] + sum - f[v];
      } else {
        dp[v] += max(0LL, dp[u] + sum - max(0LL, f[v] - e[i].w) - e[i].w);
      }
      dfs4(v, u);
    }
  }
}
signed main() {
  n = read();
  m = read();
  k = read();
  for (long long i = 1; i <= k; i++) {
    spec[read()] = 1;
  }
  for (long long i = 1; i <= n; i++) {
    c[i] = read();
  }
  for (long long i = 1; i <= m; i++) {
    w[i] = read();
  }
  for (long long i = 1; i <= m; i++) {
    long long a = read(), b = read();
    g[a].push_back(make_pair(b, i));
    g[b].push_back(make_pair(a, i));
  }
  tarjan();
  dfs3(1, 0);
  dp[1] = val[1];
  dfs4(1, 0);
  for (long long i = 1; i <= n; i++) {
    printf("%d ", dp[col[i]] + f[col[i]] - val[col[i]]);
  }
  return 0;
}
