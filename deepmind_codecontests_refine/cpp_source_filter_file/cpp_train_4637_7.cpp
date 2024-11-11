#include <bits/stdc++.h>
using namespace std;
struct ww {
  double x, y, z;
  inline void read() { scanf("%lf%lf%lf", &x, &y, &z); }
  inline void print() { printf("%.12lf %.12lf %.12lf\n", x, y, z); }
  inline ww operator-(const ww &A) { return (ww){x - A.x, y - A.y, z - A.z}; }
  inline ww operator+(const ww &A) { return (ww){x + A.x, y + A.y, z + A.z}; }
  inline void operator/=(const double &A) { x /= A, y /= A, z /= A; }
  inline void operator*=(const double &A) { x *= A, y *= A, z *= A; }
  inline double com() { return x * x + y * y + z * z; }
  inline double suan(const ww &A) {
    ww B = {x - A.x, y - A.y, z - A.z};
    return sqrt(B.com());
  }
} a[10010], O, W;
int i, j, k, n, m;
double vp, vs, ti;
inline bool ju(int x, double L, double R) {
  ww A = W;
  A *= R;
  A = A + a[x];
  double t = O.suan(A) / vp;
  return t - (1e-10) < L + R;
}
inline void work(int x, double L, double R) {
  W = a[x + 1] - a[x];
  W /= R;
  double l = L, r = L + R, mid;
  for (; l + 1e-9 < r;) {
    mid = (l + r) / 2;
    if (ju(x, L, mid - L))
      r = mid;
    else
      l = mid;
  }
  printf("YES\n%.12lf\n", r);
  W *= r - L;
  W = W + a[x];
  W.print();
  exit(0);
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n + 1; i++) a[i].read();
  scanf("%lf%lf", &vp, &vs);
  O.read();
  for (i = 1; i <= n; i++) {
    double t = a[i].suan(a[i + 1]) / vs;
    double r = O.suan(a[i + 1]) / vp;
    if (r - (1e-10) < ti + t) work(i, ti, t);
    ti += t;
  }
  printf("NO\n");
  return 0;
}
