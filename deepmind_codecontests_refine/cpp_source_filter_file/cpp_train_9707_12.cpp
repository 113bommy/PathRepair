#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
long long n, k, a[N], ans[N], g;
long long dt(long long a, long long b) {
  long long k1 = b * (a - b * b);
  b++;
  long long k2 = b * (a - b * b);
  return k2 - k1;
}
long long solve(long long x) {
  long long t = 0;
  for (long long i = 1; i <= n; i++) {
    long long l = 0, r = a[i] + 1;
    while (r - l > 1) {
      long long m = l + r >> 1;
      if (dt(a[i], m) > x)
        l = m;
      else
        r = m;
    }
    ans[i] = l;
    t += l;
  }
  g = t - k;
  return g >= 0;
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long l = -8e18, r = 8e18;
  while (r - l > 1) {
    long long m = l + r >> 1;
    if (solve(m))
      l = m;
    else
      r = m;
  }
  solve(l);
  for (long long i = 1; i <= n; i++) {
    if (g && dt(a[i], ans[i]) == l + 1) g--, ans[i]--;
    cout << ans[i] << ' ';
  }
  return 0;
}
