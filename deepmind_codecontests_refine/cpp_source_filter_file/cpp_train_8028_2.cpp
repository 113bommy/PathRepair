#include <bits/stdc++.h>
using namespace std;
inline void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = (int)(2e5) + 5;
long long int a[N];
vector<int> adj[N];
int n, u, v;
long long int dp[N];
long long int l[N];
long long int a1 = 0;
long long int ans = 0;
void dfs(int u, int p) {
  l[u] = l[p] + 1;
  a1 += (l[u] * a[u]);
  dp[u] = a[u];
  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    dp[u] += dp[v];
  }
}
void dfs1(int u, int p) {
  ans = max(ans, a1);
  for (auto v : adj[u]) {
    if (v == p) continue;
    a1 -= dp[v];
    dp[u] -= dp[v];
    a1 += dp[u];
    dp[v] += dp[u];
    dfs1(v, u);
    dp[v] -= dp[u];
    a1 -= dp[u];
    dp[u] += dp[v];
    a1 -= dp[v];
  }
}
int main() {
  fast();
  cin >> n;
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  l[0] = -1;
  dfs(1, 0);
  ans = max(ans, a1);
  dfs1(1, 0);
  cout << ans;
}
