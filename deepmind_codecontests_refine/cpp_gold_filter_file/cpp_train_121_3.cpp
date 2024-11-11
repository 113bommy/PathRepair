#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long n, m, k, p, dis[maxn], par[maxn], dsu[maxn], ans[maxn];
bool vis[maxn];
vector<pair<long long, pair<long long, long long> > > e;
vector<pair<long long, long long> > g[maxn], vec[maxn];
vector<long long> a[maxn];
priority_queue<pair<long long, long long> > q;
void init() {
  for (long long i = 1; i <= k; i++) {
    dsu[i] = i;
    a[i].push_back(i);
  }
  return;
}
void Union(long long v, long long u, long long c) {
  long long x, y;
  v = dsu[v];
  u = dsu[u];
  if (v == u) return;
  if (a[v].size() < a[u].size()) swap(v, u);
  for (long long i = 0; i < a[u].size(); i++) {
    x = a[u][i];
    a[v].push_back(x);
    dsu[x] = v;
    for (long long j = 0; j < vec[x].size(); j++) {
      y = vec[x][j].first;
      if (dsu[y] == dsu[x]) {
        ans[vec[x][j].second] = min(ans[vec[x][j].second], c);
      }
    }
  }
  return;
}
int main() {
  long long v, u, c;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k >> p;
  for (long long i = 0; i < m; i++) {
    cin >> v >> u >> c;
    g[v].push_back({u, c});
    g[u].push_back({v, c});
  }
  for (long long i = 0; i < p; i++) {
    cin >> v >> u;
    vec[v].push_back({u, i});
    vec[u].push_back({v, i});
    ans[i] = inf;
  }
  fill(dis, dis + maxn, inf);
  for (long long i = 1; i <= k; i++) {
    dis[i] = 0;
    par[i] = i;
    q.push({-dis[i], i});
  }
  while (!q.empty()) {
    v = q.top().second;
    q.pop();
    if (vis[v]) continue;
    for (long long i = 0; i < g[v].size(); i++) {
      u = g[v][i].first;
      c = g[v][i].second;
      if (dis[u] > dis[v] + c) {
        dis[u] = dis[v] + c;
        par[u] = par[v];
        q.push({-dis[u], u});
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < g[i].size(); j++) {
      u = g[i][j].first;
      c = g[i][j].second;
      if (u > i && par[i] != par[u]) {
        e.push_back({dis[i] + c + dis[u], {par[i], par[u]}});
      }
    }
  }
  init();
  sort(e.begin(), e.end());
  for (long long i = 0; i < e.size(); i++) {
    c = e[i].first;
    v = e[i].second.first;
    u = e[i].second.second;
    Union(v, u, c);
  }
  for (long long i = 0; i < p; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
