#include <bits/stdc++.h>
using namespace std;
long long n, h, l, r, a[2005];
long long f[2005][2005];
signed main(void) {
  memset(f, -0x3f3f3f3f, sizeof f);
  scanf("%lld%lld%lld%lld", &n, &h, &l, &r);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  f[0][0] = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < h; j++) {
      f[i][j] =
          max(f[i - 1][(j - a[i] + h) % h], f[i - 1][(j - a[i] + 1 + h) % h]);
      if (j >= l && j <= r) f[i][j]++;
    }
  }
  long long ans = 0;
  for (long long i = 0; i < h; i++) {
    ans = max(ans, f[n][i]);
  }
  cout << ans;
}
