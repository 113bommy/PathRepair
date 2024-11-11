#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int sz = ceil(sqrt(n) + 1e-8);
    vector<int> depth(n + 1), parent(n + 1);
    vector<char> used(n + 1);
    vector<int> independent, cycle;
    bool done = false;
    function<void(int, int, int)> dfs = [&](int v, int pr, int dep) {
      parent[v] = pr;
      depth[v] = dep;
      int top = v;
      for (auto to : g[v]) {
        if (to != pr) {
          if (!depth[to]) {
            dfs(to, v, dep + 1);
          } else if (depth[to] < depth[top]) {
            top = to;
          }
        }
      }
      if (done) return;
      if (depth[v] - depth[top] + 1 >= sz) {
        done = true;
        cycle.push_back(v);
        while (cycle.back() != top) {
          cycle.push_back(parent[cycle.back()]);
        }
      } else {
        bool good = true;
        for (auto to : g[v]) {
          if (used[to]) {
            good = false;
          }
        }
        if (good) {
          used[v] = true;
          independent.push_back(v);
        }
      }
    };
    dfs(1, 0, 1);
    if (cycle.empty()) {
      cout << "1\n";
      for (int i = 0; i < sz; ++i) cout << independent[i] << " ";
    } else {
      cout << "2\n";
      cout << cycle.size() << "\n";
      for (auto e : cycle) cout << e << " ";
    }
    cout << "\n";
  }
}
