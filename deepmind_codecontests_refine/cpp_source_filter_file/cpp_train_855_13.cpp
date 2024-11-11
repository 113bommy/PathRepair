#include <bits/stdc++.h>
using namespace std;
inline bool isprime(long long num) {
  if (num == 2 || num == 3) return true;
  if (num % 6 != 1 && num % 6 != 5) return false;
  for (int i = 5; 1ll * i * i <= num; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) return false;
  }
  return true;
}
const int mod = 998244353;
inline long long mul(long long a, long long b, long long c) {
  return (a * b - (long long)((long double)a * b / c) * c + c) % c;
}
inline long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long g = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return g;
}
inline long long quick_pow(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = mul(res, a, mod);
    a = mul(a, a, mod);
    b >>= 1;
  }
  return res;
}
inline long long quick_pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = mul(res, a, mod);
    a = mul(a, a, mod);
    b >>= 1;
  }
  return res;
}
inline long long inv(long long x) { return quick_pow(x, mod - 2); }
inline long long inv(long long x, long long mod) {
  return quick_pow(x, mod - 2, mod);
}
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
const int N = 2e5 + 10;
int fac[N];
long long C(int n, int m) {
  if (n < m || n < 0 || m < 0) return 0;
  return 1ll * fac[n] * quick_pow(1ll * fac[m] * fac[n - m] % mod, mod - 2) %
         mod;
}
int main() {
  long long n, k;
  cin >> n >> k;
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  if (k >= n) return 0 * printf("0\n");
  if (k == 0) return 0 * printf("%lld\n", fac[n]);
  long long ans = 0;
  for (int i = 0; i <= n - k; i++)
    ans = (ans + 1ll * quick_pow(mod - 1, i) * C(n - k, i) % mod *
                     quick_pow(n - k - i, n) % mod) %
          mod;
  printf("%lld\n", 2ll * ans % mod * C(n, n - k) % mod);
  return 0;
}
