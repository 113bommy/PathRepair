#include <bits/stdc++.h>
using namespace std;
const long long N = 1011110;
long long secval[N], maxval[N], cnt[N];
long long n;
signed main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  long long last = 0;
  for (long long i = 1; i <= n; ++i) {
    long long u = 0;
    cin >> u;
    maxval[u] = u;
    cnt[u]++;
    last = max(last, u);
  }
  for (long long i = 2; i < N; ++i) {
    if (maxval[i] == 0) {
      maxval[i] = maxval[i - 1];
      secval[i] = secval[i - 1];
    } else {
      if (cnt[i] > 2)
        secval[i] = i;
      else
        secval[i] = maxval[i - 1];
      maxval[i] = i;
    }
  }
  for (long long i = N - 1; i >= 2; --i) cnt[i] += cnt[i + 1];
  long long ans = 0;
  for (long long y = 2; y <= last; ++y) {
    long long x, sum = 0, maxmod = -1, secmod = -1;
    for (long long k = 1; k <= last / y; ++k)
      sum += (cnt[k * y] - cnt[(k + 1) * y]) * k;
    for (long long k = last / y; k >= 0; --k) {
      long long u = (k + 1) * y - 1;
      if (maxval[u] >= k * y && maxval[u] % y >= maxmod) {
        secmod = maxmod;
        maxmod = maxval[u] % y;
      }
      if (secval[u] >= k * y && secval[u] % y > secmod) {
        secmod = secval[u] % y;
      }
      if (maxmod == -1) continue;
      x = (k * y + maxmod) / 2;
      if (min(x, sum - k) > 1) ans = max(ans, min(x, sum - k) * y);
      if (secmod == -1) continue;
      x = (k * y + secmod);
      if (min(x, sum - 2 * k) > 1) ans = max(ans, min(x, sum - 2 * k) * y);
      if (cnt[k * y + maxmod] >= 2) {
        x = (k * y + maxmod);
        if (min(x, sum - 2 * k - 1) > 1)
          ans = max(ans, min(x, sum - 2 * k - 1) * y);
      }
    }
  }
  cout << ans << endl;
}
