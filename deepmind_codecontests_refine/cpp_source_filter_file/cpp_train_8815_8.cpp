#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long ksm(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = res * a % mod;
    a = a * a % mod;
    p >>= 1;
  }
  return res;
}
int main() {
  long long x, k;
  scanf("%lld%lld", &x, &k);
  if (k == 0) {
    printf("%lld\n", x * 2);
    return 0;
  }
  if (x == 0) {
    puts("0");
    return 0;
  }
  x = (x * 4 - 1) % mod;
  long long ans = ((x - 1) * ksm(2, k - 1) % mod + 1) % mod;
  printf("%lld\n", ans);
  return 0;
}
