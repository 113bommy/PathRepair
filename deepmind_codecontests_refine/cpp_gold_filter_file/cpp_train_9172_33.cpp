#include <bits/stdc++.h>
using namespace std;
struct Vector {
  double x, y, z;
  Vector(){};
  Vector(double a, double b, double c) {
    x = a;
    y = b;
    z = c;
  }
  double distsq(Vector b) {
    return (this->x - b.x) * (this->x - b.x) +
           (this->y - b.y) * (this->y - b.y) +
           (this->z - b.z) * (this->z - b.z);
  }
};
double eps = 1e-7;
vector<Vector> p;
double xm, ym, zm;
double ans(Vector a) {
  double m = a.distsq(p[0]);
  for (int i = 1; i < p.size(); i++) {
    double t = a.distsq(p[i]);
    if (m < t) m = t;
  }
  return m;
}
double Z(double x, double y) {
  double zl = -zm, zr = zm;
  while (zr - zl > eps) {
    double z1 = zl + (zr - zl) / 3;
    double z2 = zl + 2 * (zr - zl) / 3;
    if (ans(Vector(x, y, z1)) < ans(Vector(x, y, z2))) {
      zr = z2;
    } else {
      zl = z1;
    }
  }
  return zl;
}
Vector Y(double x) {
  double yl = -ym, yr = ym;
  while (yr - yl > eps) {
    double y1 = yl + (yr - yl) / 3;
    double y2 = yl + 2 * (yr - yl) / 3;
    double z1 = Z(x, y1);
    double z2 = Z(x, y2);
    Vector a(x, y1, z1);
    Vector b(x, y2, z2);
    if (ans(a) < ans(b)) {
      yr = y2;
    } else {
      yl = y1;
    }
  }
  return Vector(x, yl, Z(x, yl));
}
int main() {
  int n;
  cin >> n;
  p.resize(n);
  cin >> xm >> ym >> zm;
  Vector temp(xm, ym, zm);
  p[0] = temp;
  for (int i = 1; i < n; i++) {
    double a, b, c;
    cin >> a >> b >> c;
    if (abs(a) > abs(xm)) {
      xm = a;
    }
    if (abs(b) > abs(ym)) {
      ym = b;
    }
    if (abs(c) > abs(zm)) {
      zm = c;
    }
    Vector f(a, b, c);
    p[i] = f;
  }
  xm = abs(xm);
  ym = abs(ym);
  zm = abs(zm);
  double xl = -xm, xr = xm;
  while (xr - xl > eps) {
    double x1 = xl + (xr - xl) / 3;
    double x2 = xl + 2 * (xr - xl) / 3;
    Vector a = Y(x1);
    Vector b = Y(x2);
    if (ans(a) < ans(b)) {
      xr = x2;
    } else {
      xl = x1;
    }
  }
  Vector a = Y(xl);
  cout << fixed << setprecision(10);
  cout << a.x << " " << a.y << " " << a.z << endl;
  return 0;
}
