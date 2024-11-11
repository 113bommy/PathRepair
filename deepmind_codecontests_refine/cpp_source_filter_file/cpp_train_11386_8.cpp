#include <bits/stdc++.h>
using namespace std;
int ts, kk = 1, _DB = 1;
inline int LEN(string a) { return a.length(); }
inline int LEN(char a[]) { return strlen(a); }
template <class T>
inline T _abs(T n) {
  return (n < 0 ? -n : n);
}
template <class T>
inline T _max(T a, T b) {
  return (a > b ? a : b);
}
template <class T>
inline T _min(T a, T b) {
  return (a < b ? a : b);
}
template <class T>
inline T _sq(T x) {
  return x * x;
}
template <class T>
inline T _sqrt(T x) {
  return (T)sqrt((double)x);
}
template <class T>
inline T _pow(T x, T y) {
  T z = 1;
  for (int i = 1; i <= y; i++) {
    z *= x;
  }
  return z;
}
template <class T>
inline T _gcd(T a, T b) {
  a = _abs(a);
  b = _abs(b);
  if (!b) return a;
  return _gcd(b, a % b);
}
template <class T>
inline T _lcm(T a, T b) {
  a = _abs(a);
  b = _abs(b);
  return (a / _gcd(a, b)) * b;
}
template <class T>
inline T _extended(T a, T b, T &x, T &y) {
  a = _abs(a);
  b = _abs(b);
  T g, x1, y1;
  if (!b) {
    x = 1;
    y = 0;
    g = a;
    return g;
  }
  g = _extended(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
template <class T>
inline T getbit(T x, T i) {
  T t = 1;
  return (x & (t << i));
}
template <class T>
inline T setbit(T x, T i) {
  T t = 1;
  return (x | (t << i));
}
template <class T>
inline T resetbit(T x, T i) {
  T t = 1;
  return (x & (~(t << i)));
}
template <class T>
inline T _bigmod(T n, T m) {
  T ans = 1, mult = n % 1000000007;
  while (m) {
    if (m & 1) ans = (ans * mult) % 1000000007;
    m >>= 1;
    mult = (mult * mult) % 1000000007;
  }
  ans %= 1000000007;
  return ans;
}
template <class T>
inline T _modinv(T x) {
  return _bigmod(x, (T)(1000000007 - 2)) % 1000000007;
}
struct point {
  long long x, y;
};
inline long long isleft(point p0, point p1, point p2) {
  return ((p0.x - p1.x) * (p1.y - p2.y) - (p0.y - p1.y) * (p1.x - p2.x));
}
inline double dist(point a, point b) {
  return sqrt((double)(_sq(a.x - b.x) + _sq(a.y - b.y)));
}
int main() {
  long long y1, y2, yw, xb, yb, r, area;
  point A, B, C;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  A.x = 0;
  A.y = 2 * (yw - r) - (y1 + r);
  C.x = 0;
  C.y = 2 * (yw - r) - y2;
  B.x = xb;
  B.y = yb;
  area = _abs(isleft(A, B, C));
  double height = 2.0 * ((double)area) / dist(A, B);
  if ((height + 1e-9 < ((double)r)))
    cout << -1 << endl;
  else {
    double xw, yw, x1, y1, x2, y2;
    x1 = A.x;
    y1 = A.y;
    x2 = B.x;
    y2 = B.y;
    yw = yw - ((double)r);
    xw = (((yw - y1) * (x1 - x2)) / (y1 - y2)) + x1;
    cout << setprecision(10) << fixed << xw << endl;
  }
  return 0;
}
