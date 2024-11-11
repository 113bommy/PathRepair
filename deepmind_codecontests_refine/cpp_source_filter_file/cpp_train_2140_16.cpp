#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100010;
const long long inf = LONG_LONG_MAX >> 2;
long long n, m;
long long a[maxn], b[maxn];
long long ans;
int main() {
  scanf("%lld %lld", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld", a + i);
  for (long long i = 1; i <= m; i++) scanf("%lld", b + i);
  sort(b + 1, b + 1 + m);
  for (long long i = 1; i <= n; i++) {
    long long k = upper_bound(b + 1, b + 1 + m, a[i]) - b;
    long long x = k > 1 ? a[i] - b[k - 1] : inf;
    long long y = k < m ? b[k] - a[i] : inf;
    ans = max(ans, min(x, y));
  }
  printf("%lld\n", ans);
  return 0;
}
