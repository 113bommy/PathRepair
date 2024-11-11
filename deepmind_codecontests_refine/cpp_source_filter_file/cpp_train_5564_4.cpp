#include <bits/stdc++.h>
using namespace std;
long long int n, m, k, w;
vector<vector<vector<char>>> mp;
struct dsu {
  vector<long long int> p, sz;
  dsu(long long int n) {
    p.resize(n);
    sz.resize(n, 1);
    for (long long int i = 0; i < n; i++) p[i] = i;
  }
  long long int getRoot(long long int v) {
    if (p[v] == v)
      return v;
    else
      return p[v] = getRoot(p[v]);
  }
  void unite(long long int a, long long int b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a != b) {
      if (sz[a] < sz[b]) swap(a, b);
      p[b] = a;
      sz[a] += sz[b];
    }
  }
  bool inOne(long long int a, long long int b) {
    a = getRoot(a);
    b = getRoot(b);
    return a == b;
  }
};
long long int getR(long long int a, long long int b) {
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      ans += (mp[a][i][j] != mp[b][i][j]);
    }
  }
  return ans;
}
struct edge {
  long long int a, b, w;
  edge(long long int a = 0, long long int b = 0, long long int w = 0) {
    this->a = a;
    this->b = b;
    this->w = w;
  }
};
bool cmp(const edge& a, const edge& b) { return a.w < b.w; }
vector<vector<long long int>> g;
vector<pair<long long int, long long int>> path;
void dfs(long long int v = 0, long long int p = -1) {
  if (p > -1) path.push_back({p, v});
  for (auto to : g[v]) {
    if (to == p) continue;
    dfs(to, v);
  }
}
signed main() {
  cin >> n >> m >> k >> w;
  mp.resize(k + 1, vector<vector<char>>(n, vector<char>(m)));
  g.resize(k + 1);
  for (long long int i = 1; i <= k; i++) {
    for (long long int j = 0; j < n; j++) {
      for (long long int w = 0; w < m; w++) cin >> mp[i][j][w];
    }
  }
  vector<edge> ed;
  for (long long int i = 1; i <= k; i++) ed.push_back(edge(0, i, n * m));
  for (long long int i = 1; i <= k; i++) {
    for (long long int j = i + 1; j <= k; j++)
      ed.push_back(edge(i, j, getR(i, j) * w));
  }
  sort(ed.begin(), ed.end(), cmp);
  dsu s(k + 1);
  long long int ans = 0;
  for (auto e : ed) {
    long long int a = e.a, b = e.b, w = e.w;
    if (s.inOne(a, b)) continue;
    ans += w;
    s.unite(a, b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs();
  cout << ans << "\n";
  for (auto i : path) cout << i.first << " " << i.second << "\n";
  return 0;
}
