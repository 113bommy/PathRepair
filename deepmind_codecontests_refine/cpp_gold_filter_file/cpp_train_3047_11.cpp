#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int INF = 0x3f3f3f3f;
long long ksm(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 1e6 + 10;
int n;
long long r1, r2, r3, d;
long long a[N];
long long dp[N][2];
int main() {
  scanf("%d%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[1][0] = a[1] * r1 + r3;
  dp[1][1] = min(a[1] * r1 + r1, r2);
  for (int i = 2; i <= n; i++) {
    dp[i][1] = min(dp[i - 1][0] + min(a[i] * r1 + r1, r2),
                   dp[i - 1][1] + 2 * d + r1 + min(a[i] * r1 + r1, r2)) +
               d;
    dp[i][0] =
        min(dp[i - 1][0] + a[i] * r1 + r3,
            min(dp[i - 1][1] + 2 * d + r1 + a[i] * r1 + r3,
                dp[i - 1][1] + 2 * d + 2 * r1 + min(a[i] * r1 + r1, r2))) +
        d;
  }
  printf("%lld\n", min(dp[n][0], dp[n - 1][1] + 2 * d + r1 + a[n] * r1 + r3));
  return 0;
}
