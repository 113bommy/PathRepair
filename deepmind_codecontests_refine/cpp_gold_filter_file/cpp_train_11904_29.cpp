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
double p(double a, double b) {
  if (abs(a) < 1e-17) return -1e50;
  return log(a) * b;
}
int main() {
  double S;
  int a, b, c;
  while (cin >> S >> a >> b >> c) {
    double dx = S / 30, pdx = S;
    double ax = 0, ay = 0, px, py;
    double tans = -1e100;
    for (int t = 0; t < 1000; t++) {
      dx = (pdx + pdx) / 100;
      double mnx = min(S + eps, ax + pdx + eps),
             mny = min(S + eps, ay + pdx + eps);
      for (double x = max(ax - pdx, 0.0); x <= mnx; x += dx) {
        for (double y = max(ay - pdx, 0.0); y <= mny; y += dx) {
          if (x + y > S) continue;
          double z = S - x - y;
          double tt = p(x, a) + p(y, b) + p(z, c);
          if (tans < tt) {
            tans = tt;
            px = x, py = y;
          }
        }
      }
      if (dx < 1e-10) break;
      ax = px, ay = py;
      pdx = pdx * 4 / 5;
    }
    printf("%.16lf %.16lf %.16lf\n", px, py, S - px - py);
  }
  return 0;
}
