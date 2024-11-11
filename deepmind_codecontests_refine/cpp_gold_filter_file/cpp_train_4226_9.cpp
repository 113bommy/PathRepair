#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 7, M = 5e4 + 207, INF = 2e9 + 7, Lg = 9;
vector<int> adj[N];
vector<pair<int, int>> e;
set<pair<int, int>, greater<pair<int, int>>> st;
bool mark[N];
int from[M], to[M], s[M], g[M], d[N], par[Lg][N], mx[Lg][N];
int Max(int x, int y) { return (s[x] > s[y] ? x : y); }
void dfs(int p, int v, int w = M - 1) {
  par[0][v] = p;
  mark[v] = 1;
  for (int i = 1; i < Lg; i++) par[i][v] = par[i - 1][par[i - 1][v]];
  mx[0][v] = w;
  for (int i = 1; i < Lg; i++)
    mx[i][v] = Max(mx[i - 1][v], mx[i - 1][par[i - 1][v]]);
  for (auto i : adj[v]) {
    int u = from[i] + to[i] - v;
    if (mark[u] == 0) d[u] = d[v] + 1, dfs(v, u, i);
  }
}
int get_mx(int v, int k) {
  int mxi = M - 1;
  for (int i = 0; i < Lg; i++)
    if (k & (1 << i)) mxi = Max(mxi, mx[i][v]), v = par[i][v];
  return mxi;
}
int get_par(int v, int k) {
  for (int i = 0; i < Lg; i++)
    if (k & (1 << i)) v = par[i][v];
  return v;
}
int lca(int v, int u) {
  if (d[v] > d[u]) swap(u, v);
  u = get_par(u, d[u] - d[v]);
  if (u == v) return u;
  for (int i = Lg - 1; i >= 0; i--)
    if (par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
  return par[0][v];
}
int get_max(int u, int v) {
  int lc = lca(u, v);
  return Max(get_mx(u, d[u] - d[lc]), get_mx(v, d[v] - d[lc]));
}
void build() {
  for (int i = 0; i < N; i++) adj[i].clear();
  memset(mark, 0, sizeof mark);
  for (auto it : st) {
    int i = it.second;
    int u = from[i], v = to[i];
    adj[u].push_back(i);
    adj[v].push_back(i);
  }
  dfs(0, 0);
}
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int G, S;
  cin >> G >> S;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v >> g[i] >> s[i];
    u--;
    v--;
    e.push_back({g[i], i});
    from[i] = u, to[i] = v;
  }
  for (int j = 0; j < n - 1; j++) {
    int i = j + m;
    from[i] = j, to[i] = j + 1, g[i] = 0, s[i] = INF;
    st.insert({s[i], i});
  }
  build();
  sort(e.begin(), e.end());
  long long ans = 1ll * INF * INF;
  for (int i = 0; i < e.size(); i++) {
    int id = e[i].second;
    int u = from[id], v = to[id], si = s[id], gi = g[id];
    if (u == v) continue;
    int mxi = get_max(u, v);
    if (s[mxi] <= si) continue;
    st.erase({s[mxi], mxi});
    st.insert({si, id});
    assert(st.size() == n - 1);
    build();
    int Si = st.begin()->first;
    if (Si != INF) ans = min(ans, 1ll * G * g[id] + 1ll * S * Si);
  }
  if (ans == 1ll * INF * INF) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
