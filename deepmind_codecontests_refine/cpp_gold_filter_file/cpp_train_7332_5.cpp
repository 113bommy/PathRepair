#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > v;
int pop;
bool fun(long double t) {
  int tmp = 0;
  for (int i = 0; i < (v.size()); i++) {
    long double d = sqrt(((v[i].second.first * v[i].second.first) +
                          (v[i].second.second * v[i].second.second)) *
                         1.);
    if (t < d)
      continue;
    else {
      tmp += v[i].first;
    }
  }
  return (tmp + pop >= 1000000 ? true : false);
}
int main() {
  int n, x, y, tot, lo, hi = -999999999, neg = 0;
  long double mid, l, h;
  cin >> n >> pop;
  v.clear();
  for (int i = 0; i < (n); i++) {
    cin >> x >> y >> tot;
    neg += tot;
    hi = max(hi, abs(x));
    hi = max(hi, abs(y));
    v.push_back(make_pair(tot, make_pair(x, y)));
  }
  if (neg + pop < 1000000) {
    cout << "-1\n";
    return 0;
  }
  h = 200000.;
  l = 0.;
  while (h - l > 1e-6) {
    mid = l + (h - l) / 2.;
    if (fun(mid))
      h = mid;
    else
      l = mid;
  }
  cout.precision(10);
  cout << l << "\n";
}
