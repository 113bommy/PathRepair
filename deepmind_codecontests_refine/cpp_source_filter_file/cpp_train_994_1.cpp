#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
inline char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
const double pi = 2 * acos(0);
struct node {
  double x, y;
};
void read(node& a) { read(a.x, a.y); }
int sgn(double x) {
  if (x == 0) return 0;
  return x > 0 ? 1 : -1;
}
node operator+(node a, node b) { return (node){a.x + b.x, a.y + b.y}; }
node operator-(node a, node b) { return (node){a.x - b.x, a.y - b.y}; }
node operator*(node a, double x) { return (node){a.x * x, a.y * x}; }
node operator/(node a, double x) { return (node){a.x / x, a.y / x}; }
node mul(node a, node b) { return (node){a.x * b.x, a.y * b.y}; }
double operator*(node a, node b) { return a.x * b.y - a.y * b.x; }
double xj(node a, node b, node c) { return (b - a) * (c - a); }
double len(node a) { return sqrt(a.x * a.x + a.y * a.y); }
bool on(node a, node b, node c) {
  if (a.x >= min(b.x, c.x) && a.x <= max(b.x, c.x) && a.y >= min(b.y, c.y) &&
      a.y <= max(b.y, c.y) && xj(b, a, c) == 0)
    return 1;
  return 0;
}
bool pdj(node a, node b, node c, node d) {
  return sgn(xj(a, c, b)) * sgn(xj(a, b, d)) > 0 &&
         sgn(xj(b, c, a)) * sgn(xj(b, a, d)) > 0 &&
         sgn(xj(c, b, d)) * sgn(xj(c, d, a)) > 0 &&
         sgn(xj(d, a, c)) * sgn(xj(d, c, b)) > 0;
}
int n, i, j, k, p, K;
double L, R;
node A, B, C, D;
double alp, w, a[11111];
const int W = 2000;
int main() {
  read(A);
  read(B);
  read(n);
  for (i = 1; i <= n; i++) {
    read(C);
    scanf("%lf%lf", &alp, &w);
    double vmax = 0, z;
    for (int cnt = (0); cnt <= (W); cnt++) {
      D = (node){(A.x + (B.x - A.x) / W * cnt), (A.y + (B.y - A.y) / W * cnt)};
      z = alp - atan2(D.y - C.y, D.x - C.x);
      while (z < 0) z += 2 * pi;
      while (z >= 2 * pi) z -= 2 * pi;
      if (z > pi) z = 2 * pi - z;
      vmax = max(vmax, len(D - A) / (z / w + 1e-12));
    }
    a[i] = vmax;
  }
  read(K);
  sort(a + 1, a + 1 + n);
  cout << fixed << setprecision(10) << a[K + 1] << endl;
  return 0;
}
