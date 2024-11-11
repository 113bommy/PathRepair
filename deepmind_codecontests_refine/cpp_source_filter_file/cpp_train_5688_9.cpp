#include <bits/stdc++.h>
int read() {
  int r = 0, t = 1, c = getchar();
  while (c < '0' || c > '9') {
    t = c == '-' ? -1 : 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = r * 10 + c - 48;
    c = getchar();
  }
  return r * t;
}
const int N = 5010, mod = 1000000007;
long long power(long long a, long long b, long long p) {
  long long r = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) r = r * a % p;
  return r;
}
long long inv(long long a) { return power(a, mod - 2, mod); }
long long n, k, I[N], f[N], F[N], g[N], a[N], ans;
inline long long Mod(long long a) { return a >= mod ? a - mod : a; }
inline long long &Add(long long &a, long long b) { return a = Mod(a + b); }
void dp(long long *F, long long *f, long long a) {
  for (int i = (0), end_i = (n); i <= end_i; i++) F[i] = 0;
  for (int i = (0), end_i = (n - 1); i <= end_i; i++) {
    Add(F[i + 1], mod - f[i]);
    Add(F[i], f[i] * a % mod);
  }
}
void idp(long long *F, long long *f, long long a) {
  F[n] = 0;
  for (int i = (n - 1), end_i = (0); i >= end_i; i--)
    F[i] = Mod(mod - (f[i + 1] - a * F[i + 1]) % mod);
}
int main() {
  n = read();
  k = read();
  for (int i = (1), end_i = (n); i <= end_i; i++) a[i] = read();
  for (int i = (1), end_i = (n); i <= end_i; i++) I[i] = inv(i);
  f[0] = 1;
  for (int i = (1), end_i = (n); i <= end_i; i++) {
    dp(F, f, a[i]);
    for (int j = (0), end_j = (i); j <= end_j; j++) f[j] = F[j];
  }
  for (int i = (1), end_i = (n); i <= end_i; i++) {
    idp(F, f, a[i]);
    for (int j = (0), end_j = (n - 1); j <= end_j; j++) Add(g[j], F[j]);
  }
  for (int i = (0), end_i = (n - 1); i <= end_i; i++) {
    long long A = inv(i + 1) * power(n, mod - 1 - 1 - i, mod);
    for (int j = (0), end_j = (i); j <= end_j; j++) A = A * (k - j) % mod;
    Add(ans, g[i] * A % mod);
  }
  printf("%lld\n", ans);
  return 0;
}
