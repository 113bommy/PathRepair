#include <bits/stdc++.h>
inline unsigned int getuint() {
  char w = getchar();
  while (w < '0' || '9' < w) w = getchar();
  unsigned int ans = 0;
  for (; '0' <= w && w <= '9'; w = getchar()) ans = ans * 10 + w - '0';
  return ans;
}
inline unsigned int getdigit() {
  char w = getchar();
  while (w < '0' || '9' < w) w = getchar();
  return w - '0';
}
const int mod = 1000000007;
inline long long qpow(long long x, int y) {
  long long ans = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) ans = ans * x % mod;
  return ans;
}
inline long long inverse(long long x) {
  long long ans = 1;
  for (unsigned int y = mod - 2; y; y >>= 1, x = x * x % mod)
    if (y & 1) ans = ans * x % mod;
  return ans;
}
long long a[100005], s[100005], fact[100005], ifact[100005];
inline long long C(int n, int m) {
  return n <= m ? n == m : fact[n] * ifact[n - m] % mod * ifact[m] % mod;
}
int main() {
  int n = getuint(), m = getuint();
  for (int i = 1; i <= n; i++) s[i] = (s[i - 1] + (a[i] = getdigit())) % mod;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
  ifact[n] = inverse(fact[n]);
  for (int i = n; i; i--) ifact[i - 1] = ifact[i] * i % mod;
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + a[i] * qpow(10ll, n - i) % mod * C(i - 1, m) % mod) % mod;
  for (int l = 0; l < n; l++)
    ans =
        (ans + s[n - l - 1] * qpow(10ll, l) % mod * C(n - l - 2, m - 1) % mod) %
        mod;
  printf("%I64d\n", ans);
  return 0;
}
