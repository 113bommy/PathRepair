#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-6;
struct Point {
  long long x, y;
  Point() {}
  Point(long long x, long long y) : x(x), y(y) {}
  Point operator-(const Point& a) { return Point(x - a.x, y - a.y); }
  long long operator*(Point a) { return x * a.x + y * a.y; }
  long long operator%(const Point& a) { return x * a.y - y * a.x; }
  long double norm() { return x * x + y * y; }
  long double len() { return sqrt(norm()); }
  void read() { scanf("%lld%lld", &x, &y); }
} A[5], B[5];
bool operator==(const Point& a, const Point& b) {
  return a.x == b.x && a.y == b.y;
}
long long ccw(Point A, Point B, Point C) {
  long long t = (B - A) % (C - A);
  if (t == 0) return 0;
  if (t < 0) return -1;
  return 1;
}
const long double PI = acos((long double)-1.0);
long double angle(Point a, Point o, Point b) {
  a = a - o;
  b = b - o;
  long double res = acos((a * b) / sqrt(a.norm() * b.norm()));
  while (res < -EPS) res += 2 * PI;
  while (res >= 2 * PI) res -= 2 * PI;
  return res;
}
bool order(Point A, Point B, Point C) {
  return min(A.x, C.x) <= B.x && B.x <= max(A.x, C.x) && min(A.y, C.y) <= B.y &&
         B.y <= max(A.y, C.y);
}
bool good(Point A, Point B, Point C) {
  if (ccw(A, B, C)) return false;
  if (!order(A, B, C)) return false;
  long double x = (B - A).len();
  long double y = (C - B).len();
  if (x * 4 < y - EPS) return false;
  if (y * 4 < x - EPS) return false;
  return true;
}
bool check() {
  long long t[5];
  for (long long i = (1), _b = (3); i <= _b; ++i) t[i] = i;
  do {
    for (long long r1 = 0, _a = (2); r1 < _a; ++r1) {
      for (long long r2 = 0, _a = (2); r2 < _a; ++r2) {
        for (long long r3 = 0, _a = (2); r3 < _a; ++r3) {
          if (A[t[1]] == A[t[2]] && ccw(A[t[1]], B[t[1]], B[t[2]]) &&
              angle(B[t[1]], A[t[1]], B[t[2]]) < PI / 2.0 + EPS &&
              good(A[t[1]], A[t[3]], B[t[1]]) &&
              good(A[t[2]], B[t[3]], B[t[2]])) {
            return true;
          }
          swap(A[3], B[3]);
        }
        swap(A[2], B[2]);
      }
      swap(A[1], B[1]);
    }
  } while (next_permutation(t + 1, t + 4));
  return false;
}
int main() {
  long long ntest;
  scanf("%lld", &ntest);
  while (ntest--) {
    for (long long i = (1), _b = (3); i <= _b; ++i) {
      A[i].read();
      B[i].read();
    }
    puts(check() ? "YES" : "NO");
  }
}
