#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
map<int, int> sp;
int cnt = 0, num[1100];
long long dp[1100][1100], fac[200005], inv[200005];
long long quick(long long a, long long k) {
  long long ans = 1;
  while (k) {
    if (k & 1) ans = ans * a % mod;
    k /= 2;
    a = a * a % mod;
  }
  return ans;
}
long long C(long long n, long long m) {
  if (m > n) return 0;
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
  int k, n, i, j, ot = 0;
  fac[0] = inv[0] = fac[1] = inv[1] = 1;
  for (i = 2; i <= 200000; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = quick(fac[i], mod - 2);
  }
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &j);
    int p = j;
    while (p) {
      if (p % 10 == 4 || p % 10 == 7)
        p /= 10;
      else
        break;
    }
    if (p > 0)
      ot++;
    else {
      if (sp[j] == 0) {
        sp[j] = ++cnt;
        num[cnt]++;
      } else
        num[sp[j]]++;
    }
  }
  long long ans = 0;
  dp[0][0] = 1;
  for (int i = 1; i <= cnt; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      dp[i][j] += dp[i - 1][j];
      dp[i][j] += dp[i - 1][j - 1] * num[i];
      dp[i][j] %= mod;
    }
  }
  for (i = 0; i <= cnt; i++) {
    ans += dp[cnt][i] * C(ot, k - i);
    ans %= mod;
  }
  printf("%lld\n", ans);
  return 0;
}
