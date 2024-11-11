#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1);
int sign(double k) {
  if (k > eps)
    return 1;
  else if (k < -eps)
    return -1;
  return 0;
}
int cmp(double k1, double k2) { return sign(k1 - k2); }
struct point {
  double x, y;
  point operator+(const point &k1) const { return (point){k1.x + x, k1.y + y}; }
  point operator-(const point &k1) const { return (point){x - k1.x, y - k1.y}; }
  point operator*(double k1) const { return (point){x * k1, y * k1}; }
  point operator/(double k1) const { return (point){x / k1, y / k1}; }
  int operator==(const point &k1) const {
    return cmp(x, k1.x) == 0 && cmp(y, k1.y) == 0;
  }
  point turn(double k1) {
    return (point){x * cos(k1) - y * sin(k1), x * sin(k1) + y * cos(k1)};
  }
  bool operator<(const point k1) const {
    int a = cmp(x, k1.x);
    if (a == -1)
      return 1;
    else if (a == 1)
      return 0;
    else
      return cmp(y, k1.y) == -1;
  }
  double abs() { return sqrt(x * x + y * y); }
  double abs2() { return x * x + y * y; }
  double dis(point k1) { return ((*this) - k1).abs(); }
  double getw() { return atan2(y, x); }
  int getP() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) == -1); }
};
double cross(point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
double dot(point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
double slove(double S) {
  if (S < 0)
    S += 2 * pi;
  else if (S >= 2 * pi)
    S -= 2 * pi;
  return S;
}
point r[1005], b[1005];
vector<point> p;
int n, m;
vector<pair<double, int>> g;
bool check(int id, double R) {
  g.clear();
  point o = p[id];
  for (int i = 0; i < n + m; i++) {
    if (i == id) continue;
    point tmp = p[i];
    double d = tmp.dis(o);
    if (cmp(d, R * 2) >= 0) continue;
    double alf = acos(d / 2 / R);
    double delta = atan2(tmp.y - o.y, tmp.x - o.x);
    double l = slove(delta - alf), r = slove(delta + alf);
    if (l < r) {
      g.push_back(make_pair(l, i < n ? 2 : 1));
      g.push_back(make_pair(r, -(i < n ? 2 : 1)));
    } else {
      g.push_back(make_pair(l, i < n ? 2 : 1));
      g.push_back(make_pair(2 * pi, -(i < n ? 2 : 1)));
      g.push_back(make_pair(0, i < n ? 2 : 1));
      g.push_back(make_pair(r, -(i < n ? 2 : 1)));
    }
  }
  if (id < n)
    g.push_back(make_pair(0, id < n ? 2 : 1)),
        g.push_back(make_pair(2 * pi, -(id < n ? 2 : 1)));
  sort(g.begin(), g.end());
  int rn = 0, bn = 0;
  for (int i = 0; i < g.size(); i++) {
    if ((i == g.size() - 1 || g[i].first != g[i + 1].first) && rn > 0 &&
        bn <= 0)
      return true;
    if (abs(g[i].second) == 1)
      bn += g[i].second;
    else
      rn += g[i].second / 2;
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%lf%lf", &r[i].x, &r[i].y), p.push_back(r[i]);
  for (int i = 0; i < m; i++)
    scanf("%lf%lf", &b[i].x, &b[i].y), p.push_back(b[i]);
  bool f = 0;
  for (int i = 0; i < n + m; i++)
    if (check(i, 1e15)) return 0 * printf("-1\n");
  double ans = 0;
  for (int i = 0; i < n + m; i++) {
    double l = ans, r = 1e9;
    if (check(i, ans)) {
      while (l + eps < r) {
        double mid = (l + r) / 2;
        if (check(i, mid))
          l = mid;
        else
          r = mid;
      }
      ans = l;
    }
  }
  printf("%.11f\n", ans);
}
