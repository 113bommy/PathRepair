#include <bits/stdc++.h>
using namespace std;
int n, x[4], y[4], r[4];
inline double tr(double val) { return round(val * 1000.) / 1000.; }
set<pair<double, double> > isect[4], mer;
void add_isect(int i, int j, set<pair<double, double> >& K) {
  double e, f, p, k, q;
  e = x[i] - x[j];
  f = y[i] - y[j];
  p = sqrt(e * e + f * f);
  if (p > 0) {
    k = (p * p + r[j] * r[j] - r[i] * r[i]) / (p + p);
    if (r[j] * r[j] >= k * k) {
      q = sqrt(r[j] * r[j] - k * k) / p;
      K.insert(make_pair(tr(x[j] + (e * k) / p + f * q),
                         tr(y[j] + (f * k) / p - e * q)));
      K.insert(make_pair(tr(x[j] + (e * k) / p - f * q),
                         tr(y[j] + (f * k) / p + e * q)));
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  int i, j, k, s;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i] >> r[i];
  }
  if (n == 1) {
    cout << 2;
    return 0;
  }
  add_isect(1, 2, isect[3]);
  if (n == 2) {
    cout << (isect[3].size() == 2 ? 4 : 3);
    return 0;
  }
  add_isect(1, 3, isect[2]);
  add_isect(2, 3, isect[1]);
  for (i = 1; i <= 3; ++i) {
    if (!isect[i].empty()) break;
  }
  if (i == 4) {
    cout << 4;
    return 0;
  }
  s = (isect[i].size() == 2 ? 4 : 3);
  j = i % 3 + 1;
  k = j % 3 + 1;
  isect[j].insert(isect[k].begin(), isect[k].end());
  if (isect[j].size() < 2)
    cout << s + 1;
  else
    cout << s + isect[j].size();
  return 0;
}
