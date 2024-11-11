#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
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
const int maxn = 40000 + 5;
int n;
long long x[maxn], y[maxn];
long long cross(long long x0, long long y0, long long x1, long long y1,
                long long x2, long long y2) {
  return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}
long long cross(int a, int b, int c) {
  return cross(x[a], y[a], x[b], y[b], x[c], y[c]);
}
double ppDistance(double x1, double y1, double x2, double y2) {
  double dx = x1 - x2;
  double dy = y1 - y2;
  return sqrt(dx * dx + dy * dy);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x0, y0;
    scanf("%d%d", &x0, &y0);
    x[i] = x0;
    y[i] = y0;
  }
  long long area = 0;
  for (int i = 2; i < n; i++) area += cross(0, i - 1, i);
  if (area < 0)
    for (int i = 0; i < n - 1 - i; i++) {
      swap(x[i], x[n - 1 - i]);
      swap(y[i], y[n - 1 - i]);
    }
  double R = 1e100;
  for (int step = 0; step < 2; step++) {
    long long S = 0;
    int key = 1;
    for (int i = 0; i < n; i++) {
      if (i > 0) S -= cross((((i) == 0) ? (n - 1) : ((i)-1)), i, key);
      long long dx = x[(((i) == n - 1) ? (0) : ((i) + 1))] - x[i];
      long long dy = y[(((i) == n - 1) ? (0) : ((i) + 1))] - y[i];
      for (; x[(((key) == n - 1) ? (0) : ((key) + 1))] * dx +
                 y[(((key) == n - 1) ? (0) : ((key) + 1))] * dy >
             x[key] * dx + y[key] * dy;
           key = (((key) == n - 1) ? (0) : ((key) + 1)))
        S += cross(i, key, (((key) == n - 1) ? (0) : ((key) + 1)));
      double a1 = +(y[i] - y[(((i) == n - 1) ? (0) : ((i) + 1))]);
      double b1 = -(x[i] - x[(((i) == n - 1) ? (0) : ((i) + 1))]);
      double c1 = x[i] * y[(((i) == n - 1) ? (0) : ((i) + 1))] -
                  x[(((i) == n - 1) ? (0) : ((i) + 1))] * y[i];
      double a2 = dx;
      double b2 = dy;
      double c2 = -(a2 * x[key] + b2 * y[key]);
      double t = a1 * b2 - a2 * b1;
      double x0 = +(b1 * c2 - b2 * c1) / t;
      double y0 = -(a1 * c2 - a2 * c1) / t;
      checkmin(R, ppDistance(x0, y0, x[key], y[key]) *
                          ppDistance(x0, y0, x[i], y[i]) / 2.0 -
                      (double)S / 2.0);
    }
    for (int i = 0; i < n; i++) x[i] = -x[i];
    for (int i = 0; i < n - 1 - i; i++) {
      swap(x[i], x[n - 1 - i]);
      swap(y[i], y[n - 1 - i]);
    }
  }
  printf("%.18lf\n", R);
  return 0;
}
