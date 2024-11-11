#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
const long long p = 998244353;
long long a[maxn];
long long qpow(long long a, long long n, long long p) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans *= a, ans %= p;
    a *= a, a %= p;
    n >>= 1;
  }
  return ans;
}
int main() {
  int n;
  scanf("%lld", &n);
  long long inv = qpow(n, p - 2, p);
  for (int i = (1); i <= (n); ++i) scanf("%lld", &a[i]);
  sort(a + 1, a + 1 + n);
  for (int i = (2); i <= (n); ++i) a[i] += a[i - 1];
  for (int i = (1); i <= (n); ++i) {
    long long ans = 0, t = 1;
    for (int j = n - i; j > 0; j -= i) {
      if (j > i)
        ans += ((a[j] - a[j - i]) % p + p) % p * t % p;
      else
        ans += a[j] % p * t % p;
      ++t;
    }
    printf("%lld ", ans % p * inv % p);
  }
}
