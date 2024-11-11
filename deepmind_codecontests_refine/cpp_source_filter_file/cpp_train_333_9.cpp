#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
const long long inf = 1e18;
long long n, k, a[N], b[N] = {0, 1}, f1[N], f2[N], t[N], ans = inf;
long long min_(long long x, long long y) { return x < y ? x : y; }
signed main() {
  scanf("%lld%lld", &n, &k);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + n + 1);
  for (long long i = 1; i <= n; i++) f1[i] = f1[i - 1] + a[i];
  for (long long i = n; i >= 1; i--) f2[i] = f2[i + 1] + a[i];
  for (long long i = 2; i <= n; i++) {
    if (a[i] == a[i - 1])
      b[i] = b[i - 1];
    else
      b[i] = b[i - 1] + 1;
    t[b[i]]++;
  }
  for (long long i = 1; i <= n; i++)
    if (t[i] >= k) return printf("0"), 0;
  for (long long i = 1; i <= n; i++) {
    if (i >= k) ans = min_(ans, i * (a[i] - 1) + k - f1[i]);
    if (n - i + 1 >= k)
      ans = min_(ans, f2[i] - n + i + k + (n - i + 1) * a[i] - 1);
    ans = min_(ans, k - n + (2 * i - n - 1) * a[i] - f1[i] + f2[i]);
  }
  printf("%lld", ans);
  return 0;
}
