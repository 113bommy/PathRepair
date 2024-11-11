#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 79, logn = 18;
vector<vector<int> > l, p(maxn), son(maxn);
vector<int> depth(maxn, 0), val(maxn, 0);
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = logn - 1; i >= 0; i--)
    if (depth[l[i][u]] >= depth[v]) u = l[i][u];
  if (u == v) return u;
  for (int i = logn - 1; i >= 0; i--) {
    if (l[i][u] != l[i][v]) {
      u = l[i][u];
      v = l[i][v];
    }
  }
  return l[0][u];
}
void dfs(int v) {
  for (int i : son[v]) {
    dfs(i);
    val[v] += val[i];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, s;
  cin >> n >> m >> s;
  s--;
  l.assign(logn, vector<int>(maxn, s));
  vector<vector<pair<int, long long> > > g(n);
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    g[--u].push_back({--v, w});
    g[v].push_back({u, w});
  }
  vector<long long> d(n, 1e18);
  set<pair<long long, int> > q{{0, s}};
  while (!q.empty()) {
    auto v = *q.begin();
    q.erase(q.begin());
    int vr = v.second;
    if (d[vr] <= v.first) continue;
    d[vr] = v.first;
    for (pair<int, long long> i : g[vr]) {
      if (d[i.first] > d[vr] + i.second) q.insert({d[vr] + i.second, i.first});
    }
  }
  vector<pair<long long, int> > v;
  for (int i = 0; i < n; i++) v.push_back({d[i], i});
  sort(v.begin(), v.end());
  for (int i = 1; i < n; i++) {
    if (d[v[i].second] > 1e17) break;
    val[v[i].second] = 1;
    int lcaa = -1;
    for (pair<int, long long> j : g[v[i].second]) {
      if (d[v[i].second] == d[j.first] + j.second) {
        if (lcaa != -1)
          lcaa = lca(lcaa, j.first);
        else
          lcaa = j.first;
      }
    }
    l[0][v[i].second] = lcaa;
    depth[v[i].second] = depth[lcaa] + 1;
    for (int j = 1; j < logn; j++)
      l[j][v[i].second] = l[j - 1][l[j - 1][v[i].second]];
    son[lcaa].push_back(v[i].second);
  }
  dfs(s);
  val[s] = 0;
  cout << *max_element(val.begin(), val.end()) << "\n";
  return 0;
}
