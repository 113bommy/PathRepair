#include <bits/stdc++.h>
using namespace std;
const double pi = atan(1.) * 4;
const double eps = 1e-9;
int x[100010], y[100010], b[100010], n;
double r[100010], a[100010];
int f(double mid) {
  int res = 0;
  vector<pair<double, int> > v;
  for (int i = 0; i < n; i++) {
    if (b[i]) {
      res++;
      continue;
    }
    if (mid * 2 < r[i] - eps) continue;
    double th = acos(r[i] / 2 / mid);
    v.push_back(make_pair(a[i] - th, 1));
    v.push_back(make_pair(a[i] + th, -1));
    v.push_back(make_pair(a[i] - th + 2 * pi, 1));
    v.push_back(make_pair(a[i] + th + 2 * pi, -1));
    v.push_back(make_pair(a[i] - th - 2 * pi, 1));
    v.push_back(make_pair(a[i] + th - 2 * pi, -1));
  }
  sort(v.begin(), v.end());
  int mx = 0, c = 0;
  for (int i = 0; i < v.size(); i++) {
    c += v[i].second;
    if (mx < c) mx = c;
  }
  return res + mx;
}
int main() {
  int k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    if (!x[i] && !y[i]) {
      b[i] = 1;
    } else {
      a[i] = atan2(y[i], x[i]);
      r[i] = sqrt(1ll * x[i] * x[i] + 1ll * y[i] * y[i]);
    }
  }
  double lo = 0, hi = 200000;
  for (int i = 0; i < 30; i++) {
    double mid = (lo + hi) / 2;
    if (f(mid) >= k) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  printf("%.12f\n", hi);
  return 0;
}
