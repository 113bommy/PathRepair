#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
int dcmp(double x) {
  if (fabs(x) < EPS)
    return 0;
  else
    return x < 0 ? -1 : 1;
}
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  const bool operator<(Point A) const { return x == A.x ? y < A.y : x < A.x; }
};
typedef Point Vector;
Vector operator-(Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
bool operator==(const Point& a, const Point& b) {
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A) { return atan2(A.y, A.x); }
struct Circle {
  Point c;
  double r;
  Circle() : c(Point(0, 0)), r(0) {}
  Circle(Point c, double r = 0) : c(c), r(r) {}
  Point point(double a) { return Point(c.x + cos(a) * r, c.y + sin(a) * r); }
} C[3];
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol) {
  double d = Length(C1.c - C2.c);
  if (dcmp(d) == 0) {
    if (dcmp(C1.r - C2.r) == 0) return 0;
    return 0;
  }
  if (dcmp(C1.r + C2.r - d) < 0) return 0;
  if (dcmp(fabs(C1.r - C2.r) - d) > 0) return 0;
  double a = Angle(C2.c - C1.c);
  double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
  Point p1 = C1.point(a - da), p2 = C1.point(a + da);
  sol.push_back(p1);
  if (p1 == p2) return 1;
  sol.push_back(p2);
  return 2;
}
int main() {
  int n, x, y, r;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &x, &y, &r);
    C[i].c.x = x;
    C[i].c.y = y;
    C[i].r = r;
  }
  if (n == 1) {
    printf("2\n");
    return 0;
  } else if (n == 2) {
    vector<Point> sol;
    int t = getCircleCircleIntersection(C[0], C[1], sol);
    if (t == 2)
      printf("4\n");
    else
      printf("3\n");
    return 0;
  } else {
    vector<Point> sol[3];
    int t = getCircleCircleIntersection(C[0], C[1], sol[0]);
    int a = getCircleCircleIntersection(C[0], C[2], sol[1]);
    int b = getCircleCircleIntersection(C[1], C[2], sol[2]);
    if (t == 2) {
      vector<Point> S = sol[0];
      for (auto i : sol[1]) S.push_back(i);
      for (auto i : sol[2]) S.push_back(i);
      sort(S.begin(), S.end());
      int d = unique(S.begin(), S.end()) - S.begin();
      if (a > b) {
        swap(a, b);
        swap(sol[1], sol[2]);
      }
      if (a == 0 && b == 0) {
        printf("5\n");
      } else if (a == 0 && b == 1) {
        printf("5\n");
      } else if (a == 0 && b == 2) {
        printf("6\n");
      } else if (a == 1 && b == 1) {
        printf("6\n");
      } else if (a == 1 && b == 2) {
        if (d == 5)
          printf("7\n");
        else
          printf("6\n");
      } else if (a == 2 && b == 2) {
        if (d == 2)
          printf("6\n");
        else if (d == 4)
          printf("7\n");
        else
          printf("8\n");
      }
    } else if (t == 1) {
      if (a > b) {
        swap(a, b);
        swap(sol[1], sol[2]);
      }
      if (a == 0 && b == 0) {
        printf("4\n");
      } else if (a == 0 && b == 1) {
        printf("4\n");
      } else if (a == 0 && b == 2) {
        printf("5\n");
      } else if (a == 1 && b == 1) {
        if (sol[0][0] == sol[1][0])
          printf("4\n");
        else
          printf("5\n");
      } else if (a == 1 && b == 2) {
        printf("6\n");
      } else if (a == 2 && b == 2) {
        if (sol[1][0] == sol[0][0] || sol[1][1] == sol[0][0])
          printf("6\n");
        else
          printf("7\n");
      }
    } else {
      int cnt = (a == 2) + (b == 2);
      printf("%d\n", 4 + cnt);
    }
  }
  return 0;
}
