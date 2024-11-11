#include <bits/stdc++.h>
using namespace std;
pair<double, double> operator-(pair<double, double> a, pair<double, double> b) {
  return pair<double, double>(a.first - b.first, a.second - b.second);
}
pair<double, double> st, dir;
double _w, _s, _len;
inline double f(double t) {
  double first = st.first + dir.first * t, second = st.second + dir.second * t;
  double r = atan2(second, first) - _s;
  while (r < 0) {
    r += 2 * M_PI;
  }
  while (r > 2 * M_PI) {
    r -= 2 * M_PI;
  }
  return _len * t * _w / min(r, 2 * M_PI - r);
}
double get(pair<double, double> a, pair<double, double> b, double s, double w) {
  st = a;
  dir = b - a;
  _s = s;
  _w = w;
  _len = hypot(dir.first, dir.second);
  double res = 0;
  for (int i = 0; i <= 200; i++) {
    double t = f(i / 200.);
    if (t > res) {
      res = t;
    }
  }
  return res;
}
void read(pair<double, double> &p) {
  double first, second;
  scanf("%lf%lf", &first, &second);
  p.first = first;
  p.second = second;
}
int main(void) {
  pair<double, double> a, b;
  read(a);
  read(b);
  int n;
  scanf("%d", &n);
  vector<double> v(1, 0);
  for (int i = 0; i < n; i++) {
    pair<double, double> p;
    read(p);
    double s, w;
    scanf("%lf%lf", &s, &w);
    v.push_back(get(a - p, b - p, s, w));
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int k;
  scanf("%d", &k);
  printf("%.20lf\n", v[k]);
  return 0;
}
