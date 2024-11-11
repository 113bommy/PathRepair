#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;
const double PI = acos(-1.L);
struct Point {
  double x;
  double y;
  Point() {
    x = 0;
    y = 0;
  }
  Point(double x, double y) : x(x), y(y) {}
  Point operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
  }
  Point operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
  }
  double operator*(const Point& other) const {
    return x * other.x + y * other.y;
  }
  double operator^(const Point& other) const {
    return x * other.y - y * other.x;
  }
};
ostream& operator<<(ostream& s, Point p) { return s << p.x << " " << p.y; }
int main() {
  double px, py, vx, vy, a, b, c, d;
  cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
  Point displ(px, py);
  Point t1(0, b);
  Point t2(-a / 2., 0);
  Point t3(-c / 2., 0);
  Point t4(-c / 2., -d);
  Point t5(c / 2., -d);
  Point t6(c / 2., 0);
  Point t7(a / 2., 0);
  double angle = atan2(vy, vx) - PI / 2.;
  Point rotx(cos(angle), -sin(angle));
  Point roty(sin(angle), cos(angle));
  cout << fixed << setprecision(12);
  Point s1(rotx * t1, roty * t1);
  s1 = s1 + displ;
  Point s2(rotx * t2, roty * t2);
  s2 = s2 + displ;
  Point s3(rotx * t3, roty * t3);
  s3 = s3 + displ;
  Point s4(rotx * t4, roty * t4);
  s4 = s4 + displ;
  Point s5(rotx * t5, roty * t5);
  s5 = s5 + displ;
  Point s6(rotx * t6, roty * t6);
  s6 = s6 + displ;
  Point s7(rotx * t7, roty * t7);
  s7 = s7 + displ;
  cout << s1 << '\n'
       << s2 << '\n'
       << s3 << '\n'
       << s4 << '\n'
       << s5 << '\n'
       << s6 << '\n'
       << s7 << '\n';
}
