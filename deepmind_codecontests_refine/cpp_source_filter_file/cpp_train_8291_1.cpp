#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
vector<int> g[N];
vector<int> cmp;
int par[N];
bool vis[N];
void dfs(int node) {
  vis[node] = true;
  cmp.push_back(node);
  for (int nxt : g[node]) {
    if (!vis[nxt]) dfs(nxt);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cmp.clear();
      dfs(i);
      int cnt = 1;
      for (int x : cmp) {
        if (g[x].size() == 2) cnt = 0;
      }
      if (cnt) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
