#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const double EPS = 1e-9;
int n;
vector<int> e[200015];
long long dp[200015][3];
long long mpow(long long x, long long y = MOD - 2) {
  long long res = 1;
  for (; y; y >>= 1) {
    if (y & 1) res = res * x % MOD;
    x = x * x % MOD;
  }
  return res;
}
void dfs(int u, int fa = 0) {
  if (e[u].empty()) {
    dp[u][1] = dp[u][2] = 1;
    return;
  }
  long long t1 = 1, t2 = 1;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (fa == v) continue;
    dfs(v, u);
    t1 = t1 * (dp[v][0] + dp[v][2]) % MOD;
    t2 = t2 * (dp[v][0] + dp[v][1] + dp[v][2]) % MOD;
  }
  dp[u][0] = t1;
  dp[u][2] = dp[u][1] = ((t2 - t1) % MOD + MOD) % MOD;
  if (0 == dp[u][0]) return;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (fa == v) continue;
    dp[u][2] -= t1 * dp[v][1] % MOD * mpow(dp[v][0] + dp[v][2]) % MOD;
  }
  dp[u][2] = (dp[u][2] % MOD + MOD) % MOD;
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    e[p].push_back(i);
  }
  dfs(1);
  printf("%lld\n", (dp[1][0] + dp[1][2]) % MOD);
  return 0;
}
