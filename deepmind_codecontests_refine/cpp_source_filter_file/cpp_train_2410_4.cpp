#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<int> par(n), c(n);
  int root = -1;
  for (int i = 0; i < n; i++) {
    cin >> par[i] >> c[i];
    if (par[i] == -1) {
      root = i;
      continue;
    }
    --par[i];
    g[par[i]].push_back(i);
  }
  vector<int> mark(n, 1);
  vector<int> ret;
  function<void(int)> Dfs = [&](int v) {
    if (c[v] == 0) mark[v] = 0;
    for (int u : g[v]) {
      if (c[u] == 0) mark[v] = 0;
      Dfs(u);
    }
  };
  Dfs(root);
  for (int i = 0; i < n; i++) {
    if (mark[i]) ret.push_back(i);
  }
  if (ret.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  sort(ret.begin(), ret.end());
  for (int v : ret) {
    cout << v << " ";
  }
  cout << '\n';
  return 0;
}
