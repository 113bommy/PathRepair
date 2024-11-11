#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int res;
int dfs(int u, int p) {
  int maxi = 0;
  vector<int> t;
  for (auto& v : adj[u])
    if (v != p) t.push_back(dfs(v, u));
  sort(t.begin(), t.end(), greater<int>());
  int a = (t.size() > 0) ? t[0] : 0;
  int b = (t.size() > 1) ? t[1] : 0;
  res = max(res, int(a + b + adj[u].size() - (a > 0) - (b > 0) + 1));
  return a + adj[u].size() - (a > 0);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    res = 0;
    adj.clear();
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << res;
  }
}
