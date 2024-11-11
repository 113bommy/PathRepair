#include <bits/stdc++.h>
using namespace std;
const long long N = 400005;
int ec = 0, nxt[N << 1], to[N << 1], hed[N] = {0};
void add_edge(long long f, long long t) {
  ++ec;
  to[ec] = t;
  nxt[ec] = hed[f];
  hed[f] = ec;
}
struct edge {
  long long u, v, col, w;
} e[N];
vector<long long> V[N];
long long n, m, val[2][N];
map<long long, long long> vis;
long long prep() {
  for (long long v, u = 1; u <= n; u++) {
    long long cnt = 0;
    vis.clear();
    for (long long i = 0; i < V[u].size(); i++) {
      if (vis[e[V[u][i]].col]) {
        val[0][u] = vis[e[V[u][i]].col];
        val[1][u] = V[u][i];
        cnt++;
      }
      vis[e[V[u][i]].col] = V[u][i];
    }
    if (cnt >= 2) return 1;
  }
  return 0;
}
long long dfn[N], low[N], dfc = 0;
long long stk[N], tp = 0;
long long scc[N], scn = 0;
void tarjan(long long u) {
  dfn[u] = low[u] = ++dfc;
  stk[++tp] = u;
  for (long long i = hed[u]; i; i = nxt[i]) {
    long long v = to[i];
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (!scc[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (low[u] == dfn[u]) {
    scn++;
    while (1) {
      scc[stk[tp]] = scn;
      if (stk[tp] == u) break;
      tp--;
    }
    tp--;
  }
}
long long chk(long long x) {
  long long tot = m + m;
  dfc = 0;
  memset(dfn, 0, sizeof(dfn));
  memset(hed, 0, sizeof(hed));
  ec = 0;
  memset(scc, 0, sizeof(scc));
  tp = 0;
  scn = 0;
  for (long long v, u = 1; u <= n; u++) {
    long long s, t, ls, lt;
    if (val[0][u]) {
      add_edge(val[0][u], val[1][u] + m);
      add_edge(val[1][u], val[0][u] + m);
    }
    for (long long i = 0; i < V[u].size(); i++) {
      v = V[u][i];
      s = ++tot;
      t = ++tot;
      add_edge(s, v);
      add_edge(v + m, t);
      if (i) {
        add_edge(s, ls);
        add_edge(lt, t);
        add_edge(v + m, ls);
        add_edge(lt, v);
      }
      ls = s;
      lt = t;
    }
  }
  for (long long i = 1; i <= m; i++)
    if (e[i].w > x) add_edge(i + m, i);
  for (long long i = 1; i <= tot + (m << 1); i++)
    if (!dfn[i]) tarjan(i);
  for (long long i = 1; i <= m; i++)
    if (scc[i] == scc[i + m]) return 0;
  return 1;
}
bool cmp(long long x, long long y) { return e[x].col < e[y].col; }
int main() {
  ios::sync_with_stdio(false);
  long long l = 1, r = 0, mid, ans = -1;
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].col >> e[i].w;
    V[e[i].u].push_back(i);
    V[e[i].v].push_back(i);
    r = max(r, e[i].w);
  }
  for (long long i = 1; i <= n; i++) sort(V[i].begin(), V[i].end(), cmp);
  if (prep()) {
    cout << "No\n";
    return 0;
  }
  while (l <= r) {
    mid = (l + r) >> 1;
    if (chk(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if (ans == -1) {
    cout << "No\n";
    return 0;
  }
  chk(ans);
  cout << "Yes\n";
  dfc = 0;
  for (long long i = 1; i <= m; i++)
    if (scc[i] > scc[i + m]) dfc++;
  cout << ans << ' ' << dfc << '\n';
  for (long long i = 1; i <= m; i++)
    if (scc[i] > scc[i + m]) cout << i << ' ';
  cout << '\n';
  return 0;
}
