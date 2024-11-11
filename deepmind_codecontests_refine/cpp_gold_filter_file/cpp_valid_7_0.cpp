#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
long long t, n, ans;
long long a[N], b[N], v[N], l[N];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
signed main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    ans = 0ll;
    for (long long i = 1; i <= n; ++i) scanf("%lld", &b[i]);
    for (long long i = 1; i < n; ++i) a[i] = abs(b[i + 1] - b[i]);
    --n;
    for (long long i = 1; i <= n; ++i) {
      v[i] = a[i];
      l[i] = i;
    }
    for (long long i = 1; i <= n; ++i)
      for (long long j = i; j; j = l[j] - 1) {
        v[j] = gcd(v[j], a[i]);
        while (l[j] > 1 && gcd(a[i], v[l[j] - 1]) == v[j]) l[j] = l[l[j] - 1];
        if (v[j] > 1) ans = max(ans, i - l[j] + 1);
      }
    printf("%lld\n", ans + 1);
  }
  return 0;
}
