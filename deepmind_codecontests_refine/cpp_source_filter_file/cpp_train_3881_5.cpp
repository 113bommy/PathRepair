#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
inline int cmp(double x, double y = 0, double tol = 1e-7) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator+(point q) { return point(x + q.x, y + q.y); }
  point operator-(point q) { return point(x - q.x, y - q.y); }
  point operator*(double t) { return point(x * t, y * t); }
  point operator/(double t) { return point(x / t, y / t); }
  double operator*(point q) { return x * q.x + y * q.y; }
  double operator%(point q) { return x * q.y - y * q.x; }
  double polar() { return ((y > -1e-7) ? atan2(y, x) : 2 * Pi + atan2(y, x)); }
  double mod() { return sqrt(x * x + y * y); }
  point rotate(double t) {
    return point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t));
  }
  point rotate(double sin, double cos) {
    return point(x * cos - y * sin, x * sin + y * cos);
  }
  int cmp(point q) const {
    if (int t = ::cmp(x, q.x)) return t;
    return ::cmp(y, q.y);
  }
  bool operator==(point q) const { return cmp(q) == 0; }
  bool operator!=(point q) const { return cmp(q) != 0; }
  bool operator<(point q) const { return cmp(q) < 0; }
  static point pivot;
};
point point::pivot;
vector<point> p;
int n, k;
inline bool centro(point &q) {
  int i = 0, j = n - 1, cont = 0;
  while (i < j) {
    point tmp = q * 2 - p[i];
    if (tmp == p[j]) {
      i++;
      j--;
    } else if (tmp < p[j]) {
      j--;
      cont++;
    } else {
      i++;
      cont++;
    }
  }
  if (i == j && q != p[i]) cont++;
  return (cont <= k);
}
int main() {
  cin >> n >> k;
  point e;
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &e.x, &e.y);
    p.push_back(e);
  }
  sort((p).begin(), (p).end());
  if (k >= n) {
    printf("-1\n");
    return 0;
  }
  if (n <= 50) {
    set<point> S, aux;
    for (int i = 0; i < n; i++)
      if (centro(p[i])) aux.insert(p[i]);
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        e = (p[i] + p[j]) * 0.5;
        if (centro(e)) aux.insert(e);
      }
    printf("%d\n", (int)aux.size());
    for (set<point>::iterator it = aux.begin(); it != aux.end(); it++)
      printf("%.10lf %.10lf\n", (*it).x, (*it).y);
    return 0;
  }
  set<point> S, aux;
  for (int i = 0; i <= k; i++) {
    for (int j = n - 1; j >= n - k; j--) {
      e = (p[i] + p[j]) * 0.5;
      if (centro(e)) aux.insert(e);
    }
  }
  printf("%d\n", (int)aux.size());
  for (set<point>::iterator it = aux.begin(); it != aux.end(); it++)
    printf("%.8lf %.8lf\n", (*it).x, (*it).y);
  return 0;
}
