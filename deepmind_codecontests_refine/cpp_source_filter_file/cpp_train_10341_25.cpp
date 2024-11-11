#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
const int MOD = 1e9 + 7;
int dp[MAXN + 10];
int main() {
  int n;
  dp[1] = 0;
  scanf("%d", &n);
  n = (n >> 1) - 1;
  for (int i = 2; i <= n; i++) dp[i] = (dp[i - 1] * 2 + 1) % MOD;
  for (int i = 1; i <= n; i++) dp[i] = (4ll * dp[i] + 1) % MOD;
  for (int i = 2; i <= n; i++) dp[i] = 1ll * dp[i] * dp[i - 1] % MOD;
  int side = 2;
  for (int i = 1; i <= n; i++) side = (side + 4ll * dp[i]) % MOD;
  int ans = 1ll * side * side % MOD;
  ans = (2ll * (ans + 1)) % MOD;
  printf("%d\n", ans);
  return 0;
}
