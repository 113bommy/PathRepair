#include <bits/stdc++.h>
using namespace std;
const int BUF = 1000000;
char buf[BUF], *p1, *p2;
inline char getChar() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, BUF, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long f = 0;
  char c;
  while (!isdigit(c = getChar())) {
  }
  do f = f * 10 + (c ^ 48);
  while (isdigit(c = getChar()));
  return f;
}
const int maxN = 100003, mod = 1e6;
long long m;
struct Vector {
  long long x, y;
  Vector() {}
  Vector(long long x, long long y) : x(x), y(y) {}
  friend bool operator<(const Vector& a, const Vector& b) { return a.x < b.x; }
} now;
set<Vector> hull;
set<Vector>::iterator it, L, R, tmp;
inline bool convex(Vector a, Vector b, Vector c) {
  return (b.y - a.y) * (c.x - b.x) >= (c.y - b.y) * (b.x - a.x);
}
inline bool check(Vector a, Vector b, long long x, long long y) {
  return m * (b.x - a.x) >= (a.y * b.x - b.y * a.x) * x + (b.y - a.y) * y;
}
int main() {
  int n = read(), i, x, y, lst = 0;
  m = read();
  hull.insert(Vector(0, 0));
  for (i = 1; i <= n; ++i) {
    if (read() == 1) {
      x = (read() + lst) % mod + 1, y = (read() + lst) % mod + 1,
      now = Vector(x, y);
      R = hull.lower_bound(now);
      if (R != hull.end()) {
        if ((*R).x == x) {
          if (y >= (*R).y) continue;
          hull.erase(R), R = hull.lower_bound(now);
          if (R == hull.end()) goto GG;
        }
        L = hull.upper_bound(now), --L;
        if (!convex(*L, now, *R)) {
          if (L != hull.begin()) {
            it = L, --it;
            while (L != hull.begin() && convex(*it, *L, now))
              tmp = L, --L, --it, hull.erase(tmp);
          }
          if (R != hull.end()) {
            it = R, ++it;
            while (it != hull.end() && convex(now, *R, *it))
              tmp = R, ++R, ++it, hull.erase(tmp);
          }
          hull.insert(now);
        }
      } else {
      GG:
        L = hull.upper_bound(now), --L;
        if (L != hull.begin()) {
          it = L, --it;
          while (L != hull.begin() && convex(*it, *L, now))
            tmp = L, --L, --it, hull.erase(tmp);
        }
        hull.insert(now);
      }
    } else {
      x = (read() + lst) % mod + 1, y = (read() + lst) % mod + 1;
      R = hull.lower_bound(Vector(now.x = (y + x - 1) / x, 0));
      if (R != hull.end()) {
        L = R, --L;
        if (check(*L, *R, x, y))
          lst = i, printf("YES\n");
        else
          printf("NO\n");
      } else
        printf("NO\n");
    }
  }
  return 0;
}
