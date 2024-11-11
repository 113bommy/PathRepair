#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long N = 2e5 + 100, OO = 1e9 + 7, T = 22, M = 1e9 + 7, P = 6151,
                SQ = 1300, lg = 22;
long long h[N], a[N], f[N], n, m, k, p, ct[N], mx = 0;
bool check(long long x) {
  long long cnt = 0;
  for (long long i = 1; i <= n; i++) {
    if (x >= f[i]) continue;
    cnt += (f[i] - x + p - 1) / p;
  }
  for (long long i = 0; i <= m + 1; i++) ct[i] = 0;
  if (cnt > k * (m + 1)) return false;
  for (long long i = 1; i <= n; i++) {
    if (x >= f[i]) continue;
    long long val = (f[i] - x + p - 1) / p;
    long long pos = 0, cnt = h[i];
    while (val && pos <= m) {
      if (cnt >= p) {
        val--;
        cnt -= p;
        continue;
      }
      long long g = (p - cnt + a[i] - 1) / a[i];
      if (g + pos > m) {
        cnt += (m - pos) * a[i];
        if (val > 1 || max((long long)0, cnt - p) + a[i] > x) return false;
        cnt -= (m - pos) * a[i];
        ct[min(x / a[i], m + 1)]++;
        break;
      }
      cnt += g * a[i];
      cnt -= p;
      val--;
      pos += g;
    }
  }
  for (long long i = 1; i <= m + 1; i++) {
    ct[i] += ct[i - 1];
    if (i * k < ct[i]) return false;
  }
  return true;
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> p;
  for (long long i = 1; i <= n; i++)
    cin >> h[i] >> a[i], f[i] = h[i] + a[i] * m, mx = max(mx, f[i]);
  m--;
  long long l = 0, r = mx;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << r << endl;
  return 0;
}
