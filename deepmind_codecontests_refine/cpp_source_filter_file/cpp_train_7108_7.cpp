#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -f;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + (s - '0');
    s = getchar();
  }
  return f * x;
}
const int MOD = 998244353;
int qkpow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = res * 1ll * a % MOD;
    a = a * 1ll * a % MOD;
    b >>= 1;
  }
  return res;
}
int n, m, i, j, s, o, k;
int a[5005], dp[5005];
int fac[5005], invf[5005];
int A(int n, int m) {
  if (m < 0 || m > n) return 0;
  return fac[n] * 1ll * invf[n - m] % MOD;
}
int ct[5005];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * 1ll * i % MOD;
  invf[n] = qkpow(fac[n], MOD - 2);
  for (int i = n - 1; i >= 0; i--) invf[i] = invf[i + 1] * 1ll * (i + 1) % MOD;
  int pre = 0;
  for (int i = 1; i <= n; i++) {
    while (pre < n && (a[pre + 1] << 1) <= a[i]) pre++;
    ct[i] = pre + 1;
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i && (a[j] << 1) <= a[i]; j++) {
      (dp[i] += dp[j] * 1ll * A(n - ct[j] - 1, ct[i] - ct[j] - 1)) %= MOD;
    }
  }
  if (ct[n] < n) {
    printf("0\n");
  } else
    printf("%d\n", dp[n]);
  return 0;
}
