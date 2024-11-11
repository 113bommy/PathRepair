#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 7;
const int mod = 1000000007;
int n, a[maxn];
long long dp[maxn][maxn], fac[maxn];
long long quick_pow(long long a, long long b) {
  long long sum = 1;
  while (b) {
    if (b & 1) sum = (sum * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return sum;
}
long long inv(int n, int m) {
  if (m > n) return 0;
  return (((fac[n] * (quick_pow(fac[m], mod - 2)) % mod) *
           quick_pow(fac[n - m], mod - 2) % mod) %
          mod);
}
void init() {
  fac[0] = 1;
  for (int i = 1; i <= 100; i++) fac[i] = (fac[i - 1] * i) % mod;
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = 0; i < 10; i++) scanf("%d", &a[i]);
  for (int i = a[9]; i <= n; i++) dp[9][i] = 1;
  for (int i = 8; i >= 0; i--) {
    for (int len = a[i]; len <= n; len++) {
      for (int j = a[i]; j <= len; j++) {
        dp[i][len] =
            (dp[i][len] + dp[i + 1][len - j] * inv(i == 0 ? len - 1 : len, j)) %
            mod;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + dp[0][i]) % mod;
  printf("%lld\n", ans);
  return 0;
}
