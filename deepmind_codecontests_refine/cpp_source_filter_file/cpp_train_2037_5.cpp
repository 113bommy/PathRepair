#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 210;
int n, k;
vector<int> mp[maxn];
int dp[maxn][maxn];
int tmp[maxn];
void dfs(int rt, int f) {
  dp[rt][0] = 1;
  dp[rt][k + 1] = 1;
  for (int v : mp[rt]) {
    if (v == f) continue;
    dfs(v, rt);
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i <= k * 2; i++) {
      for (int j = 0; j <= 2 * k; j++) {
        if (j + i + 1 <= 2 * k + 1)
          tmp[min(rt, j + 1)] += 1ll * dp[rt][i] * dp[v][j] % mod,
              tmp[min(rt, j + 1)] %= mod;
        else
          tmp[max(i, j + 1)] += 1ll * dp[rt][i] * dp[v][j] % mod,
              tmp[max(i, j + 1)] %= mod;
      }
    }
    for (int i = 0; i <= 2 * k + 1; i++) dp[rt][i] = tmp[i];
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    mp[x].push_back(y);
    mp[y].push_back(x);
  }
  dfs(1, 0);
  long long res = 0;
  for (int i = 0; i <= k; i++) res += dp[1][i];
  printf("%lld", res % mod);
  return 0;
}
