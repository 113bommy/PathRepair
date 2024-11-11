#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
struct disjoint_set {
  vector<int> parent;
  vector<int> rnk;
  int sz;
  disjoint_set(int n) : sz(n), parent(n), rnk(n, 0) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int u) {
    if (u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (rnk[u] > rnk[v])
      parent[v] = u;
    else
      parent[u] = v;
    if (rnk[u] == rnk[v]) ++rnk[v];
  }
  void compress() {
    for (int i = 0; i < sz; ++i) {
      find(i);
    }
  }
};
int impossible() {
  cout << -1 << '\n';
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  disjoint_set ds(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    ds.merge(a, b);
  }
  ds.compress();
  vector<vector<vector<int>>> team_sz(4);
  {
    vector<vector<int>> team(n);
    for (int i = 0; i < n; ++i) {
      team[ds.parent[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
      if (team[i].size() > 3) return impossible();
      team_sz[team[i].size()].push_back(team[i]);
    }
  }
  if (team_sz[2].size() > team_sz[1].size()) return impossible();
  for (vector<int> const& team : team_sz[3]) {
    for (int i : team) {
      cout << (i + 1) << ' ';
    }
    cout << '\n';
  }
  for (int i = 0; i < team_sz[2].size(); ++i) {
    for (int j : team_sz[1][i]) {
      cout << (j + 1) << ' ';
    }
    for (int j : team_sz[2][i]) {
      cout << (j + 1) << ' ';
    }
    cout << '\n';
  }
  for (int i = team_sz[2].size(); i < team_sz[1].size(); i += 3) {
    for (int j = i; j < i + 3; ++j) {
      cout << (team_sz[1][j].front() + 1) << ' ';
    }
    cout << '\n';
  }
  return 0;
}
