#include <bits/stdc++.h>
using namespace std;
int vis[100010], cnt;
vector<int> adj[100010];
void dfs(int u) {
  vis[u] = 1;
  cnt++;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (!vis[v]) dfs(v);
  }
  return;
}
int main() {
  int n, m, comp;
  long long mod, ans;
  cin >> n >> m >> mod;
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(vis, 0, sizeof(vis));
  comp = 0;
  ans = 1LL;
  for (int i = 0; i < n; i++)
    if (!vis[i]) {
      comp++;
      cnt = 0;
      dfs(i);
      ans = (ans * (long long)(cnt)) % mod;
    }
  for (int i = 0; i < comp - 2; i++) ans = (ans * (long long)(n)) % mod;
  cout << (comp == 1 % mod ? 1 : ans) << endl;
  return 0;
}
