#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100004], vis(1e5 + 5), depth(1e5 + 5);
long long ans = 0;
int dfs(int c) {
  vis[c] = 1;
  long long k, mx1 = 0, mx2 = 0;
  for (auto it : adj[c]) {
    if (!vis[it]) {
      k = 1 + dfs(it);
      if (k > mx1) {
        mx2 = mx1;
        mx1 = k;
      } else if (k > mx2) {
        mx2 = k;
      }
      ans = max(ans, mx2 + mx1);
      depth[c] = mx1;
    }
  }
  return depth[c];
}
int main() {
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[i].push_back(a);
    adj[a].push_back(i);
  }
  dfs(1);
  cout << ans;
  return 0;
}
