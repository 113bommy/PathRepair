#include <bits/stdc++.h>
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  do x = x * 10 + ch - 48, ch = getchar();
  while (ch >= '0' && ch <= '9');
  return x * f;
}
const int MAXN = 1000001;
const int mod = 998244353;
int k, n, a[MAXN << 1], p[MAXN << 1];
long long fac[MAXN << 1], ifac[MAXN << 1];
long long C(int n, int m) {
  if (n < m || n < 0 || m < 0) return 0;
  return fac[n] * ifac[m] % mod * ifac[n - m];
}
int main() {
  k = read();
  n = k + MAXN;
  for (int i = 1; i <= k; i++) {
    a[i] = read();
    for (int j = a[i] + 1; j <= n; j += k) p[j]++;
  }
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] + p[i];
    if (p[i] > i) n = i - 1;
  }
  fac[0] = 1;
  for (int i = 1; i <= n + k; i++) fac[i] = fac[i - 1] * i % mod;
  ifac[0] = ifac[1] = 1;
  for (int i = 2; i <= n + k; i++)
    ifac[i] = (mod - mod / i) * ifac[mod % i] % mod;
  for (int i = 1; i <= n + k; i++) ifac[i] = ifac[i - 1] * ifac[i] % mod;
  long long ans = 0;
  for (int i = n; i > n - k && i >= 0; i--) {
    ans = (ans + C(i - p[i] + k - 1, k - 1)) % mod;
  }
  std::printf("%lld\n", ans);
  return 0;
}
