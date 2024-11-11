#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 6, mod = (int)0;
complex<double> p[N], o;
complex<double> rotate(complex<double> x, complex<double> a,
                       complex<double> b) {
  return (x - a) / polar(1.0, arg(b - a));
}
int n;
double cross(complex<double> a, complex<double> b) {
  return a.real() * b.imag() - a.imag() * b.real();
}
double area(complex<double> a, complex<double> b) {
  return abs(cross(a - o, b - o)) / 2;
}
double solve() {
  int best = n;
  double res = 1e9, cur_area = 0;
  for (int cur = n; cur < n + n; ++cur) {
    int pr = cur - 1;
    while (best < cur) cur_area += area(p[best], p[best + 1]), best++;
    while (rotate(p[best], p[cur], p[pr]).real() >
           rotate(p[best + 1], p[cur], p[pr]).real())
      cur_area += area(p[best], p[best + 1]), best++;
    complex<double> rotated = rotate(p[best], p[cur], p[pr]);
    res = min(res, -cur_area + area(p[cur], p[best]) +
                       abs(rotated.real() * rotated.imag()) / 2);
    cur_area -= area(p[cur], p[cur + 1]);
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int j = 0; j < n; ++j) {
    int x, y;
    cin >> x >> y;
    p[j] = complex<double>(x, y);
    o += p[j];
  }
  o /= n;
  for (int j = n; j < n + n + n; ++j) p[j] = p[j - n];
  double res = solve();
  reverse(p, p + 3 * n);
  res = min(res, solve());
  cout << setprecision(7) << fixed << res << endl;
}
