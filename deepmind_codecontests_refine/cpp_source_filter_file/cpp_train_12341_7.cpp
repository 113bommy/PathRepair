#include <bits/stdc++.h>
using namespace std;
vector<long long> x, y, z;
int t, n;
long long res[3];
long long inf = (long long)9e18;
bool ok(long long r) {
  long long be[4], en[4];
  for (int i = 0; i < 4; ++i) {
    be[i] = -inf;
    en[i] = inf;
  }
  for (int i = 0; i < n; ++i) {
    be[0] = max(be[0], -r - x[i] + y[i] + z[i]);
    be[1] = max(be[1], -r + x[i] - y[i] + z[i]);
    be[2] = max(be[2], -r + x[i] + y[i] - z[i]);
    be[3] = max(be[3], -r + x[i] + y[i] + z[i]);
    en[0] = min(en[0], r - x[i] + y[i] + z[i]);
    en[1] = min(en[1], r + x[i] - y[i] + z[i]);
    en[2] = min(en[2], r + x[i] + y[i] - z[i]);
    en[3] = min(en[3], r + x[i] + y[i] + z[i]);
  }
  long long a[3];
  for (int p = 0; p < 2; ++p) {
    for (int i = 0; i < 3; ++i) {
      a[i] = be[i];
      if ((a[i] + p) % 2 == 1) ++a[i];
    }
    if (a[0] > en[0] || a[1] > en[1] || a[2] > en[2] ||
        a[0] + a[1] + a[2] > en[3])
      continue;
    for (int i = 0; i < 3; ++i) {
      if (a[0] + a[1] + a[2] < be[3]) {
        long long d = (en[i] - a[i]) / 2;
        if (a[0] + a[1] + a[2] + d + d >= be[3])
          d = (be[3] + 1 - a[0] - a[1] - a[2]) / 2;
        a[i] += d + d;
      }
    }
    if (be[3] <= a[0] + a[1] + a[2] && a[0] + a[1] + a[2] <= en[3]) {
      res[0] = (a[1] + a[2]) / 2;
      res[1] = (a[0] + a[2]) / 2;
      res[2] = (a[0] + a[1]) / 2;
      return true;
    }
  }
  return false;
}
void solve() {
  cin >> n;
  x.resize(n);
  y.resize(n);
  z.resize(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> z[i];
  long long l = -1;
  long long r = (long long)4e18;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    (ok(mid) ? r : l) = mid;
  }
  ok(r);
  cout << res[0] << " " << res[1] << " " << res[2] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) solve();
  return 0;
}
