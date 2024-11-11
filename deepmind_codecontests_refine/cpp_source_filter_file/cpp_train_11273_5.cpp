#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int a[N];
const int mod = 998244353;
long long quickpow(long long a, long long b) {
  if (b < 0) return 0;
  long long ret = 1;
  a %= mod;
  while (b) {
    if (b & 1) ret = (ret * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return ret;
}
long long inv(long long a) { return quickpow(a, mod - 2); }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + 2 * n);
  long long res1 = 0, res2 = 1;
  for (int p = 0, q = 2 * n - 1; p < q; p++, q--) {
    res1 += a[q] - a[p];
    res1 %= mod;
  }
  for (int i = 2 * n, j = 1; j <= n; j++, i--) {
    res2 = res2 * i * inv(j) % mod;
  }
  long long res = res1 * res2 % mod;
  printf("%lld\n", res);
}
