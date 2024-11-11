#include <bits/stdc++.h>
using namespace std;
vector<int> g[1000050];
vector<int> r[1000050];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    r[v].push_back(u);
  }
  vector<bool> ans(n + 1);
  vector<bool> vis(n + 1);
  int c = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      c++;
      ans[i] = true;
      for (int v : g[i]) {
        vis[v] = true;
      }
    }
  }
  for (int i = n; i > 0; i--) {
    if (ans[i]) {
      for (int u : r[i]) {
        if (ans[u]) {
          c--;
          ans[i] = false;
          break;
        }
      }
    }
  }
  cout << c << '\n';
  for (int i = 1; i <= n; i++) {
    if (ans[i]) cout << i << " ";
  }
  return 0;
}
