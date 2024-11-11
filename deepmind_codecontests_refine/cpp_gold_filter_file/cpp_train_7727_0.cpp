#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const long long maxn = 2e5 + 10;
int main() {
  long long n, i;
  long long dp[maxn];
  cin >> n;
  dp[0] = 1;
  for (i = 1; i < maxn; i++) dp[i] = (dp[i - 1] * 10) % mod;
  for (i = 1; i < n; i++) {
    if (n - i - 2 >= 0)
      printf("%lld ",
             (180 * dp[n - i - 1] + (n - i - 1) * 81 * dp[n - i - 1]) % mod);
    else
      printf("%lld ", 180 * dp[n - i - 1] % mod);
  }
  printf("10\n");
}
