#include <bits/stdc++.h>
using std::cin;
using std::cout;
template <class T>
inline T abs(const T &a) {
  return a < 0 ? -a : a;
}
template <class T>
inline void mn(T &A, const T &B) {
  if (B < A) A = B;
}
inline int dcmp(const double &x) { return x > -1e-8 ? x > 1e-8 : -1; }
struct Vector {
  double x, y;
  Vector(const double &A = 0, const double &B = 0) : x(A), y(B) {}
};
inline std::istream &operator>>(std::istream &A, Vector &B) {
  A >> B.x >> B.y;
  return A;
}
inline Vector operator+(const Vector &a, const Vector &b) {
  return Vector(a.x + b.x, a.y + b.y);
}
inline Vector operator-(const Vector &a, const Vector &b) {
  return Vector(a.x - b.x, a.y - b.y);
}
inline Vector operator*(const Vector &a, const double &b) {
  return Vector(a.x * b, a.y * b);
}
inline Vector operator/(const Vector &a, const double &b) {
  return Vector(a.x / b, a.y / b);
}
inline double operator^(const Vector &a, const Vector &b) {
  return a.x * b.y - a.y * b.x;
}
inline double operator*(const Vector &a, const Vector &b) {
  return a.x * b.x + a.y * b.y;
}
inline double dis(const Vector &a, const Vector &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
struct Circle {
  Vector O;
  double R;
  Circle() {}
  Circle(const Vector &A, const double &B) : O(A), R(B) {}
};
inline std::istream &operator>>(std::istream &A, Circle &B) {
  A >> B.O >> B.R;
  return A;
}
inline Vector *intersect(const Circle &A, const Circle &B) {
  double ds = dis(A.O, B.O);
  if (A.R + B.R < ds || abs(A.R - B.R) > ds) return 0;
  Vector *ret = (Vector *)malloc(2 * sizeof(Vector));
  double Acos = (ds * ds + A.R * A.R - B.R * B.R) / (2 * ds * A.R),
         ds2 = A.R * Acos;
  Vector fx = B.O - A.O;
  Vector M = A.O + fx / ds * ds2;
  double ds3 = sqrt(A.R * A.R - ds2 * ds2);
  ret[0] = M + Vector(fx.y, -fx.x) / ds * ds3;
  ret[1] = M + Vector(-fx.y, fx.x) / ds * ds3;
  return ret;
}
Circle C[3];
Vector *tp[3];
int n, cnt = 1, tg[3];
void init() {
  cin >> n;
  for (int i = (0); i < (n); ++i) cin >> C[i];
}
int work() {
  int cnt = n + 1;
  if (n == 2)
    if ((*tp = intersect(C[0], C[1])) && dcmp(dis(tp[0][0], tp[0][1]))) ++cnt;
  if (n == 3) {
    tp[0] = intersect(C[0], C[1]);
    tp[1] = intersect(C[0], C[2]);
    tp[2] = intersect(C[1], C[2]);
    if (tp[0]) tg[0] = !dcmp(dis(tp[0][0], tp[0][1]));
    if (tp[1]) tg[1] = !dcmp(dis(tp[1][0], tp[1][1]));
    if (tp[2]) tg[2] = !dcmp(dis(tp[2][0], tp[2][1]));
    if (tp[0] && tp[1] && tp[2]) {
      int flg = 1;
      for (int i = (0); i < (1 + !tg[0]); ++i)
        for (int j = (0); j < (1 + !tg[1]); ++j)
          if (!dcmp(dis(tp[0][i], tp[1][j])))
            for (int k = (0); k < (1 + !tg[2]); ++k)
              if (!dcmp(dis(tp[0][i], tp[2][k]))) --flg;
      cnt += flg;
    }
    if (tp[0] && !tg[0]) ++cnt;
    if (tp[1] && !tg[1]) ++cnt;
    if (tp[2] && !tg[2]) ++cnt;
  }
  for (int i = (0); i < (3); ++i)
    if (tp[i]) free(tp[i]);
  return cnt;
}
int main() {
  init();
  printf("%d\n", work());
  return 0;
}
