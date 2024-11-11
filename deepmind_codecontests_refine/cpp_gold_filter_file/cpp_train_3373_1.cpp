#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC target("avx")
using namespace std;
inline char gc() {
  static char buf[1 << 16], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 1 << 16, stdin);
    if (p2 == p1) return EOF;
  }
  return *p1++;
}
template <class t>
inline t read(t &x) {
  char c = gc();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = gc();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const double eps = 1e-9;
const double pi = acos(-1);
struct point {
  double x, y;
  inline void read() { scanf("%lf%lf", &x, &y); }
  inline point operator+(const point &nt) const {
    return (point){x + nt.x, y + nt.y};
  }
  inline point operator-(const point &nt) const {
    return (point){x - nt.x, y - nt.y};
  }
  inline point operator*(const double &nt) const {
    return (point){x * nt, y * nt};
  }
  inline double length() { return sqrt(x * x + y * y); }
} x, y;
double distance(point x, point y) {
  return sqrt((y.x - x.x) * (y.x - x.x) + (y.y - x.y) * (y.y - x.y));
}
struct segment {
  point x, y;
  inline void read() {
    x.read();
    y.read();
  }
  inline double length() { return distance(x, y); }
} a, b;
struct line {
  point x, y;
  inline void read() {
    x.read();
    y.read();
  }
};
double DJ(point x, point y) { return x.x * y.x + x.y * y.y; }
double CJ(point x, point y) { return x.x * y.y - x.y * y.x; }
point trpoint(segment x) { return x.y - x.x; }
point trpoint(line x) { return x.y - x.x; }
double prolen(point x, segment a) {
  return DJ(trpoint((segment){a.x, x}), trpoint(a)) / a.length();
}
point propoint(point x, segment a) {
  return a.x + trpoint(a) * (prolen(x, a) / a.length());
}
point refpoint(point x, segment a) { return x + (propoint(x, a) - x) * 2; }
bool orthline(line x, line y) { return DJ(trpoint(x), trpoint(y)) == 0; }
bool paraline(line x, line y) { return CJ(trpoint(x), trpoint(y)) == 0; }
bool interseg(segment x, segment y) {
  return min(x.x.x, x.y.x) <= max(y.x.x, y.y.x) &&
         min(y.x.x, y.y.x) <= max(x.x.x, x.y.x) &&
         min(x.x.y, x.y.y) <= max(y.x.y, y.y.y) &&
         min(y.x.y, y.y.y) <= max(x.x.y, x.y.y) &&
         CJ(y.x - x.x, y.y - x.x) * CJ(y.x - x.y, y.y - x.y) <= 0 &&
         CJ(x.x - y.x, x.y - y.x) * CJ(x.x - y.y, x.y - y.y) <= 0;
}
double dispointline(point x, segment y) { return distance(x, propoint(x, y)); }
point crossseg(segment x, segment y) {
  double a = dispointline(x.x, y), b = dispointline(x.y, y);
  return x.x + (x.y - x.x) * (a / (a + b));
}
bool direct() {
  return !interseg((segment){x, y}, a) && !interseg((segment){x, y}, b);
}
bool reflect() {
  point z = refpoint(x, b), mid = crossseg((segment){z, y}, b);
  return !interseg((segment){x, y}, b) && interseg((segment){z, y}, b) &&
         !interseg((segment){x, mid}, a) && !interseg((segment){y, mid}, a);
}
bool check() { return !interseg((segment){x, y}, a); }
signed main() {
  x.read();
  y.read();
  a.read();
  b.read();
  if (distance(x, b.x) + distance(b.y, y) ==
          distance(x, y) - distance(b.x, b.y) ||
      distance(x, b.y) + distance(b.x, y) ==
          distance(x, y) - distance(b.x, b.y)) {
    if (check())
      puts("YES");
    else
      puts("NO");
    return 0;
  }
  if (direct() || reflect())
    puts("YES");
  else
    puts("NO");
}
