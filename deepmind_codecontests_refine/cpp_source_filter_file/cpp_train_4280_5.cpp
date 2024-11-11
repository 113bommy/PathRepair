#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int MAX = 1e18, MIN = -1e18, MOD = 1000000007;
void dfs(int s, vector<int> adj[], vector<int>& vis) {
  vis[s] = 1;
  for (auto i : adj[s])
    if (!vis[i]) dfs(i, adj, vis);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, i, u, v, k = 0;
  cin >> n >> m;
  vector<int> adj[n + 1];
  vector<int> vis(n + 1, 0);
  for (i = 1; i <= m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, adj, vis);
  for (i = 1; i <= n; i++) {
    if (!vis[i]) {
      k = 1;
      break;
    }
  }
  if (k == 1 || n != m)
    cout << "NO";
  else
    cout << "FHTAGN";
  return 0;
}
