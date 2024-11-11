#include <bits/stdc++.h>
const long long maxn = 30050;
const long long mod = 1e9 + 7;
using namespace std;
signed main() {
  long long t = 1, y = 1, n;
  scanf("%lld", &n);
  for (long long i = n / 2 + 1; i <= n; ++i) t *= i;
  for (long long i = 1; i <= n / 2; ++i) y *= i;
  long long p = 1;
  for (long long i = 1; i <= n / 2 - 1; ++i) p *= i;
  printf("%lld\n", t / (y * 2 * p * p));
}
