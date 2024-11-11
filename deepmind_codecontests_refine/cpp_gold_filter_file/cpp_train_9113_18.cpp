#include <bits/stdc++.h>
using namespace std;
bool scan(int& x) { return scanf("%d", &x) == 1; }
bool scan(long long& x) { return scanf("%I64d", &x) == 1; }
bool scan(char* s) { return scanf("%s", s) == 1; }
template <typename T, typename... TT>
bool scan(T& x, TT&... xx) {
  return scan(x) && scan(xx...);
}
long long powmod(long long a, long long p, long long mod) {
  long long r = 1;
  a %= mod;
  for (; p; p >>= 1, (a *= a) %= mod)
    if (p & 1) (r *= a) %= mod;
  return r;
}
const long long mod = 1e6 + 3;
int main() {
  long long n, k;
  while (scan(n, k)) {
    long long len = 0;
    for (long long x = k; x; x >>= 1) ++len;
    if (len > n + 1 || (len == n + 1 && (k & (k - 1)))) {
      puts("1 1");
      continue;
    }
    long long cnt = 0;
    for (long long x = k - 1, p = 2; x; x /= p) {
      cnt += x / p;
    }
    cnt += n;
    long long inv = powmod(powmod(2, mod - 2, mod), cnt, mod);
    long long a = powmod(powmod(2, n, mod), k, mod), b = a * inv % mod;
    long long t = 1;
    for (long long x = 0; x < k; ++x) {
      (t *= powmod(2, n, mod) - x) %= mod;
      if (t == 0) break;
    }
    a = (a - t + mod) % mod * inv % mod;
    cout << a << ' ' << b << endl;
  }
  return 0;
}
