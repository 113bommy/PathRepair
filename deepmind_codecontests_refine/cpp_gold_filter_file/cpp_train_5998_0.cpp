#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long __x = 0, __y = 1;
  char __c = ' ';
  while (__c < '0' || __c > '9') {
    __c = getchar();
    if (__c == '-') {
      __c = getchar();
      break;
    }
  }
  while (__c >= '0' && __c <= '9') __x = __x * 10 + __c - '0', __c = getchar();
  return __x * __y;
}
const long long N = 1e3 + 7, MOD = 1e9 + 7, INF = 1e9 + 7;
long long n, m, ans;
inline long long qpow(long long base, long long exponent) {
  long long res = 1;
  while (exponent) {
    if (exponent & 1) res = res * base % MOD;
    base = base * base % MOD, exponent >>= 1;
  }
  return res;
}
signed main() {
  n = read(), m = read();
  printf("%lld\n",
         (n + 1 - m) * qpow(n + 1, MOD - 2) % MOD * qpow(2 * (n + 1), m) % MOD);
  return 0;
}
