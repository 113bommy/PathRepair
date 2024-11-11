#include <bits/stdc++.h>
using namespace std;
vector<int> adj[2345];
bool vis[2345];
void dfs(int u) {
  for (int i = 0; i < adj[u].size(); i++) {
    if (!vis[adj[u][i]]) {
      vis[adj[u][i]] = true;
      dfs(adj[u][i]);
    }
  }
}
int main() {
  long long n, m, k;
  long long M = 1000000007;
  cin >> n >> m >> k;
  for (int i = 0; i <= n - k + 1; i++) {
    int l = i, r = i + k - 1;
    while (l <= r) {
      adj[l].push_back(r);
      adj[r].push_back(l);
      l++;
      r--;
    }
  }
  long long cc = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cc++;
      dfs(i);
    }
  }
  if (k > n) cc = n;
  long long ans = 1;
  for (int i = 0; i < cc; i++) {
    ans = (ans * m) % M;
  }
  cout << ans << endl;
  return 0;
}
