#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
long long n, p, ans, a[105000], pre[105000], back[105000];
signed main() {
  scanf("%lld%lld", &n, &p);
  for (long long i = 1; i <= n; i++) scanf("%lld", a + i);
  for (long long i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  for (long long i = n; i >= 1; i--) back[i] = back[i + 1] + a[i];
  for (long long i = 1; i <= n - 1; i++) {
    long long a = pre[i] % p, b = back[i + 1] % p;
    ans = max(ans, a + b);
  }
  printf("%lld\n", ans);
  return 0;
}
