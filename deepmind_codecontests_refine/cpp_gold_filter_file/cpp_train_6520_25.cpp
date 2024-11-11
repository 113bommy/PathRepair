#include <bits/stdc++.h>
using namespace std;
struct vect3D {
  double x, y, z;
  vect3D() {}
  vect3D(double x, double y, double z) : x(x), y(y), z(z){};
  vect3D operator+(vect3D const &T) const {
    return vect3D(x + T.x, y + T.y, z + T.z);
  }
  vect3D operator-(vect3D const &T) const {
    return vect3D(x - T.x, y - T.y, z - T.z);
  }
  vect3D operator*(double const &t) const {
    return vect3D(x * t, y * t, z * t);
  }
  double operator%(vect3D const &T) const {
    return x * T.x + y * T.y + z * T.z;
  }
  vect3D operator^(vect3D const &T) const {
    return vect3D(y * T.z - z * T.y, z * T.x - x * T.z, x * T.y - y * T.x);
  }
  double len() { return sqrt(x * x + y * y + z * z); }
  void get() { scanf("%lf%lf%lf", &x, &y, &z); }
};
int n, m;
vect3D A, v, O, p;
double R, r, ret;
double fdis(vect3D O, vect3D A, vect3D v, double k) {
  return (O - (A + (v * k))).len();
}
double fdis2(vect3D O, vect3D p, vect3D A, vect3D v, double k) {
  vect3D u = A + (v * k);
  double ret = min((u - p).len(), (u - O).len());
  if (((u - O) % (p - O)) >= 0 && ((u - p) % (O - p)) >= 0) {
    ret = min(ret, ((O - p) ^ (u - p)).len() / (O - p).len());
  }
  return ret;
}
double getmin(vect3D O, double R, vect3D A, vect3D v, double r) {
  int itr = 0;
  double d1, d2, k1, k2, T;
  for (double i = 0, j = 1e9, k1, k2; itr < 200; itr++) {
    k1 = i + (j - i) / 3.;
    k2 = j - (j - i) / 3.;
    d1 = fdis(O, A, v, k1);
    d2 = fdis(O, A, v, k2);
    if (d1 < d2)
      j = k2;
    else
      i = k1;
    T = (i + j) / 2.;
  }
  if (fdis(O, A, v, T) > R + r + 1e-14) return 1e100;
  double ret = T;
  itr = 0;
  for (double i = 0, j = T, k; itr < 200; itr++) {
    k = (i + j) / 2.;
    if (fdis(O, A, v, k) <= R + r)
      ret = j = k;
    else
      i = k;
  }
  return ret;
}
double getmin2(vect3D O, vect3D p, vect3D A, vect3D v, double r) {
  int itr = 0;
  double d1, d2, k1, k2, T;
  for (double i = 0, j = 1e9, k1, k2; itr < 200; itr++) {
    k1 = i + (j - i) / 3.;
    k2 = j - (j - i) / 3.;
    d1 = fdis2(O, p, A, v, k1);
    d2 = fdis2(O, p, A, v, k2);
    if (d1 < d2)
      j = k2;
    else
      i = k1;
    T = (i + j) / 2.;
  }
  if (fdis2(O, p, A, v, T) > r + 1e-14) return 1e100;
  double ret = T;
  itr = 0;
  for (double i = 0, j = T, k; itr < 200; itr++) {
    k = (i + j) / 2.;
    if (fdis2(O, p, A, v, k) + 1e-14 <= r)
      ret = j = k;
    else
      i = k;
  }
  return ret;
}
int main() {
  A.get();
  v.get();
  scanf("%lf", &r);
  ret = 1e100;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    O.get();
    scanf("%lf%d", &R, &m);
    ret = min(ret, getmin(O, R, A, v, r));
    while (m--) {
      p.get();
      ret = min(ret, getmin2(O, O + p, A, v, r));
    }
  }
  if (ret >= 1e99)
    printf("-1\n");
  else
    printf("%.9f\n", ret);
  return 0;
}
