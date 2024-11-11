#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535897932384626433832795;
const double eps = 1e-1;
struct Point {
  double x, y;
  Point(double a = 0, double b = 0) : x(a), y(b) {}
};
Point rotate(Point a, double d) {
  double c = cos(d), s = sin(d);
  return Point(a.x * c - a.y * s, a.y * c + a.x * s);
}
Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator*(Point a, double r) { return Point(a.x * r, a.y * r); }
Point operator/(Point a, double r) { return Point(a.x / r, a.y / r); }
double norm(Point a) { return sqrt(a.x * a.x + a.y * a.y); }
const int maxn = 1000 + 2;
const double size = 500;
int sig(double rt) {
  if (fabs(rt) < eps) return 0;
  if (rt > 0) return 1;
  return -1;
}
int n;
Point p[maxn], unit[maxn];
int main() {
  scanf("%d", &n);
  srand(n * 10);
  if (n < 5) {
    printf("No solution\n");
    return 0;
  }
  double deg = (180 - (n - 2) * 180.0 / n) / 180 * pi;
  Point cur = Point(size, 0);
  p[0] = Point(0, 0);
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] + cur;
    unit[i - 1] = cur / size;
    cur = rotate(cur, deg);
  }
  unit[n - 1] = cur / size;
  while (true) {
    int inx = rand() % n;
    Point *a = &p[inx], *b = &p[(inx + 1) % n];
    Point *t = &p[(inx + 3) % n], *g = &p[(inx + 2) % n];
    double ratio = (rand() % (10 * (inx + 1))) / 10.0;
    if (rand() % 2 == 0) ratio = -ratio;
    *b = *b + (unit[inx] * ratio);
    *g = *g + ((unit[(inx + 2) % n] * -1) * ratio);
    bool flag = true;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (sig(norm(p[i] - p[(i + 1) % n]) - norm(p[j] - p[(j + 1) % n])) ==
            0) {
          flag = false;
          break;
        }
    if (flag) break;
  }
  for (int i = 0; i < n; i++)
    cout << p[i].x / 10.0 << ' ' << p[i].y / 10.0 << endl;
  return 0;
}
