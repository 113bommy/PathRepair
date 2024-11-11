#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
const int N = 299;
vector<int> adj[N], dislike[N];
bool vis[N];
vector<int> V;
int ans = 0, group = 0;
void dfs(int u) {
  vis[u] = 1;
  ++group;
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
  for (int v : dislike[u]) {
    if (vis[v]) group = -1e9;
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    int u, v;
    cin >> u >> v;
    dislike[u].push_back(v);
    dislike[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    dfs(i);
    ans = max(ans, group);
    group = 0;
    memset(vis, 0, sizeof(vis));
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
