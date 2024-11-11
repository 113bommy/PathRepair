#include <bits/stdc++.h>
using namespace ::std;
const int maxn = 100 + 10;
const int maxk = 20 + 5;
const int mod = 1e9 + 7;
int n, k;
long long dp[maxn][2 * maxk], h[2 * maxk];
vector<vector<int> > e;
void init() {
  scanf("%d%d", &n, &k);
  e.resize(n + 1);
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[v].push_back(u);
    e[u].push_back(v);
  }
}
void dfs(int u, int p) {
  dp[u][0] = dp[u][k + 1] = 1;
  for (auto v : e[u]) {
    if (v == p) continue;
    dfs(v, u);
    for (int i = 0; i <= 2 * k; i++) h[i] = 0;
    for (int i = 0; i <= 2 * k; i++)
      for (int j = 0; j <= 2 * k; j++) {
        if (i + j <= 2 * k) {
          (h[min(i, j + 1)] += dp[u][i] * dp[v][j]) %= mod;
        } else {
          (h[max(i, j + 1)] += dp[u][i] * dp[v][j]) %= mod;
        }
      }
    for (int i = 0; i <= 2 * k; i++) dp[u][i] = h[i];
  }
}
void solve() {
  if (k == 0) {
    puts("1");
    return;
  }
  dfs(1, 0);
  int ans = 0;
  for (int i = 0; i <= k; i++) (ans += dp[1][i]) %= mod;
  printf("%d\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
