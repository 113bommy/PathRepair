#include <bits/stdc++.h>
const long long N = 200005;
long long n, t, a[N], x[N], b[N], max;
signed main() {
  scanf("%lld%lld", &n, &t);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &x[i]);
    if (x[i] < i) return puts("No"), 0;
  }
  for (long long i = 1; i <= n; i++) b[i] = a[i] + t;
  for (long long i = 1; i <= n; i++) {
    max = std::max(max, x[i]);
    if (max > i) b[i] = b[i + 1], ++b[i + 1];
  }
  for (long long L = 1, R = 1; L <= n; L++) {
    if (R <= L) R = L + 1;
    while (R <= n && a[R] + t <= b[R - 1]) ++R;
    if (x[L] != R - 1) return puts("-1"), 0;
  }
  puts("Yes");
  for (long long i = 1; i <= n; i++) printf("%lld ", b[i]);
  return 0;
}
