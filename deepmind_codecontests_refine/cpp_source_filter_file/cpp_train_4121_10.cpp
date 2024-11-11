#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
vector<long long int> adj[32];
long long int vis[32];
pair<long long int, long long int> ans[32];
long long int dx[] = {0, 1, 0, -1};
long long int dy[] = {1, 0, -1, 0};
void dfs(long long int node, long long int x, long long int y,
         long long int dis, long long int d) {
  vis[node] = 1;
  long long int cnt = 1;
  ans[node] = pair<long long int, long long int>(x, y);
  for (auto child : adj[node]) {
    if (!vis[child]) {
      long long int z = (cnt + d) % 4;
      dfs(child, x + dx[z] * dis, y + dy[z] * dis, dis - 10000, (z + 2) % 4);
      cnt++;
    }
  }
}
void solve() {
  long long int n;
  cin >> n;
  memset(vis, 0, sizeof(vis));
  for (long long int i = 1; i <= n - 1; i++) {
    long long int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (auto i = 1; i <= n; i++) {
    if (adj[i].size() > 4) {
      cout << "NO\n";
      return;
    }
  }
  dfs(1, 0, 0, 1e16, 0);
  cout << "YES\n";
  for (long long int k = 1; k <= n; k++) {
    cout << ans[k].first << " " << ans[k].second << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
