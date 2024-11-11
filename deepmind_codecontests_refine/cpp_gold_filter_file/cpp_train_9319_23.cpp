#include <bits/stdc++.h>
using namespace std;
class Point {
 public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double a) { return Point(x * a, y * a); }
  Point operator/(double a) { return Point(x / a, y / a); }
  double absv() { return sqrt(norm()); }
  double norm() { return x * x + y * y; }
  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < (1e-6) && fabs(y - p.y) < (1e-6);
  }
};
struct Segment {
  Point p1, p2;
};
double hen(Point a) {
  if (fabs(a.x) < (1e-6) && a.y > 0)
    return acos(0);
  else if (fabs(a.x) < (1e-6) && a.y < 0)
    return 3 * acos(0);
  else if (fabs(a.y) < (1e-6) && a.x < 0)
    return 2 * acos(0);
  else if (fabs(a.y) < (1e-6) && a.x > 0)
    return 0.0;
  else if (a.y > 0)
    return acos(a.x / a.absv());
  else
    return 2 * acos(0) + acos(-a.x / a.absv());
}
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
Point inter(Point a1, Point a2, Point b1, Point b2) {
  Point a = a2 - a1;
  Point b = b2 - b1;
  return a1 + a * cross(b, b1 - a1) / cross(b, a);
}
double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ru[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
long long frac[100010];
long long inv[100010];
long long saikif(long long a, int n) {
  if (n == 1)
    return a % 1000000007;
  else if (n % 2 == 0) {
    long long q = saikif(a, n / 2);
    return (q * q) % 1000000007;
  } else
    return (a * saikif(a, n - 1)) % 1000000007;
}
void gyakugen() {
  frac[0] = 1;
  for (int i = 1; i <= 100000; i++) frac[i] = (frac[i - 1] * i) % 1000000007;
  for (int i = 0; i <= 100000; i++) inv[i] = saikif(frac[i], 1000000007 - 2);
}
int main() {
  long long a[2000], b[2000];
  int n;
  long long ma = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      long long ue = 0, sita = 0;
      for (int k = i; k <= j; k++) {
        ue = ue | a[k];
        sita = sita | b[k];
      }
      ma = max(ue + sita, ma);
    }
  }
  cout << ma << endl;
}
