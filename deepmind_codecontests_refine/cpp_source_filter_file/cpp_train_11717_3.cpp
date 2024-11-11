#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
const int M = 2e6 + 7;
const int lim = 1e6;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long ksm(long long a, long long b, long long p) {
  long long ret = 1;
  while (b) {
    if (b & 1) (ret *= a) %= p;
    (a *= a) %= p;
    b >>= 1;
  }
  return ret;
}
long long inv(long long x) { return ksm(x, mod - 2, mod); }
int main() {
  long long k, x, a = 1, b = 1, f, aa, bb;
  scanf("%lld", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%lld", &x);
    if (x % 2 == 0) f = 1;
    (a *= (x % 2)) %= 2;
    (b *= (x % (mod - 1))) %= mod - 1;
  }
  if (f == 0) f = -1;
  b = (b - 1 + mod - 1) % (mod - 1);
  a = (a - 1 + 2) % 2;
  bb = ksm(2, b, mod);
  aa = (bb + f + mod) % mod;
  long long t = ksm(2, a, 3);
  t = (t + f + 3) % 3;
  if (t == 0)
    aa = inv(3) * aa % mod;
  else
    bb = bb * 3 % mod;
  printf("%lld/%lld\n", aa, bb);
  return 0;
}
