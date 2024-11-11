#include <bits/stdc++.h>
using namespace std;
;
const int N = 100;
const int inf = 1e9 + 7;
int n;
double R, x[N];
vector<pair<double, double> > v;
double dist(pair<double, double> a, pair<double, double> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}
int main() {
  cin >> n >> R;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    double mx = R, ml = R;
    for (int j = 0; j < ((int)v.size()); j++) {
      mx = max(mx, v[j].second + 2.0 * R);
      if (fabs(x[i] - v[j].first) <= 2.0 * R) ml = max(ml, v[j].second);
    }
    double l = ml, r = mx;
    for (int j = 1; j <= 80; j++) {
      double m = (l + r) / 2.0;
      bool fl = 1;
      for (int k = 0; k < ((int)v.size()); k++) {
        if (dist(v[k], make_pair(x[i], m)) <= (2.0 * R) * (2.0 * R)) {
          fl = 0;
        }
      }
      if (fl)
        r = m;
      else
        l = m;
    }
    v.push_back(make_pair(x[i], l));
  }
  for (auto i : v) cout << fixed << setprecision(10) << i.second << " ";
}
