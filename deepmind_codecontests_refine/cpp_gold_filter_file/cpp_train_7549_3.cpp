#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> toposort;
vector<bool> visited;
unordered_map<string, int> edges;
int n;
void clear() {
  for (int i = (0); i < (n); ++i) {
    g[i].clear();
    visited[i] = false;
  }
  toposort.clear();
}
void dfs(int v) {
  if (visited[v]) return;
  visited[v] = true;
  for (auto v2 : g[v]) {
    if (!visited[v2]) dfs(v2);
  }
  toposort.emplace_back(v);
}
string getKey(int a, int b) { return to_string(a) + "->" + to_string(b); }
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int m;
  cin >> n >> m;
  vector<pair<int, int>> u(m);
  g.resize(n);
  visited.resize(n);
  for (int i = (0); i < (m); ++i) {
    cin >> u[i].first >> u[i].second;
    u[i].first--;
    u[i].second--;
    edges.emplace(getKey(u[i].second, u[i].first), i);
  }
  int l = 1;
  int r = m;
  bool isValid;
  while (l <= r) {
    int k = l + ceil((r - l) * 0.5);
    clear();
    for (int i = (0); i < (k); ++i) {
      g[u[i].second].emplace_back(u[i].first);
    }
    for (int i = (0); i < (n); ++i) {
      if (!visited[i]) dfs(i);
    }
    reverse(toposort.begin(), toposort.end());
    isValid = toposort.size() == n;
    if (isValid) {
      for (int i = 0; i + 1 < n; i++) {
        auto key = getKey(toposort[i], toposort[i + 1]);
        if (edges.find(key) == edges.end() || edges[key] >= k) {
          isValid = false;
          break;
        }
      }
    }
    if (!isValid) {
      if (l == k) break;
      l = k;
    } else {
      if (r == k) break;
      r = k;
    }
  }
  if (!isValid) {
    cout << -1 << endl;
    return 0;
  }
  cout << r << endl;
  return 0;
}
