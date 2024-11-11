#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
  point() { x = y = 0; }
  point(long long xx, long long yy) : x(xx), y(yy) {}
  void dp() { cout << "point :: " << x << " " << y << endl; }
  bool operator==(point p) { return (x == p.x && y == p.y); }
};
inline point toVector(point &a, point &b) {
  return point(b.x - a.x, b.y - a.y);
}
inline long long dotProduct(point &a, point &b) {
  return a.x * b.x + a.y * b.y;
}
inline long long crossProduct(point &a, point &b) {
  return a.x * b.y - b.x * a.y;
}
inline long long dotProduct(point &a, point &b, point &c) {
  point ab = toVector(a, b), ac = toVector(a, c);
  return dotProduct(ab, ac);
}
inline long long crossProduct(point &a, point &b, point &c) {
  point ab = toVector(a, b), ac = toVector(a, c);
  return crossProduct(ab, ac);
}
inline long double distanceBetweenPoint(point &a, point &b) {
  long long x, y;
  x = a.x - b.x;
  y = a.y - b.y;
  return sqrt(x * x + y * y);
}
struct line {
  point a, b;
  void dp() { cout << a.x << " " << a.y << " " << b.x << " " << b.y << endl; }
};
bool cutFine(point a, point b, point c) {
  if (fabs(distanceBetweenPoint(a, b) - distanceBetweenPoint(a, c) -
           distanceBetweenPoint(c, b)) > 1e-9)
    return false;
  long double sh, lo;
  sh = distanceBetweenPoint(a, c);
  lo = distanceBetweenPoint(c, b);
  if (sh > lo) swap(sh, lo);
  if (4 * sh >= lo) return true;
  return false;
}
bool check(line f, line s, line t) {
  if (!(f.a == s.a)) return false;
  if (dotProduct(f.a, f.b, s.b) < 0 || crossProduct(f.a, f.b, s.b) < 0)
    return false;
  if (cutFine(f.a, f.b, t.a) && cutFine(s.a, s.b, t.b)) return true;
  if (cutFine(f.a, f.b, t.b) && cutFine(s.a, s.b, t.a)) return true;
  return false;
}
int main() {
  int te;
  cin >> te;
  int id = 0;
  while (te--) {
    line l[3];
    id++;
    for (int i = 0; i < 3; i++) {
      point p;
      cin >> p.x >> p.y;
      l[i].a = p;
      cin >> p.x >> p.y;
      l[i].b = p;
    }
    if (id == 1226) {
    }
    bool flag = 0;
    for (int i = 0; i < 3; i++)
      for (int j = i + 1; j < 3; j++) {
        line f, s, t;
        f = l[i];
        s = l[j];
        t = l[3 - i - j];
        if (check(f, s, t) || check(s, f, t)) {
          flag = 1;
          goto out;
        }
        swap(s.a, s.b);
        if (check(f, s, t) || check(s, f, t)) {
          flag = 1;
          goto out;
        }
        swap(s.a, s.b);
        swap(f.a, f.b);
        if (check(f, s, t) || check(s, f, t)) {
          flag = 1;
          goto out;
        }
        swap(s.a, s.b);
        if (check(f, s, t) || check(s, f, t)) {
          flag = 1;
          goto out;
        }
      }
  out:;
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
