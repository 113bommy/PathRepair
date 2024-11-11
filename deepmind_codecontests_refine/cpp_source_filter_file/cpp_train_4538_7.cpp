#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int MAXX = 2e6 + 10;
long long f(long long n) {
  if (n == 1) return 1ll;
  long long ret = 1;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ret *= (i - 1);
      n /= i;
      while (n % i == 0) {
        n /= i;
        ret *= i;
      }
    }
  }
  if (n > 1) ret *= n - 1;
  return ret;
}
long long F(long long n, long long k) {
  if (k == 1) return f(n);
  if (n == 1) return 1ll;
  if (k & 1) {
    long long ret = F(f(n), k - 1);
    return ret;
  } else {
    long long ret = F(n, k - 1);
    return ret;
  }
}
int main() {
  long long n, k;
  scanf("%lld %lld", &n, &k);
  long long ans = F(n, k);
  printf("%lld", ans);
  return 0;
}
