#include <bits/stdc++.h>
using namespace std;
long long n, k, m = 1e6 + 3;
inline long long modexp(long long x, long long y) {
  long long e = x, r = 1;
  while (y > 0) {
    if (y & 1) r = r * e % m;
    e = e * e % m;
    y >>= 1;
  }
  return r;
}
int main() {
  scanf("%I64d%I64d", &n, &k);
  if (n < 63 && (1LL << n) < k) return puts("1 1"), 0;
  long long g = 0;
  for (long long t = k - 1; t > 0; g += (t /= 2))
    ;
  long long a = 1, inv = modexp(modexp(2, g), m - 2);
  if (k < m + 1)
    for (long long t = k - 1; t > 0; t--) {
      a = a * ((modexp(2, n) + m - t) % m) % m;
    }
  else
    a = 0;
  printf("%I64d %I64d\n",
         (modexp(modexp(2, n), k - 1) * inv % m + m - a * inv % m) % m,
         modexp(modexp(2, n), k - 1) * inv % m);
  return 0;
}
