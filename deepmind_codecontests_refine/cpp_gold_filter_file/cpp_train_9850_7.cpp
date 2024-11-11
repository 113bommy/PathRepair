#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
struct Point {
  long long x, y;
  Point(long long x0 = INF, long long y0 = INF) {
    x = x0;
    y = y0;
  }
};
istream &operator>>(istream &in, Point &A) {
  in >> A.x >> A.y;
  return in;
}
bool operator==(Point A, Point B) { return A.x == B.x and A.y == B.y; }
struct Vector {
  long long x, y;
  Vector(Point A, Point B) {
    x = B.x - A.x;
    y = B.y - A.y;
  }
  int cross(Vector B) {
    long long t = (long long)this->x * B.y - this->y * B.x;
    if (t == 0)
      return 0;
    else
      return 1;
  }
};
struct Line {
  long long a, b, c;
  Line(Point A, Point B) {
    a = A.y - B.y;
    b = B.x - A.x;
    c = -a * A.x - b * A.y;
  }
  bool online(Point A) { return ((long long)a * A.x + b * A.y + c == 0); }
};
void yes() {
  cout << "yes";
  exit(0);
}
void no() {
  cout << "no";
  exit(0);
}
int main() {
  int n;
  cin >> n;
  vector<Point> a(n);
  for (int i = 0; i < n; i++) {
    a[i].x = i + 1;
    cin >> a[i].y;
  }
  const Point PINF;
  Line p12(a[0], a[1]);
  if (p12.online(a[2])) {
    Point A, B;
    Line AB(A, B);
    bool F = 1;
    for (int i = 3; i < n; i++) {
      if (!p12.online(a[i]) and A == PINF and B == PINF)
        A = a[i];
      else if (!p12.online(a[i]) and !(A == PINF) and B == PINF) {
        B = a[i];
        AB = Line(A, B);
        Vector AB(A, B);
        Vector V12(a[0], a[1]);
        if (AB.cross(V12) != 0) {
          F = 0;
          break;
        }
      } else if (!p12.online(a[i]) and !AB.online(a[i])) {
        F = 0;
        break;
      }
    }
    if (A == PINF) no();
    if (F and !(A == PINF)) yes();
  } else {
    Point A, B;
    A = a[2];
    Line AB(A, B);
    bool F = 1;
    for (int i = 3; i < n; i++) {
      if (!p12.online(a[i]) and B == PINF) {
        B = a[i];
        AB = Line(A, B);
        Vector AB(A, B);
        Vector V12(a[0], a[1]);
        if (AB.cross(V12) != 0) {
          F = 0;
          break;
        }
      } else if (!p12.online(a[i]) and !AB.online(a[i])) {
        F = 0;
        break;
      }
    }
    if (F) yes();
  }
  Line p13(a[0], a[2]);
  Point A, B;
  A = a[1];
  Line AB(A, B);
  bool F = 1;
  for (int i = 3; i < n; i++) {
    if (!p13.online(a[i]) and B == PINF) {
      B = a[i];
      AB = Line(A, B);
      Vector AB(A, B);
      Vector V13(a[0], a[2]);
      if (AB.cross(V13) != 0) {
        F = 0;
        break;
      }
    } else if (!p13.online(a[i]) and !AB.online(a[i])) {
      F = 0;
      break;
    }
  }
  if (F) yes();
  Line p23(a[1], a[2]);
  B = PINF;
  A = a[0];
  F = 1;
  for (int i = 3; i < n; i++) {
    if (!p23.online(a[i]) and B == PINF) {
      B = a[i];
      AB = Line(A, B);
      Vector Vab(A, B);
      Vector V23(a[1], a[2]);
      if (Vab.cross(V23) != 0) {
        F = 0;
        break;
      }
    } else if (!p23.online(a[i]) and !AB.online(a[i])) {
      F = 0;
      break;
    }
  }
  if (F) yes();
  cout << "NO";
  return 0;
}
