#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, u, v, count = INT_MAX;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  unordered_map<int, unordered_set<int>> mp;
  vector<int> in(n + 1, 0);
  while (m--) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    mp[u].insert(v);
    mp[v].insert(u);
    in[u]++;
    in[v]++;
  }
  for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
  for (int i = 1; i <= n; i++)
    if (in[i] > 1) {
      int lo = 0, hi = g[i].size() - 1;
      while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (g[i][mid] > i)
          hi = mid;
        else
          lo = mid + 1;
      }
      for (int j = lo; j < g[i].size(); j++)
        for (int k = j + 1; k < g[i].size(); k++)
          if (mp[g[i][j]].find(g[i][k]) != mp[g[i][j]].end()) {
            count = min(count, in[i] + in[g[i][j]] + in[g[i][k]] - 6);
          }
    }
  if (count < n)
    cout << count;
  else
    cout << -1;
  return 0;
}
