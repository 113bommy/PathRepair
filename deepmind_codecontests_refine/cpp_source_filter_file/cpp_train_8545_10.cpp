#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double PI = 3.14159265359;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long sy, a, b;
  cin >> sy >> a >> b;
  int n;
  cin >> n;
  vector<pair<long long, long long>> vsegs(n);
  for (auto &p : vsegs) {
    long long x, y;
    cin >> x >> y;
    p = {x, y};
  }
  int q;
  cin >> q;
  vector<pair<long long, long long>> vpts(q);
  for (auto &p : vpts) {
    long long x, y;
    cin >> x >> y;
    p = {x, y};
  }
  vector<long long> cs(n);
  cs[0] = vsegs[0].second - vsegs[0].first;
  for (int i = 1; i < n; i++) {
    cs[i] = cs[i - 1] + vsegs[i].second - vsegs[i].first;
  }
  for (int i = 0; i < q; i++) {
    double ans = 0;
    long long x1 = vpts[i].first, y1 = vpts[i].second;
    int lpos = 0, rpos = n - 1, l = 0, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      long long x2 = vsegs[mid].first;
      long long x3y1 = (x2 - x1) * (y1 - sy) + x1 * y1;
      if (x3y1 < a * y1)
        l = mid + 1;
      else
        r = mid;
    }
    lpos = l;
    l = 0, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      long long x2 = vsegs[mid].second;
      long long x3y1 = (x2 - x1) * (y1 - sy) + x1 * y1;
      if (x3y1 < b * y1)
        l = mid + 1;
      else
        r = mid;
    }
    rpos = l;
    double scaleFac = ((double)y1 - sy) / (y1);
    if (rpos > lpos) {
      ans += cs[rpos - 1];
      if (lpos) ans -= cs[lpos];
      ans *= scaleFac;
    }
    int misl = lpos - 1, misr = rpos;
    if (misl != -1) {
      double x2 = vsegs[misl].second;
      double x3 = (double)(x1 - x2) * sy / y1 + x2;
      if (x3 > a) {
        ans += min((double)b, x3) - a;
      }
    }
    if (misr != n && misr != misl) {
      double x2 = vsegs[misr].first;
      double x3 = (double)(x1 - x2) * sy / y1 + x2;
      if (x3 < b) {
        ans += b - max(x3, (double)a);
      }
    }
    cout << setprecision(12) << ans << endl;
  }
  return 0;
}
