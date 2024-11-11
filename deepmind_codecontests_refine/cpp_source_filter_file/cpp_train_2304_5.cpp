#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, K = 201, MOD = 1e9 + 7, inv2 = 5e8 + 4;
int n, k, s[N];
long long dp[N][K], old[K], a[K], f[N], g[K], binom[K][K];
bool seen[N];
vector<int> G[N];
void DFS(int u) {
  seen[u] = true;
  s[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!seen[v]) {
      DFS(v);
      s[u] += s[v];
    } else {
      G[u][i] = G[u].back();
      G[u].pop_back();
      i--;
    }
  }
}
void solve(int u) {
  dp[u][0] = 1;
  int e = 0;
  for (int v : G[u]) {
    solve(v);
    for (int i = 0; i <= min(e, k); i++) {
      old[i] = dp[u][i];
      dp[u][i] = 0;
    }
    for (int i = 0; i <= min(e, k); i++)
      for (int j = 0; j <= min(s[v], k); j++)
        dp[u][i + j] = (dp[u][i + j] + old[i] * dp[v][j]) % MOD;
    e += s[v];
  }
  for (int i = 1; i <= min(s[u] - 1, k); i++) {
    a[i] += dp[u][i];
    if (a[i] >= MOD) a[i] -= MOD;
  }
  for (int v : G[u]) {
    for (int i = 1; i <= min(s[v], k); i++) {
      a[i] += MOD - dp[v][i];
      if (a[i] >= MOD) a[i] -= MOD;
    }
  }
  if (u == 0) return;
  for (int i = min(s[u], k); 1 <= i; i--) {
    long long x = (i == 1 ? f[s[u]] : dp[u][i - 1]);
    a[i] = (a[i] + x * f[n - s[u]]) % MOD;
    dp[u][i] += x;
    if (dp[u][i] >= MOD) dp[u][i] -= MOD;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  DFS(0);
  long long ipow2 = 1;
  for (int i = 1; i < n; i++) {
    ipow2 = (ipow2 * inv2) % MOD;
    f[i] = (MOD + 1 - ipow2) % MOD;
  }
  solve(0);
  for (int i = 0; i <= k; i++) {
    binom[i][0] = binom[i][i] = 1;
    for (int j = 1; j < i; j++)
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
  }
  g[1] = 1;
  for (int l = 2; l <= k; l++) {
    g[l] = 1;
    for (int i = 0; i < k; i++) g[l] = g[l] * l % MOD;
    for (int i = 1; i < l; i++) g[l] -= binom[l][i] * g[i] % MOD;
    g[l] %= MOD;
    if (g[l] < 0) g[l] += MOD;
  }
  long long ans = 0;
  for (int i = 1; i <= k; i++) ans = (ans + a[i] * g[i]) % MOD;
  for (int i = 0; i < n; i++) ans = ans * 2 % MOD;
  cout << ans << "\n";
  return 0;
}
