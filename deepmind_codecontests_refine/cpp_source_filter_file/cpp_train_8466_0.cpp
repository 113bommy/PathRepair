#include <bits/stdc++.h>
using namespace std;
const long long o = 1e4 + 1;
long long n, m, q, a[o], b[o];
long long qwq(long long x) {
  long long s = 0;
  for (long long i = 1; i <= n; i++) {
    if (x * a[i] > b[i] * (m + 100)) return m + 1000;
    s += 1 + x * a[i] / b[i];
  }
  return s;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  bool q = 1;
  long long x, y;
  for (long long i = 1; i <= n; i++) cin >> a[i] >> b[i], q &= !a[i];
  if (q) return cout << (n == m ? -1 : 0), 0;
  long long l = 1, r = 1e18;
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    if (qwq(mid) > m)
      r = mid - 1;
    else
      l = mid;
  }
  if (qwq(l) != m) return cout << 0, 0;
  x = l, l = 1, r = 1e18;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (qwq(mid) < m)
      l = mid + 1;
    else
      r = mid;
  }
  y = l;
  cout << max(0ll, x - y + 1);
  return 0;
}
