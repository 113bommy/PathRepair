#include <bits/stdc++.h>
using namespace std;
void In() { freopen("in.in", "r", stdin); }
void Out() { freopen("out.out", "w", stdout); }
const int N = 1e2 + 10;
const int M = 3e5 + 10;
const int Mbit = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
vector<int> G[N];
long long dp[N][45], f[45];
int n, k;
void dfs(int u, int fa) {
  dp[u][0] = dp[u][k + 1] = 1;
  for (auto v : G[u]) {
    if (v == fa) continue;
    dfs(v, u);
    for (int i = 0; i <= 2 * k; i++) f[i] = 0;
    for (int i = 0; i <= 2 * k; i++) {
      for (int j = 0; j <= 2 * k; j++) {
        if (i + j <= 2 * k)
          (f[min(i, j + 1)] += dp[u][i] * dp[v][j]) %= mod;
        else
          (f[max(i, j + 1)] += dp[u][i] * dp[v][j]) %= mod;
      }
    }
    for (int i = 0; i <= 2 * k; i++) dp[u][i] = f[i];
  }
}
int main() {
  In();
  while (~scanf("%d%d", &n, &k)) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(1, -1);
    long long ans = 0;
    for (int i = 0; i <= k; i++) (ans += dp[1][i]) %= mod;
    cout << ans << endl;
  }
  return 0;
}
