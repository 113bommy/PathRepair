#include <bits/stdc++.h>
using namespace std;
long long mod = (long long)1e9 + 7;
long long fastPow(long long x, long long n) {
  long long ans = 1;
  while (n != 0) {
    if (n % 2 == 1) ans = ((ans % mod) * (x % mod)) % mod;
    n /= 2;
    x = ((x % mod) * (x % mod)) % mod;
  }
  return ans;
}
int main() {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  long long ans = fastPow(fastPow(2, m) - 1, n);
  printf("%lld\n", ans);
  return 0;
}
