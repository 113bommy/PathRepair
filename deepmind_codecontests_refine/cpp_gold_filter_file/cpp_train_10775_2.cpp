#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long OO = 0x3f3f3f3f3f3f3f3fLL;
const int M7 = 1000000007;
const int M9 = 1000000009;
const long long M7L = 1000000007L;
template <typename T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <typename T, typename... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <typename T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
template <typename T>
void _W(const vector<T> &x) {
  for (auto i = x.cbegin(); i != x.cend(); i++) {
    if (i != x.cbegin()) putchar(' ');
    _W(*i);
  }
}
void W() {}
template <typename T, typename... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return b > a ? a = b, true : false;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return b < a ? a = b, true : false;
}
struct Point {
  long double x, y;
  Point operator-(const Point &op) const { return {x - op.x, y - op.y}; }
  long double operator^(const Point &op) const { return x * op.y - op.x * y; }
};
inline int dcmp(long double x) {
  if (x < -1e-8) return -1;
  return x > 1e-8;
}
ostream &operator<<(ostream &os, const Point &op) {
  os << "(" << op.x << ", " << op.y << ")";
  return os;
}
long double abs(const Point &a) { return sqrt(a.x * a.x + a.y * a.y); }
long double dist(const Point &a, const Point &b) { return abs(b - a); }
long double cross(const Point &o, const Point &a, const Point &b) {
  return (a - o) ^ (b - o);
}
long double cosLaw(long double a, long double b, long double c) {
  return (a * a + b * b - c * c) / (2 * a * b);
}
Point a, b;
long double r1, r2;
int main(int argc, char *argv[]) {
  long double t1, t2, d;
  long double area = 0;
  R(a.x, a.y, r1, b.x, b.y, r2);
  if (r2 > r1) {
    swap(r1, r2);
    swap(a.x, b.x);
    swap(a.y, b.y);
  }
  d = dist(a, b);
  ;
  ;
  if (r1 + r2 <= d) {
    goto END;
  }
  if (r1 >= r2 + d) {
    area = acos(-1.0) * r2 * r2;
    goto END;
  }
  t1 = acos(cosLaw(r1, d, r2));
  t2 = acos(cosLaw(r2, d, r1));
  area += r1 * r1 * (t1 - abs(sin(t1) * cos(t1)));
  area += r2 * r2 *
          (t2 -
           abs(sin(t2) * cos(t2)) * ((dcmp(acos(-1.0) / 2 - t2) > 0) ? 1 : -1));
END:
  printf("%.12lf\n", (double)area);
  return 0;
}
