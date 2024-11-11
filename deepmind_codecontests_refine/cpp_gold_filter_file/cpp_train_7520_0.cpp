#include <bits/stdc++.h>
using namespace std;
vector<int> a, b, c, mini;
vector<vector<int>> g;
long long int cost;
pair<int, int> dfs(int curr, int par, int m) {
  pair<int, int> p = {0, 0};
  if (b[curr] != c[curr]) {
    p.first += (b[curr] == 0);
    p.second += (b[curr] == 1);
  }
  for (int i = 0; i < g[curr].size(); i++) {
    int s = g[curr][i];
    if (s == par) continue;
    int mn = min(m, a[curr]);
    pair<int, int> a = dfs(s, curr, mn);
    p.first += a.first;
    p.second += a.second;
  }
  if (m > a[curr]) {
    int solved = min(p.first, p.second);
    p.first -= solved;
    p.second -= solved;
    cost += solved * 2LL * a[curr];
  }
  return p;
}
int main() {
  int n;
  cin >> n;
  a.resize(n + 1), b.resize(n + 1), c.resize(n + 1);
  cost = 0;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  a[0] = INT_MAX;
  pair<int, int> p = dfs(1, 0, INT_MAX);
  if (!p.first && !p.second)
    cout << cost << endl;
  else
    cout << -1 << endl;
  return 0;
}
