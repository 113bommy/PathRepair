#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, L;
  scanf("%d%d", &n, &L);
  vector<int> x0(n), y0(n);
  vector<double> v0(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%lf", &x0[i], &y0[i], &v0[i]);
  }
  vector<long double> l, v;
  if (x0[0] > 0) {
    l.push_back(x0[0]);
    v.push_back(0);
  }
  for (int i = 0; i < n; ++i) {
    l.push_back(y0[i] - x0[i]);
    v.push_back(v0[i]);
    if (i + 1 < n && y0[i] < x0[i + 1]) {
      l.push_back(x0[i + 1] - y0[i]);
      v.push_back(0);
    }
    if (i + 1 == n && y0[i] < L) {
      l.push_back(L - y0[i]);
      v.push_back(0);
    }
  }
  vector<long double> x(v.size(), 2), t(v.size());
  set<pair<double, int>> w;
  double bal = 0, res = 0;
  const double eps = 1e-10;
  for (int i = 0; i < v.size(); ++i) {
    w.insert(make_pair(v[i], i));
    t[i] = l[i] / (v[i] + x[i]);
    bal += t[i] * (1 - x[i]);
    res += t[i];
    while (bal < -eps) {
      assert(!w.empty());
      auto it = w.end();
      --it;
      int j = it->second;
      bal -= t[j] * (1 - x[j]);
      res -= t[j];
      if (v[j] > eps && bal + l[j] / v[j] < eps) {
        x[j] = 0;
      } else {
        x[j] = max((long double)0.,
                   min((long double)2., (l[j] + bal * v[j]) / (l[j] - bal)));
      }
      if (x[j] < eps) {
        w.erase(it);
      }
      t[j] = l[j] / (v[j] + x[j]);
      bal += t[j] * (1 - x[j]);
      res += t[j];
    }
  }
  printf("%.15lf\n", (double)res);
  return 0;
}
