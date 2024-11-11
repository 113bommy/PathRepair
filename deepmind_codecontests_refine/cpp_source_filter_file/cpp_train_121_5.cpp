#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const long long oo = 1e18;
int n, e, k, Q;
vector<vector<pair<int, int> > > g;
int p[N];
int find(int u) {
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}
pair<int, long long> dp[17][N];
long long mx[N];
int d[N];
void DFS(int u, int p) {
  for (auto e : g[u]) {
    if (e.first == p) continue;
    dp[0][e.first] = {u, e.second};
    d[e.first] = d[u] + 1;
    DFS(e.first, u);
  }
}
long long calc(int u, int v) {
  if (d[u] < d[v]) swap(u, v);
  int l = 0;
  while ((1 << l) <= d[u]) ++l;
  --l;
  long long res = 0;
  for (int i = l; i >= 0; --i)
    if (d[u] - (1 << i) >= d[v]) {
      res = max(res, dp[i][u].second);
      u = dp[i][u].first;
    }
  if (u == v) return res;
  for (int i = l; i >= 0; --i)
    if (dp[i][u].first != dp[i][v].first) {
      res = max(res, dp[i][u].second);
      res = max(res, dp[i][v].second);
      u = dp[i][u].first;
      v = dp[i][v].first;
    }
  res = max(res, dp[0][u].second);
  res = max(res, dp[0][v].second);
  return res;
}
int main() {
  scanf("%d%d%d%d", &n, &e, &k, &Q);
  g.resize(n);
  for (int a, b, c, i = 0; i < e; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    g[a].push_back({b, c});
    swap(a, b);
    g[a].push_back({b, c});
  }
  vector<long long> cost(k);
  cost.resize(n, oo);
  vector<bool> vis(n);
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      q;
  for (int i = 0; i < k; ++i) q.push({0, i});
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto e : g[u])
      if (cost[e.first] > cost[u] + e.second) {
        cost[e.first] = cost[u] + e.second;
        q.push({cost[e.first], e.first});
      }
  }
  vector<pair<long long, pair<int, int> > > edges;
  for (int u = 0; u < n; ++u)
    for (auto e : g[u]) {
      int v = e.first;
      edges.push_back({cost[u] + cost[v] + e.second, {u, v}});
    }
  sort(edges.begin(), edges.end());
  g.clear();
  g.resize(n);
  for (int i = 0; i < n; ++i) p[i] = i;
  for (auto e : edges) {
    int u = e.second.first;
    int v = e.second.second;
    if (find(u) != find(v)) {
      g[u].push_back({v, e.first});
      g[v].push_back({u, e.first});
      p[find(u)] = find(v);
    }
  }
  memset(dp, -1, sizeof(dp));
  DFS(0, -1);
  for (int k = 1; k < 17; ++k)
    for (int i = 0; i < n; ++i)
      if (dp[k - 1][i].first != -1) {
        dp[k][i].first = dp[k - 1][dp[k - 1][i].first].first;
        dp[k][i].second =
            max(dp[k - 1][i].second, dp[k - 1][dp[k - 1][i].first].second);
      }
  while (Q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u;
    --v;
    printf("%lld\n", calc(u, v));
  }
  return 0;
}
