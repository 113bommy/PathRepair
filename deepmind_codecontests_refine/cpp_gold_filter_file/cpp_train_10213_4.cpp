#include <bits/stdc++.h>
using namespace std;
long long digit(long long x) {
  long long ans = 0;
  while (x) {
    ans++;
    x /= 10;
  }
  return ans;
}
const long long N = 2e5;
long long a[N + 10];
long long p[11];
signed main() {
  long long n, k;
  scanf("%lld %lld", &n, &k);
  p[0] = 1ll;
  for (long long i = 1; i <= 10; i++) p[i] = p[i - 1] * 10 % k;
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  map<long long, long long> vis[11];
  for (long long i = 1; i <= n; i++) {
    for (long long d = 1; d <= 10; d++) {
      long long kk = a[i] * p[d] % k;
      kk = -kk;
      kk = (kk + k) % k;
      vis[d][kk]++;
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long dig = digit(a[i]);
    ans += vis[dig][a[i] % k];
    if ((a[i] * p[dig] + a[i]) % k == 0) ans--;
  }
  printf("%lld", ans);
  return 0;
}
