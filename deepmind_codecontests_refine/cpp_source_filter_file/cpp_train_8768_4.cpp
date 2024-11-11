#include <bits/stdc++.h>
using namespace std;
struct edge {
  int from, to;
  edge(int from, int to) : from(from), to(to) {}
};
using node = vector<edge>;
using graph = vector<node>;
void addedge(graph& g, int from, int to, bool bidirectional = false) {
  g[from].emplace_back(edge(from, to));
  if (bidirectional) g[to].emplace_back(edge(to, from));
}
class Solution {
 public:
  int n, k;
  vector<int> f;
  graph g;
  int dfs(int u = 0, int p = -1, int d = 0) {
    int ret = 0;
    for (auto e : g[u]) {
      if (p == e.to) continue;
      ret += dfs(e.to, u, d + 1);
    }
    f[u] = d - ret;
    return ret;
  }
  void solve() {
    cin >> n >> k;
    f = vector<int>(n);
    g = graph(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      addedge(g, u - 1, v - 1, true);
    }
    dfs();
    sort(f.begin(), f.end(), greater<int>());
    cout << accumulate(f.begin(), next(f.begin(), k), 0LL) << endl;
    return;
  };
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution solution;
  solution.solve();
  return 0;
}
