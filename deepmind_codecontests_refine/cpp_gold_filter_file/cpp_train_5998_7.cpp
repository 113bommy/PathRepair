#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
inline long long read() {
  long long num = 0, fu = 1;
  char c = getchar();
  while (c != '-' && (c > '9' || c < '0')) c = getchar();
  if (c == '-') fu = -1, c = getchar();
  while (c >= '0' && c <= '9')
    num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
  return fu * num;
}
long long n, m;
long long mul(long long x, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) (res *= x) %= mod;
    (x *= x) %= mod;
    p >>= 1;
  }
  return res;
}
signed main() {
  n = read();
  m = read();
  printf("%lld\n", mul(2, m) * (n + 1 - m) % mod * mul(n + 1, m - 1) % mod);
}
