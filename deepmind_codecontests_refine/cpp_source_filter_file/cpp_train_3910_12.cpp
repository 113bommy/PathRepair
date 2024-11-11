#include <bits/stdc++.h>
using namespace std;
bool u[200001];
vector<int> adj[200001];
int n, k, ans, s[200001];
void dfs(int v = 1, int p = 1) {
  if (u[v]) s[v]++;
  for (auto u : adj[v]) {
    if (u == p) continue;
    dfs(u, v);
    s[v] += s[u];
    ans += s[u] < 2 * k - s[u] ? s[u] : 2 * k - s[u];
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= 2 * k; i++) {
    int y;
    cin >> y;
    u[y] = true;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs();
  cout << ans;
  return 0;
}
