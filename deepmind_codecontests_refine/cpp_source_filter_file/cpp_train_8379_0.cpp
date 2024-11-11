#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n;
long long Pow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ret % mod;
}
int main() {
  scanf("%d", &n);
  printf("%lld\n", (Pow(27, n) - Pow(7, n) % mod) % mod);
  return 0;
}
