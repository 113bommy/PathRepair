#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int MAXN = 1e6;
long long suf[N];
long long fac[N], ifac[N];
long long euler[N];
void euler_t() {
  euler[1] = 1;
  for (int i = 2; i < MAXN; ++i) euler[i] = i;
  for (int i = 2; i < MAXN; ++i) {
    if (euler[i] == i)
      for (int j = i; j < MAXN; j += i) {
        euler[j] = euler[j] / i * (i - 1);
      }
  }
}
long long quick_pow(long long a, long long b) {
  a %= mod;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long inv(long long x) { return quick_pow(x, mod - 2); }
long long C(int n, int m) {
  if (m > n) return 0;
  return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i <= 1000000; ++i) fac[i] = fac[i - 1] * i % mod;
  ifac[1000000] = inv(fac[1000000]);
  for (int i = 999999; i >= 0; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}
int num[N];
long long res;
int n, m, q;
int tim[N];
void sol(int x) {
  long long pre = 0;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      pre = pre + C(num[i], m - 1) * euler[i] % mod;
      num[i]++;
      if (i * i != x) {
        pre = pre + C(num[x / i], m - 1) * euler[x / i] % mod;
        num[x / i]++;
      }
      pre %= mod;
    }
  }
  res = res + pre;
  res %= mod;
}
int main() {
  init();
  euler_t();
  scanf("%d %d %d", &n, &m, &q);
  int x;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    sol(x);
  }
  for (int i = 1; i <= q; ++i) {
    scanf("%d", &x);
    sol(x);
    printf("%lld\n", res);
  }
}
