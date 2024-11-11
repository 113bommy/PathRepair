#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const double eps = 1e-11;
int sgn(double x) { return x > eps ? 1 : (x < -eps ? -1 : 0); }
struct Vector {
  double x, y;
  Vector(double _x = 0, double _y = 0) : x(_x), y(_y) {}
  Vector operator+(const Vector &rhs) const {
    return Vector(x + rhs.x, y + rhs.y);
  }
  Vector operator-(const Vector &rhs) const {
    return Vector(x - rhs.x, y - rhs.y);
  }
  Vector operator*(const double &rhs) const { return Vector(x * rhs, y * rhs); }
  Vector operator/(const double &rhs) const { return Vector(x / rhs, y / rhs); }
  double operator*(const Vector &rhs) const { return x * rhs.x + y * rhs.y; }
  double operator^(const Vector &rhs) const { return x * rhs.y - rhs.x * y; }
  int read() { return scanf("%lf%lf", &x, &y); }
  int pri() { return printf("P:%.2f %.2f\n", x, y); }
};
struct Polygon {
  int siz;
  vector<Vector> cor;
  vector<Vector> tx;
  void init() {
    cor.clear();
    tx.clear();
    siz = 0;
  }
  void read(int _n) {
    siz = _n;
    cor.resize(siz);
    for (int i = 0; i < siz; i++) {
      cor[i].read();
      tx.push_back(cor[i] - cor[0]);
    }
  }
};
int N;
Polygon A;
bool PointInPolygon(Vector &, Polygon &);
int main() {
  while (~scanf("%d", &N)) {
    A.init();
    A.read(N);
    scanf("%d", &N);
    Vector tem;
    bool ok = 1;
    for (int i = 0; i < N; i++) {
      tem.read();
      ok &= PointInPolygon(tem, A);
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
bool PointInPolygon(Vector &p, Polygon &poly) {
  if (poly.siz < 3) return 0;
  Vector tp = p - poly.cor[0];
  if (sgn(tp ^ poly.tx[1]) <= 0) return 0;
  if (sgn(tp ^ poly.tx[poly.siz - 1]) >= 0) return 0;
  int l = 1, r = poly.siz - 2, mid;
  while (l < r) {
    mid = (l + r + 1) >> 1;
    if (sgn(tp ^ poly.tx[mid]) >= 0)
      l = mid;
    else
      r = mid - 1;
  }
  return sgn((p - poly.cor[l]) ^ (poly.cor[l + 1] - poly.cor[l])) > 0;
}
