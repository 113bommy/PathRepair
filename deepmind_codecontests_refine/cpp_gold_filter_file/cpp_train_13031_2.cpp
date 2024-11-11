#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(n + 1);
  vector<int> vis(n + 1, false);
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  function<void(int)> dfs = [&](int v) {
    vis[v] = true;
    for (auto u : adj[v])
      if (!vis[u]) dfs(u);
  };
  int comp = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == false) {
      dfs(i);
      comp++;
    }
  }
  cout << k - n + comp << endl;
  return 0;
}
