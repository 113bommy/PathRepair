#include <bits/stdc++.h>
using namespace std;
long long n, x;
long long ksm(long long x, long long y) {
  if (!y) return 1;
  long long z = ksm(x, y / 2);
  z *= z;
  z %= (n + 1);
  if (y & 1) z *= x;
  return z % (n + 1);
}
signed main() {
  scanf("%lld%lld", &n, &x);
  for (long long i = 2; i * i <= n + 1; i++)
    if ((n + 1) % i == 0) {
      puts("-1");
      return 0;
    }
  for (long long i = x - 1; i; i--) {
    if (i % (n + 1) == 0) continue;
    long long fl = 0;
    for (long long j = 2; j * j <= n && !fl; j++)
      if (n % j == 0 && (ksm(i, j) == 1 || ksm(i, n / j) == 1)) fl = 1;
    if (!fl) {
      printf("%lld\n", i);
      return 0;
    }
  }
  puts("-1");
}
