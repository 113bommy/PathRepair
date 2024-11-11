#include <bits/stdc++.h>
using namespace std;
const int modu = 1000003;
long long n, k;
inline long long mod_mul(long long a, long long b, int modu = ::modu) {
  long long res = 0;
  while (b) {
    if (b & 1) (res += a) %= modu;
    (a <<= 1) %= modu;
    b >>= 1;
  }
  return res;
}
inline long long mod_pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) (res *= a) %= modu;
    (a *= a) %= modu;
    b >>= 1;
  }
  return res;
}
int main() {
  scanf("%lld%lld", &n, &k);
  if (n <= 62 && k > (1LL << n)) return puts("1 1\n"), 0;
  long long num = 1, deno = 0, pow = 0, inv;
  pow = k - 1 - __builtin_popcountll(k - 1);
  if ((k - 1) < modu) {
    long long tmp = (mod_pow(2, n) + modu - 1) % modu;
    for (int i = 0; i < k - 1; ++i) {
      (num *= tmp) %= modu;
      (tmp += modu - 1) %= modu;
    }
  } else
    num = 0;
  deno = mod_pow(2, mod_mul(n, k - 1, modu - 1));
  inv = mod_pow(mod_pow(2, pow), modu - 2);
  (num *= inv) %= modu, (deno *= inv) %= modu;
  printf("%lld %lld\n", (deno - num + modu) % modu, deno);
  return 0;
}
