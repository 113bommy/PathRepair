#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;
vector<int64_t> keys;
vector<vector<int64_t>> g;
map<int64_t, vector<pair<int64_t, int64_t>>> store;
vector<int64_t> pow2((int64_t)5e5 + 1);
void dfs(int64_t v, map<int64_t, bool> &visited) {
  visited[v] = true;
  for (auto el : g[v]) {
    if (!visited.count(el)) {
      dfs(el, visited);
    }
  }
}
signed main() {
  pow2[0] = 1;
  for (int64_t i = 1; i < 5e5 + 1; i++) {
    pow2[i] = pow2[i - 1] * 2 % mod;
  }
  ios::sync_with_stdio(false);
  int64_t n, m;
  int64_t k;
  cin >> n >> m;
  cin >> k;
  keys.resize(n);
  g.resize(n);
  for (auto &el : keys) {
    cin >> el;
  }
  for (int64_t i = 0; i < m; ++i) {
    int64_t a, b;
    cin >> a >> b;
    a--, b--;
    store[(keys[a] ^ keys[b])].push_back({a, b});
  }
  int64_t ans = (pow2[k] - store.size()) * pow2[n];
  for (auto forbiddenKey : store) {
    set<int64_t> vertices;
    for (auto vertice : forbiddenKey.second) {
      vertices.insert(vertice.first);
      vertices.insert(vertice.second);
      g[vertice.first].push_back(vertice.second);
      g[vertice.second].push_back(vertice.first);
    }
    int64_t countCC = 0;
    map<int64_t, bool> visited;
    for (auto vertice : vertices) {
      if (!visited.count(vertice)) {
        dfs(vertice, visited);
        countCC++;
      }
    }
    ans += pow2[n - vertices.size() + countCC];
    ans %= mod;
    for (auto vertice : vertices) {
      g[vertice].clear();
    }
  }
  cout << ans;
  return 0;
}
