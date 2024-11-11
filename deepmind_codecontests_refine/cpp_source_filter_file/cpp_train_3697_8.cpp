#include <bits/stdc++.h>
template <typename T>
inline T abs(T a) {
  return a < 0 ? -a : a;
}
template <typename T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
inline void swap(T& a, T& b) {
  T t = a;
  a = b, b = t;
}
template <typename T>
inline bool umin(T& mn, T u) {
  return u < mn ? mn = u, true : false;
}
template <typename T>
inline bool umax(T& mx, T u) {
  return u > mx ? mx = u, true : false;
}
template <typename T>
inline void read(T& r) {
  char c;
  r = 0;
  bool flag = false;
  do c = getchar();
  while (c != '-' && (c < '0' || c > '9'));
  if (c == '-') flag = true, c = getchar();
  do r = r * 10 + c - '0', c = getchar();
  while (c >= '0' && c <= '9');
  if (flag) r *= -1;
}
template <typename T1, typename T2>
inline void read(T1& r, T2& s) {
  read(r), read(s);
}
template <typename T1, typename T2, typename T3>
inline void read(T1& r, T2& s, T3& t) {
  read(r), read(s), read(t);
}
template <typename T1, typename T2, typename T3, typename T4>
inline void read(T1& r, T2& s, T3& t, T4& u) {
  read(r), read(s), read(t), read(u);
}
template <typename T>
inline void write(T w, const char* c = "") {
  if (w == 0)
    putchar('0');
  else {
    if (w < 0) putchar('-'), w *= -1;
    static int s[21], top;
    top = 0;
    while (w) s[top++] = w % 10, w /= 10;
    while (top--) putchar(s[top] + '0');
  }
  for (int i = 0; c[i]; i++) putchar(c[i]);
}
const double eps = 1e-9;
inline int dcmp(double x) { return fabs(x) < eps ? 0 : (x ? -1 : 1); }
struct Point {
  double x, y;
  Point() {}
  Point(double a, double b) : x(a), y(b) {}
  inline double length() { return sqrt(x * x + y * y); }
} P, O(0, 0), V, L;
inline Point operator-(Point A) { return Point(-A.x, -A.y); }
inline Point operator-(Point A, Point B) { return Point(A.x - B.x, A.y - B.y); }
inline double Dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }
inline double Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
inline double angle(Point A, Point B) {
  double cos = Dot(A, B) / A.length() / B.length();
  double sin = Cross(A, B) / A.length() / B.length();
  return atan2(sin, cos);
}
inline bool Onleft(Point A, Point B) { return dcmp(Cross(B, A)) > 0; }
struct Line {
  int A, B, C;
} l[2000];
inline bool parallel(Line m, Line n) { return m.A * n.B == n.A * m.B; }
Point Intersection(Line m, Line n) {
  return Point((double)(m.C * n.B - n.C * m.B) / (n.A * m.B - m.A * n.B),
               (double)(m.C * n.A - n.C * m.A) / (m.A * n.B - n.A * m.B));
}
double ang[2016];
long long ans, inians;
int main() {
  int n, i, j, tot, cnt = 0;
  bool side;
  read(n);
  for (i = 0; i < n; i++) {
    read(l[i].A, l[i].B, l[i].C), l[i].C *= -1;
    if (l[i].C == 0)
      i--, n--, cnt++;
    else if (l[i].B < 0)
      l[i].A *= -1, l[i].B *= -1, l[i].C *= -1;
  }
  if (cnt) inians = (cnt - 1ll) * cnt / 2 * n;
  for (i = 0; i < n; i++) {
    tot = 0;
    V = Point(-l[i].B, l[i].A);
    if (l[i].A == 0)
      side = l[i].C < 0;
    else
      side = ((l[i].C < 0) ^ (l[i].A < 0));
    for (j = 0; j < n; j++)
      if (j != i) {
        P = Intersection(l[i], l[j]);
        L = Point(-l[j].B, l[j].A);
        if (Onleft(L, V) ^ side)
          ang[tot++] = angle(-L, O - P);
        else
          ang[tot++] = angle(L, O - P);
      }
    std::sort(ang, ang + tot);
    ang[tot] = 8;
    for (j = cnt = 1; j <= tot; j++)
      if (dcmp(ang[j] - ang[j - 1]) == 0)
        cnt++;
      else
        ans += (cnt - 1ll) * cnt / 2, cnt = 1;
  }
  write(ans / 3 + inians);
  return 0;
}
