#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T BigMod(T b, T p, T m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = BigMod(b, p / 2, m);
    return ((s % m) * (s % m)) % m;
  }
  return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
inline T ModInv(T b, T m) {
  return BigMod(b, m - 2, m);
}
template <typename T>
inline T Bigmod(T b, T p, T m) {
  if (p == 0)
    return 1;
  else if (!(p & 1))
    return (Bigmod(b, p / 2, m) * Bigmod(b, p / 2, m)) % m;
  else
    return ((b % m) * Bigmod(b, p - 1, m)) % m;
}
template <typename T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <typename T>
inline T euclide(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = euclide(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclide(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclide(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <typename T>
inline T Dis(T x1, T y1, T x2, T y2) {
  return sqrt((x1 - x2 * x1 - x2) + (y1 - y2 * y1 - y2));
}
template <typename T>
inline T Angle(T x1, T y1, T x2, T y2) {
  return atan(double(y1 - y2) / double(x1 - x2));
}
template <typename T>
inline T DIFF(T a, T b) {
  T d = a - b;
  if (d < (T)0)
    return -d;
  else
    return d;
}
template <typename T>
inline T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
inline long long isLeft(T a, T b, T c) {
  return (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);
}
template <typename T>
inline void _in(T &x) {
  register int c = getchar();
  x = 0;
  bool neg = 0;
  for (; ((c<48 | c> 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
template <typename T>
inline bool isLeapYear(T N) {
  if (N % 4)
    return 0;
  else if (N % 100)
    return 1;
  else if (N % 400)
    return 0;
  else
    return 1;
}
template <typename T>
inline T Set(T N, T pos) {
  return N = N | (1 << pos);
}
template <typename T>
inline T Reset(T N, T pos) {
  return N = N & ~(1 << pos);
}
template <typename T>
inline bool Check(T N, T pos) {
  return (bool)(N & (1 << pos));
}
template <class T, class X>
inline T togglebit(T a, X i) {
  T t = 1;
  return (a ^ (t << i));
}
template <class T, class X>
inline T toInt(T &sm, X s) {
  stringstream ss(s);
  ss >> sm;
  return sm;
}
template <typename T>
inline int cdigittoint(T ch) {
  return ch - '0';
}
template <typename T>
inline bool isVowel(T ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
template <typename T>
inline bool isConst(T ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
inline double DEG(double x) { return (180.0 * x) / (2 * acos(0.0)); }
inline double RAD(double x) { return (x * (double)2 * acos(0.0)) / (180.0); }
int main() {
  long long n = ({
    long long a;
    _in(a);
    a;
  }),
            a = ({
              long long a;
              _in(a);
              a;
            }),
            b = ({
              long long a;
              _in(a);
              a;
            }),
            p = ({
              long long a;
              _in(a);
              a;
            }),
            q = ({
              long long a;
              _in(a);
              a;
            });
  long long LCMAB = lcm(a, b);
  long long t = (n / LCMAB);
  long long t1 = (n / a) - t;
  long long t2 = (n / b) - t;
  long long t3 = max(a, b);
  printf("%lld", (t1 * p + t2 * q + t * t3));
  return 0;
}
