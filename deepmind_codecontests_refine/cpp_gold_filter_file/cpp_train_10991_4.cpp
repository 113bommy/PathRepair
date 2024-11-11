#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e18;
int n, m, k;
vector<vector<int>> g, ans;
vector<bool> used;
queue<pair<int, int>> q;
void dfs(int u) {
  ans[q.front().first].push_back(u);
  q.front().second--;
  if (!q.front().second) q.pop();
  for (auto v : g[u]) {
    if (!used[v]) {
      used[v] = true;
      dfs(v);
      ans[q.front().first].push_back(u);
      q.front().second--;
      if (!q.front().second) {
        q.pop();
      }
    }
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  int u, v;
  used.resize(n, false);
  g.resize(n);
  ans.resize(k);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < k; i++) {
    q.push({i, (2 * n + k - 1) / k});
  }
  used[0] = true;
  dfs(0);
  if (!q.empty() && q.front().second != (2 * n + k - 1) / k) {
    q.pop();
  }
  while (!q.empty()) {
    ans[q.front().first].push_back(0);
    q.pop();
  }
  for (int i = 0; i < k; i++) {
    cout << ans[i].size() << " ";
    for (auto x : ans[i]) {
      cout << x + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
