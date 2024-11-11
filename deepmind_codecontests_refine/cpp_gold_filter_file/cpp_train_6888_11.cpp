#include <bits/stdc++.h>
using namespace std;
struct AC {
  static const int MAX_N = 1e5 + 5;
  int n;
  map<int, map<int, int>> W;
  vector<int> G[MAX_N];
  vector<pair<int, int>> NG[MAX_N];
  vector<tuple<int, int, int>> ans;
  int root;
  void add_edge(int u, int v, int w) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
    W[u][v] = W[v][u] = w;
  }
  bool valid() {
    for (int i = 1; i <= n; i++)
      if (G[i].size() == 2)
        if (W[i][G[i][0]] != W[i][G[i][1]]) return false;
    return true;
  }
  void merge(int u, int v, int w) {
    ans.emplace_back(root, v, w);
    ans.emplace_back(root, u, -w);
  }
  void dfs(int pa, int now) {
    if (G[now].size() == 1) {
      NG[pa].emplace_back(now, W[pa][now]);
      return;
    }
    vector<pair<int, int>>& edge = NG[now];
    for (auto i : G[now])
      if (i != pa) dfs(now, i);
    while (edge.size() != 2) {
      merge(edge[0].first, edge.back().first, edge.back().second);
      edge[0].second += edge.back().second;
      edge.pop_back();
    }
    if (edge.size() == 2) {
      int d = (W[pa][now] - edge[0].second - edge[1].second) / 2;
      ans.emplace_back(edge[0].first, edge[1].first, -d);
      edge[0].second += d;
      edge[1].second += d;
      merge(edge[0].first, edge[1].first, edge[1].second);
      edge[0].second += edge[1].second;
      edge.pop_back();
    }
    NG[pa].emplace_back(edge[0]);
  }
  void solve() {
    if (!valid()) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    for (root = 1; G[root].size() != 1; root++)
      ;
    dfs(root, G[root][0]);
    for (auto i : NG[root]) ans.emplace_back(root, i.first, i.second);
  }
  void print() {
    if (ans.size() == 0) return;
    cout << ans.size() << '\n';
    for (auto& [u, v, w] : ans) cout << u << ' ' << v << ' ' << w << " \n";
  }
} solver;
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  solver.n = n;
  for (int i = 0, t1, t2, t3; i < n - 1; i++) {
    cin >> t1 >> t2 >> t3;
    solver.add_edge(t1, t2, t3);
  }
  solver.solve();
  solver.print();
  return 0;
}
