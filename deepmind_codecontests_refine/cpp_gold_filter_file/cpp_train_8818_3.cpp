#include <bits/stdc++.h>
using namespace std;
long long x, k, mod = 1000000007ll, a, b;
long long pow(long long x, long long y) {
  if (y == 0)
    return 1ll % mod;
  else {
    long long tmp = pow(x, y / 2);
    tmp = tmp * tmp % mod;
    if (y % 2 == 1) tmp = tmp * x % mod;
    return tmp;
  }
}
long long res;
int main() {
  scanf("%lld %lld", &x, &k);
  if (x == 0ll) {
    puts("0");
    return 0;
  }
  a = (x % mod * pow(2ll, k + 1)) % mod;
  b = pow(2ll, k) - 1ll;
  printf("%lld\n", (a - b + mod) % mod);
  return 0;
}
