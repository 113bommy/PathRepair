#include <bits/stdc++.h>
using namespace std;
const int maxn = 3030303;
long long n, q, inv[maxn], inv_fac[maxn], fac[maxn], dp[maxn / 3][3];
long long C(long long x, long long y) {
  return (x < y || x < 0 || y < 0)
             ? 0
             : (fac[x] * ((inv_fac[y] * inv_fac[x - y]) % 1000000007)) %
                   1000000007;
}
int main() {
  fac[0] = inv_fac[0] = fac[1] = inv_fac[1] = inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    fac[i] = (fac[i - 1] * i) % 1000000007;
    inv[i] =
        ((1000000007 - (1000000007 / i)) * inv[1000000007 % i]) % 1000000007;
    inv_fac[i] = (inv_fac[i - 1] * inv[i]) % 1000000007;
  }
  scanf("%lld %lld", &n, &q);
  dp[0][0] = dp[0][1] = dp[0][2] = n;
  for (int i = 1; i <= 3 * n; i++) {
    long long sum = C(3 * n, i + 1), x1 = dp[i - 1][0], y1 = dp[i - 1][1];
    dp[i][0] =
        (((sum + 1000000007 * 2 - x1 * 2 + 1000000007 - y1) % 1000000007) *
         inv[3]) %
        1000000007;
    dp[i][1] = (dp[i][0] + x1) % 1000000007;
    dp[i][2] = (dp[i][1] + y1) % 1000000007;
  }
  for (int testcase = 0; testcase < q; testcase++) {
    long long x;
    scanf("%lld", &x);
    printf("%lld\n", (C(3 * n, x) + dp[x][0]) % 1000000007);
  }
  return 0;
}
