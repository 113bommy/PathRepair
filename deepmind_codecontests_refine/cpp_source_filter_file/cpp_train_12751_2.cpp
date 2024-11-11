#include <bits/stdc++.h>
using namespace std;
long long n, m, b, mod, ans;
long long a[510], dp[510][510];
int main() {
  scanf("%lld%lld%lld%lld", &n, &m, &b, &mod);
  for (register int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  dp[0][0] = 1;
  for (register int i = 1; i <= n; i++)
    for (register int j = 1; j <= m; j++)
      for (register int k = a[i]; k <= b; k++)
        dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % mod;
  for (register int i = 1; i <= b; i++) ans = (ans + dp[m][i]) % mod;
  printf("%lld\n", ans);
  return 0;
}
