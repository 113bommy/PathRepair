#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const long long linf = LLONG_MAX;
const int mod = 2;
const double EPS = 1e-9;
inline int sign(long long val) { return val > 0 ? 1 : val == 0 ? 0 : -1; }
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return int(a * 1ll * b % mod); }
bool eq(long double A, long double B) { return abs(A - B) < EPS; }
bool ls(long double A, long double B) { return A < B && !eq(A, B); }
bool le(long double A, long double B) { return A < B || eq(A, B); }
using namespace std;
class Point {
 public:
  Point() {}
  Point(double xx, double yy) {
    x = xx;
    y = yy;
  }
  Point(const Point &op) {
    x = op.x;
    y = op.y;
  }
  bool equal(Point op) { return (x == op.x && y == op.y); }
  bool equal(int xx, int yy) { return (x == xx && y == yy); }
  double dist(Point op) {
    return sqrt(((op.x - x) * (op.x - x)) + ((op.y - y) * (op.y - y)));
  }
  double toCenter() { return dist(Point(0, 0)); }
  void setX(double xx) { x = xx; }
  void setY(double yy) { y = yy; }
  double getX() { return x; }
  double getY() { return y; }
  Point rotate(long double phi) const {
    long double nx = x * cosl(phi) - y * sinl(phi);
    long double ny = x * sinl(phi) + y * cosl(phi);
    return Point(nx, ny);
  }
  Point operator+(Point A) { return Point(x + A.x, y + A.y); }
  Point operator-(Point A) { return Point(x - A.x, y - A.y); }
  bool operator==(const Point &op) const { return eq(op.x, x) && eq(op.y, y); }
  bool operator<(const Point &op) const {
    return ls(x, op.x) || (le(x, op.x) && ls(y, op.y));
  }

 private:
  double x;
  double y;
};
class Circle {
 public:
  Circle(Point c, double r) {
    center = new Point(c.getX(), c.getY());
    radius = r;
  }
  double getRadius() { return radius; }
  Point getCenter() { return *center; }

 private:
  Point *center;
  double radius;
};
void intersection(Circle c1, Circle c2, vector<Point> &resultPoints) {
  long double d = c1.getCenter().dist(c2.getCenter());
  long double r1 = c1.getRadius();
  long double r2 = c2.getRadius();
  if (ls(r1 + r2, d) || ls(d, abs(r1 - r2))) {
    return;
  }
  if (eq(r1 + r2, d)) {
    Point v = c2.getCenter() - c1.getCenter();
    v.setX(v.getX() * (r1 / (r1 + r2)));
    v.setY(v.getY() * (r1 / (r1 + r2)));
    resultPoints.push_back(c1.getCenter() + v);
  } else if (eq(r1 - r2, d)) {
    Point v = c2.getCenter() - c1.getCenter();
    v.setX(v.getX() * (r1 / (r1 - r2)));
    v.setY(v.getY() * (r1 / (r1 - r2)));
    resultPoints.push_back(c1.getCenter() + v);
  } else if (eq(r2 - r1, d)) {
    swap(r1, r2);
    swap(c1, c2);
    Point v = c2.getCenter() - c1.getCenter();
    v.setX(v.getX() * (r1 / (r1 - r2)));
    v.setY(v.getY() * (r1 / (r1 - r2)));
    resultPoints.push_back(c1.getCenter() + v);
  } else {
    long double phi = acosl((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
    Point v = c2.getCenter() - c1.getCenter();
    v.setX(v.getX() * (r1 / d));
    v.setY(v.getY() * (r1 / d));
    resultPoints.push_back(c1.getCenter() + v.rotate(phi));
    resultPoints.push_back(c1.getCenter() + v.rotate(-phi));
  }
}
bool isAdjacent(Circle c1, Circle c2) {
  long double d = c1.getCenter().dist(c2.getCenter());
  long double r1 = c1.getRadius();
  long double r2 = c2.getRadius();
  return !(ls(r1 + r2, d) || ls(d, abs(r1 - r2)));
}
int main(int argc, char **argv) {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 2;
    return 0;
  }
  vector<Circle> circles;
  double x, y, r;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> r;
    circles.emplace_back(Circle(Point(x, y), r));
  }
  vector<Point> points;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      intersection(circles[i], circles[j], points);
    }
  }
  sort(((points)).begin(), ((points)).end());
  (points).resize(unique(((points)).begin(), ((points)).end()) -
                  (points).begin());
  int v = points.size();
  int e = 0;
  for (int i = 0; i < n; i++) {
    int counter = 0;
    for (Point point : points) {
      if (eq(point.dist(circles[i].getCenter()), circles[i].getRadius())) {
        counter++;
      }
    }
    if (counter == 0) {
      v++;
      e++;
    } else {
      e += counter;
    }
  }
  int connectedComp = 1;
  if (n == 2 && !isAdjacent(circles[0], circles[1])) {
    connectedComp++;
  }
  if (n == 3 && !isAdjacent(circles[0], circles[1]) &&
      !isAdjacent(circles[0], circles[2])) {
    connectedComp++;
  }
  if (n == 3 && !isAdjacent(circles[0], circles[1]) &&
      !isAdjacent(circles[1], circles[2])) {
    connectedComp++;
  }
  if (n == 3 && !isAdjacent(circles[0], circles[2]) &&
      !isAdjacent(circles[1], circles[2])) {
    connectedComp++;
  }
  if (n == 3 && !isAdjacent(circles[0], circles[2]) &&
      !isAdjacent(circles[1], circles[2]) &&
      !isAdjacent(circles[0], circles[1])) {
    connectedComp--;
  }
  cout << 1 + connectedComp + e - v;
  return 0;
}
