#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int> > G(n + 1, vector<int>());
  vector<int> d(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if (n != m + 1)
    cout << "no\n";
  else {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (d[u]) continue;
      d[u] = 1;
      for (int v : G[u]) q.push(v);
    }
    bool t = true;
    for (int i = 1; i <= n; ++i) {
      if (d[i] == 0) t = false;
    }
    if (t)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}
