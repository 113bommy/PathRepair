#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int maxn = 300000 + 10;
const long long inf = 2LL * (1e18);
struct Edge {
  int from, to, w;
  Edge() { from = to = w = 0; }
  Edge(int f, int t, int ww) : from(w), to(t), w(ww) {}
};
vector<Edge> G[maxn];
long long dp[maxn][4];
int tot[maxn], sp[maxn];
int n, m, k, ecc_cnt, dfn;
int issp[maxn], c[maxn], pre[maxn], w[maxn], low[maxn];
int co[maxn];
vector<int> ecc[maxn];
vector<Edge> g[maxn];
long long ans[maxn];
stack<int> S;
vector<long long> dt[maxn][4];
void dfs(int u, int fa) {
  low[u] = pre[u] = ++dfn;
  S.push(u);
  for (auto e : G[u]) {
    if (e.to == fa) continue;
    if (pre[e.to] == 0) {
      dfs(e.to, u);
    }
    low[u] = min(low[e.to], low[u]);
  }
  if (low[u] == pre[u]) {
    ecc_cnt++;
    ecc[ecc_cnt].clear();
    ecc[ecc_cnt].push_back(u);
    co[u] = ecc_cnt;
    for (; S.top() != u;) {
      co[S.top()] = ecc_cnt;
      ecc[ecc_cnt].push_back(S.top());
      S.pop();
    }
    S.pop();
  }
}
inline void find_ecc() {
  dfs(1, 0);
  for (auto i = (1); i <= (n); ++i) assert(pre[i] != 0);
}
inline void build() {
  for (auto i = (1); i <= (n); ++i) {
    for (auto e : G[i]) {
      if (co[i] != co[e.to]) {
        g[co[i]].push_back({co[i], co[e.to], e.w});
      }
    }
  }
  for (auto i = (1); i <= (ecc_cnt); ++i) {
    for (auto e : ecc[i]) sp[i] += issp[e];
  }
}
void dfs_tree(int u, int fa) {
  tot[u] = sp[u];
  for (auto e : g[u]) {
    if (fa == e.to) continue;
    dfs_tree(e.to, u);
    tot[u] += tot[e.to];
  }
  long long sumc = 0;
  for (auto e : ecc[u]) sumc += c[e];
  dp[u][1] = sumc;
  dp[u][3] = sumc;
  for (auto e : g[u]) {
    if (fa == e.to) continue;
    long long val = max({dp[e.to][1], dp[e.to][2], dp[e.to][3]});
    long long cost = 0;
    if (tot[e.to] < k && tot[e.to] > 0) {
      cost += e.w;
    }
    dp[u][2] += max(val - cost, 0LL);
    dt[u][2].push_back(max(val - cost, 0LL));
    dp[u][3] += max(val - cost, 0LL);
    dt[u][3].push_back(max(val - cost, 0LL));
  }
}
void Dp(int u, int fa) {
  for (auto e : ecc[u]) ans[e] = max({dp[u][1], dp[u][3]});
  int idx = 0;
  for (auto e : g[u]) {
    if (e.to == fa) continue;
    int v = e.to;
    long long dpu[4], totu, totv, dpv[4], val, cost;
    for (auto i = (0); i < (4); ++i) dpu[i] = dp[u][i];
    for (auto i = (0); i < (4); ++i) dpv[i] = dp[v][i];
    totu = tot[u], totv = tot[v];
    if (tot[v] < k && tot[v] > 0) {
      cost = e.w;
    } else
      cost = 0;
    val = max({dp[v][1], dp[v][2], dp[v][3]});
    dp[u][2] -= max(val - cost, 0LL);
    if (tot[v] < k && tot[v] > 0) {
      cost = e.w;
    } else
      cost = 0;
    tot[u] -= tot[v];
    tot[v] += tot[u];
    dp[u][3] -= max(val - cost, 0LL);
    val = max({dp[u][1], dp[u][2], dp[u][3]});
    if (tot[u] < k && tot[u] > 0) {
      cost = e.w;
    } else
      cost = 0;
    dp[v][2] += max(val - cost, 0LL);
    dp[v][3] += max(val - cost, 0LL);
    Dp(v, u);
    for (auto i = (0); i < (4); ++i) {
      dp[u][i] = dpu[i];
      dp[v][i] = dpv[i];
    }
    tot[u] = totu, tot[v] = totv;
    idx++;
  }
}
inline void init() {
  find_ecc();
  build();
}
inline void solve() {
  init();
  dfs_tree(1, 0);
  Dp(1, 0);
  for (auto i = (1); i <= (n); ++i) {
    printf("%lld ", ans[i]);
  }
  puts("");
}
int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  for (auto i = (1); i <= (k); ++i) {
    int x;
    scanf("%d", &(x));
    issp[x]++;
  }
  for (auto i = (1); i <= (n); ++i) scanf("%d", &(c[i]));
  for (auto i = (1); i <= (m); ++i) scanf("%d", &(w[i]));
  for (auto i = (1); i <= (m); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(Edge(u, v, w[i]));
    G[v].push_back(Edge(v, u, w[i]));
  }
  solve();
  return 0;
}
