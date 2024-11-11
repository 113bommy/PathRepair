#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<pair<int, int> > > graph(n + 1);
  for (int e = 1; e < n; e++) {
    int u, v;
    cin >> u >> v;
    graph[u].emplace_back(v, e);
    graph[v].emplace_back(u, e);
  }
  int maxDeg = 0;
  int root = 0;
  for (int i = 1; i <= n; i++) {
    if (graph[i].size() > maxDeg) maxDeg = graph[i].size(), root = i;
  }
  cout << maxDeg << '\n';
  vector<vector<int> > ans(maxDeg + 1);
  function<void(int, int, int)> dfs = [&](int u, int p, int day) {
    int add = 1;
    for (auto it : graph[u]) {
      int v = it.first;
      int id = it.second;
      if (v == p) continue;
      int nday = (day + add) % maxDeg;
      add++;
      ans[nday].push_back(id);
      dfs(v, u, nday);
    }
  };
  dfs(root, 0, 0);
  for (int i = 0; i < maxDeg; i++) {
    cout << ans[i].size() << " ";
    for (int x : ans[i]) cout << x << " ";
    cout << '\n';
  }
}
