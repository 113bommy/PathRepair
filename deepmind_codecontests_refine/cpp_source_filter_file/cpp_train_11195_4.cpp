#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 1000 + 10;
int a[2], b[2], t[2];
int p[maxn][2];
long double power2(long long x) { return 1.0 * x * x; }
long double get_dist(int p1[], int p2[]) {
  return sqrt(power2(p1[0] - p2[0]) + power2(p1[1] - p2[1]));
}
pair<long double, int> da[maxn], db[maxn];
int main() {
  cout << fixed << setprecision(8);
  cin >> a[0] >> a[1];
  cin >> b[0] >> b[1];
  cin >> t[0] >> t[1];
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> p[i][0] >> p[i][1];
  long double ans = 0.0;
  for (int i = 0; i < n; ++i) ans += 2 * get_dist(p[i], t);
  for (int i = 0; i < n; ++i) {
    da[i] = make_pair(get_dist(p[i], t) - get_dist(p[i], a), i);
    db[i] = make_pair(get_dist(p[i], t) - get_dist(p[i], b), i);
  }
  sort(da, da + n);
  sort(db, db + n);
  if (n == 1) {
    cout << ans - max(da[n - 1].first, db[n - 1].first) << endl;
  }
  if (da[n - 1].second == db[n - 1].second) {
    long double together = ans - max(da[n - 1].first + db[n - 2].first,
                                     da[n - 2].first + db[n - 1].first);
    long double output =
        min(together, min(ans - da[n - 1].first, ans - db[n - 1].first));
    cout << output << endl;
  } else {
    long double together = ans - da[n - 1].first - db[n - 1].first;
    long double output =
        min(together, min(ans - da[n - 1].first, ans - db[n - 1].first));
    cout << output << endl;
  }
}
