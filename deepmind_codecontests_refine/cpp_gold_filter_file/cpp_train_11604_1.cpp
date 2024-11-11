#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100050];
int b[100050];
long long dp[100050][2];
const int m = 1e9 + 7;
void dfs(int v, int p) {
  long long old[2] = {0};
  dp[v][0] = 1 - b[v];
  dp[v][1] = b[v];
  for (auto u : adj[v]) {
    if (u == p) continue;
    old[0] = dp[v][0];
    old[1] = dp[v][1];
    dp[v][0] = 0, dp[v][1] = 0;
    dfs(u, v);
    dp[v][0] += (dp[u][1] * old[0]) % m;
    dp[v][1] += (dp[u][1] * old[1]) % m;
    dp[v][1] += (old[1] * dp[u][0]) % m;
    dp[v][1] += (old[0] * dp[u][1]) % m;
    dp[v][0] += (old[0] * dp[u][0]) % m;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int(i) = 0; (i) < (n - 1); (i)++) {
    int a;
    scanf("%d", &a);
    adj[a + 1].push_back(i + 2);
    adj[i + 2].push_back(a + 1);
  }
  for (int(i) = 0; (i) < (n); (i)++) scanf("%d", &b[i + 1]);
  dfs(1, 0);
  cout << dp[1][1] % m;
  return 0;
}
