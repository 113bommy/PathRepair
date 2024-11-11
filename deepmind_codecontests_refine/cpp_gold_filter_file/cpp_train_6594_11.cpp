#include <bits/stdc++.h>
using namespace std;
const long long N = 40;
long long ans = -(1ll << 60), n, u, r, a[N], b[N], k[N], p[N];
inline void update() {
  long long tem = 0;
  for (long long i = 1; i <= n; i++) tem += a[i] * k[i];
  ans = max(ans, tem);
}
inline void dfs(long long pos, long long valid) {
  if (pos > u || (u - pos + 1) % 2 == 0) update();
  if (pos > u) return;
  long long tem[N];
  memcpy(tem, a, sizeof(a));
  for (long long i = 1; i <= n; i++) a[i] = tem[p[i]] + r;
  dfs(pos + 1, 1);
  memcpy(a, tem, sizeof(a));
  if (valid) {
    for (long long i = 1; i <= n; i++) a[i] ^= b[i];
    dfs(pos + 1, 0);
    memcpy(a, tem, sizeof(a));
  }
}
signed main() {
  scanf("%lld%lld%lld", &n, &u, &r);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (long long i = 1; i <= n; i++) scanf("%lld", &b[i]);
  for (long long i = 1; i <= n; i++) scanf("%lld", &k[i]);
  for (long long i = 1; i <= n; i++) scanf("%lld", &p[i]);
  dfs(1, 1);
  printf("%lld\n", ans);
  return 0;
}
