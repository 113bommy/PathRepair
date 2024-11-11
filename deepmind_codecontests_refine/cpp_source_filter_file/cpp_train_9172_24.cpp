#include <bits/stdc++.h>
using namespace std;
struct p {
  double x;
  double y;
  double z;
};
long long n;
vector<p> a;
double pow(double s) { return s * s; }
double dist(double x, double y, double z) {
  double d = -1e9;
  for (long long i = 0; i < n; i++)
    d = max(d, sqrt(pow(a[i].x - x) + pow(a[i].y - y) + pow(a[i].z - z)));
  return d;
}
double poz(double x, double y) {
  double l = -1e4, r = 1e4;
  for (long long i = 0; i < 50; i++) {
    double s = l + (r - l) / 3;
    double q = l + 2 * (r - l) / 3;
    if (dist(x, y, s) < dist(x, y, q))
      r = q;
    else
      l = s;
  }
  return l;
}
pair<double, double> poy(double x) {
  double l = -1e4, r = 1e4;
  for (long long i = 0; i < 50; i++) {
    double s = l + (r - l) / 3;
    double q = l + 2 * (r - l) / 3;
    double tmp1 = poz(x, s);
    double tmp2 = poz(x, q);
    if (dist(x, s, tmp1) < dist(x, q, tmp2))
      r = q;
    else
      l = s;
  }
  return {l, poz(x, l)};
}
double pox() {
  double l = -1e4, r = 1e4;
  for (long long i = 0; i < 50; i++) {
    double s = l + (r - l) / 3;
    double q = l + 2 * (r - l) / 3;
    pair<double, double> tmp1 = poy(s);
    pair<double, double> tmp2 = poy(q);
    if (dist(s, tmp1.first, tmp1.second) < dist(q, tmp2.first, tmp2.second))
      r = q;
    else
      l = s;
  }
  return l;
}
signed main() {
  cin >> n;
  a.resize(n);
  for (long long i = 0; i < n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
  double x = pox();
  pair<double, double> tmp = poy(x);
  cout << fixed << setprecision(10) << x << " " << tmp.first << " "
       << tmp.second;
  return 0;
}
