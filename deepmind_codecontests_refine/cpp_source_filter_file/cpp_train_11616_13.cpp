#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 5001;
long long int powxy(long long int x, long long int y) {
  if (y == 0) return 1;
  if (y % 2 == 1) return (x * powxy(x, y - 1)) % mod;
  long long int t = powxy(x, y / 2) % mod;
  return (t * t) % mod;
}
vector<int> adj[300005];
long long int sum[300005];
long long int dp[300005];
int cost[300005];
long long int ans = -1e15;
void solve(int node, int par) {
  sum[node] = cost[node];
  long long int max1 = -1e15;
  long long int max2 = -1e15;
  for (int to : adj[node]) {
    if (to == par) continue;
    solve(to, node);
    sum[node] += sum[to];
  }
  dp[node] = sum[node];
  for (int to : adj[node]) {
    if (to == par) continue;
    dp[node] = max(dp[node], dp[to]);
  }
  for (int to : adj[node]) {
    if (to == par) continue;
    if (dp[to] > max1) {
      max2 = max1;
      max1 = dp[to];
    } else if (dp[to] > max2)
      max2 = dp[to];
  }
  if (max2 != -1e15) ans = max(ans, max1 + max2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> cost[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  solve(1, 0);
  if (ans != 1e15)
    cout << ans;
  else
    cout << "Impossible";
}
