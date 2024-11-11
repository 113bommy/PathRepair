#include <bits/stdc++.h>
using namespace std;
long long int dp[300][300];
vector<long long int> adj[300];
long long int arr[300];
long long int n, k;
void dfs(long long int node, long long int pr) {
  for (auto to : adj[node])
    if (to != pr) dfs(to, node);
  dp[node][0] = arr[node];
  for (long long int i = 0; i <= n - 1; i++) {
    if (i == 0) {
      for (auto to : adj[node])
        if (to != pr) dp[node][0] += dp[to][k];
    } else {
      for (auto to : adj[node]) {
        if (to != pr) {
          long long int ret = dp[to][i - 1];
          for (auto too : adj[node]) {
            if (too != pr && to != too) {
              ret += dp[too][max(i, k - i)];
            }
          }
          dp[node][i] = max(dp[node][i], ret);
        }
      }
    }
  }
  for (long long int i = n - 1; i >= 0; i--)
    dp[node][i] = max(dp[node][i], dp[node][i + 1]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int TESTS, q, a, s, m, b, r, c, p, w, d, x, i, j, y, z, xs, ys, t;
  memset(dp, 0, sizeof(dp));
  TESTS = 1;
  while (TESTS--) {
    cin >> n >> k;
    for (long long int i = 0; i <= n - 1; i++) cin >> arr[i];
    for (long long int i = 0; i <= n - 2; i++) {
      cin >> a >> b;
      a--;
      b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << dp[0][0];
  }
  return 0;
}
