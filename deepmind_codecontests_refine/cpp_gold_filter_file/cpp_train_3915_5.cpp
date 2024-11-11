#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &g, vector<int> &d, int x) {
  vector<bool> visited(g.size());
  vector<pair<int, int>> s = {{x, 0}};
  visited[x] = true;
  int u, v, index;
  while (!s.empty()) {
    u = s.back().first;
    index = s.back().second;
    if (!visited[g[u][index]]) {
      s.emplace_back(g[u][index], 0);
      visited[g[u][index]] = true;
      d[g[u][index]] = d[u] + 1;
    } else if (index + 1 < g[u].size()) {
      ++s.back().second;
    } else {
      s.pop_back();
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  --x;
  vector<vector<int>> g(n, vector<int>());
  int u, v;
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> dx(n);
  vector<int> d(n);
  dfs(g, dx, x);
  dfs(g, d, 0);
  int answ = 2 * dx[0];
  for (int i = 0; i < n; ++i) {
    if (dx[i] < d[i]) {
      answ = max(2 * d[i], answ);
    }
  }
  cout << answ << '\n';
  return 0;
}
