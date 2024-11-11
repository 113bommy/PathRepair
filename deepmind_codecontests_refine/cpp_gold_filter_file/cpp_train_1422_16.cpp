#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, i, j, k;
  long double t, s = 0, v = 0, ss, vv, EPS = 1E-10, x, a, b, c;
  cin >> n >> t;
  vector<long double> aa(n), tt(n);
  vector<pair<long double, long double>> pp;
  for (i = 0; i < n; i++) cin >> aa[i];
  for (i = 0; i < n; i++) {
    cin >> tt[i];
    s += tt[i] * aa[i];
    v += aa[i];
    pp.push_back({tt[i], aa[i]});
  }
  sort(pp.rbegin(), pp.rend());
  if (s / v >= t + EPS) {
    for (i = 0; i < n; i++) {
      ss = s - pp[i].first * pp[i].second;
      vv = v - pp[i].second;
      if (ss / vv >= t + EPS) {
        s = ss;
        v = vv;
      } else {
        a = 0;
        b = pp[i].second;
        while (abs(a - b) > EPS) {
          c = (a + b) / 2;
          ss = s - pp[i].first * c;
          vv = v - c;
          if (ss / vv >= t + EPS)
            a = c;
          else
            b = c;
        }
        s -= a * pp[i].first;
        v -= a;
        break;
      }
    }
  } else if (s / v <= t - EPS) {
    for (i = n - 1; i >= 0; i--) {
      ss = s - pp[i].first * pp[i].second;
      vv = v - pp[i].second;
      if (ss / vv <= t - EPS) {
        s = ss;
        v = vv;
      } else {
        a = 0;
        b = pp[i].second;
        while (abs(a - b) > EPS) {
          c = (a + b) / 2;
          ss = s - pp[i].first * c;
          vv = v - c;
          if (ss / vv <= t - EPS)
            a = c;
          else
            b = c;
        }
        s -= a * pp[i].first;
        v -= a;
        break;
      }
    }
  }
  cout << setprecision(10) << fixed << v << "\n";
  return 0;
}
