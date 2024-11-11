#include <bits/stdc++.h>
const long long mod = 100000;
int main() {
  long long a, t, res = 1;
  scanf("%lld", &a);
  t = a / 10000 * 10000 + a / 100 % 10 * 1000 + a % 10 * 100 +
      a / 10 % 10 * 10 + a / 1000 % 10;
  for (int i = 0; i < 5; ++i) res = res * t % mod;
  printf("%05lld\n", res);
  return 0;
}
