#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  long long f = 0, c = getchar();
  x = 0;
  while (!isdigit(c)) f |= c == 45, c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (f) x = -x;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
const long long maxn = 2e6 + 50, mod = 1e9 + 7;
long long n, m, ans;
long long fac[maxn], nfac[maxn], sum[maxn], po10[maxn];
string str;
long long ksm(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = (res * a) % mod;
    p >>= 1;
    a = (a * a) % mod;
  }
  return res;
}
void init() {
  read(n, m);
  cin >> str;
  po10[0] = 1;
  for (long long i = 1; i <= n; i++) po10[i] = po10[i - 1] * 10 % mod;
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  nfac[n] = ksm(fac[n], mod - 2);
  for (long long i = n - 1; i >= 0; i--) nfac[i] = nfac[i + 1] * (i + 1) % mod;
  long long ans = 0;
  str = " " + str;
  for (long long i = 1; i <= n; i++) sum[i] = sum[i - 1] + str[i] - 48;
}
inline long long c(long long n, long long m) {
  if (m > n) return 0;
  return fac[n] * nfac[m] % mod * nfac[n - m] % mod;
}
signed main() {
  init();
  for (long long i = 1; i <= n - m; i++) {
    ans = (ans + po10[i - 1] * sum[n - i] % mod * c(n - i - 1, m - 1) % mod) %
          mod;
  }
  for (long long i = m + 1; i <= n; i++)
    ans = (ans + po10[n - i] * (str[i] - 48) * c(i - 1, m) % mod) % mod;
  printf("%lld\n", ans);
  return 0;
}
