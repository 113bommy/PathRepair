#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const int mod = 998244353;
int n;
int a[N];
int dp[N];
int fac[N], ifac[N];
int qpow(int a, int b) {
  int res = 1;
  for (; b > 0; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) res = 1ll * res * a % mod;
  return res;
}
void init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  return;
}
int A(int n, int m) {
  if (m == 0) return 1;
  if (n == 0) return 0;
  return 1ll * fac[n + m - 1] * ifac[n - 1] % mod;
}
int main() {
  init(N - 10);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  dp[n] = 1;
  for (int i = n; i >= 1; i--) {
    int cnt = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (a[j] * 2 <= a[i])
        dp[j] = (dp[j] + 1ll * dp[i] * A(n - i, cnt) % mod *
                             A(n - i + 1 + cnt, (i - j - 1) - cnt) % mod) %
                mod;
      if (a[j] * 2 > a[i] && a[j] * 2 < 4 * a[i]) cnt++;
    }
  }
  printf("%d\n", dp[0]);
  return 0;
}
