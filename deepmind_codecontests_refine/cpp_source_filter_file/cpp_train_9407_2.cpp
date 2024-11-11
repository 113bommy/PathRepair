#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int inf = 0x7FFFFFFF;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
int sgn(double x) { return x < -eps ? -1 : x > eps; }
int main() {
  double y1, y2, yw, xb, yb, r;
  while (cin >> y1 >> y2 >> yw >> xb >> yb >> r) {
    if (sgn(y2 - y1 - 2 * r) < 0) {
      puts("-1");
      continue;
    } else {
      double y = (y1 + r), yyw = yw - r;
      double ax = (yyw - y) / (yyw - y + yyw - yb) * xb;
      double ds = (y2 - y1) * ax / (sqrt(sqr(ax) + sqr(yw - y)));
      if (sgn(ds - r) <= 0) {
        puts("-1");
        continue;
      }
      printf("%.12lf\n", ax);
    }
  }
  return 0;
}
