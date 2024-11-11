#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100;
const double EPS = 1e-3;
const double PI = acos(-1);
int n;
struct Point {
  double x, y;
};
double ang, Cos, Sin;
Point data[MAX_N + 10];
inline void rotate(Point& a) {
  double xx = a.x, yy = a.y;
  a.x = Cos * xx - Sin * yy;
  a.y = Sin * xx + Cos * yy;
}
inline Point operator*(const Point& a, double b) {
  Point res;
  res.x = a.x * b;
  res.y = a.y * b;
  return res;
}
inline Point operator+(const Point& a, const Point& b) {
  Point res;
  res.x = a.x + b.x;
  res.y = a.y + b.y;
  return res;
}
inline int sgn(double a) {
  if (fabs(a) < EPS) return 0;
  return a < 0 ? -1 : 1;
}
double edgeLen[MAX_N + 10];
bool tryIt() {
  data[0].x = data[0].y = 0.0;
  Point dir;
  dir.x = 0.0;
  dir.y = -1.0;
  int en = 0;
  for (int i = 1; i < n - 1; i++) {
    rotate(dir);
    double len;
    if (sgn(dir.x) >= 0)
      len = (int)((long long)rand() * rand() % 999001 + 1000) / 1000.0;
    else {
      int bound = (int)(-data[i - 1].x / dir.x * 1000.0) - 1000 + 1;
      bound = min(999000, bound);
      if (bound <= 0) return false;
      len = (int)((long long)rand() * rand() % bound + 1000) / 1000.0;
    }
    data[i] = data[i - 1] + dir * len;
    edgeLen[en++] = len;
  }
  rotate(dir);
  if (sgn(data[n - 2].x) <= 0) return false;
  double yy = data[n - 2].y - data[n - 2].x / dir.x * dir.y;
  if (sgn(yy) <= 0) return false;
  data[n - 1].x = 0.0;
  data[n - 1].y = yy;
  edgeLen[en++] = sqrt((yy - data[n - 2].y) * (yy - data[n - 2].y) +
                       data[n - 2].x * data[n - 2].x);
  if (edgeLen[en - 1] < 1.0 || edgeLen[en - 1] > 1000.0) return false;
  edgeLen[en++] = yy;
  if (edgeLen[en - 1] < 1.0 || edgeLen[en - 1] > 1000.0) return false;
  sort(edgeLen, edgeLen + en);
  for (int i = 1; i < en; i++)
    if (sgn(edgeLen[i] - edgeLen[i - 1]) == 0) return false;
  return true;
}
int main() {
  srand(1232384);
  scanf("%d", &n);
  ang = 2.0 * PI / n;
  Cos = cos(ang);
  Sin = sin(ang);
  int t = 1000;
  while (t--) {
    if (tryIt()) {
      for (int i = 0; i < n; i++) printf("%.10f %.10f\n", data[i].x, data[i].y);
      return 0;
    }
  }
  printf("No solution\n");
  return 0;
}
