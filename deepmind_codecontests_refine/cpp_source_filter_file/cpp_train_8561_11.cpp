#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct Line {
  double k, b;
  double l, r;
  int id;
};
double X;
bool operator<(const Line& a, const Line& b) {
  double vala = a.k * X + a.b;
  double valb = b.k * X + b.b;
  if (fabs(vala - valb) > eps) return vala < valb;
  return a.id < b.id;
}
bool check_inter(Line a, Line b) {
  double dk = a.k - b.k;
  double db = b.b - a.b;
  if (fabs(dk) < eps)
    return fabs(a.b - b.b) < eps && a.r + eps > b.l - eps &&
           a.l - eps < b.r + eps;
  double x = db / dk;
  return a.l - eps < x && x < a.r + eps && b.l - eps < x && x < b.r + eps;
}
struct Vec {
  double x, y;
  Vec(double xx = 0, double yy = 0) {
    x = xx;
    y = yy;
  }
  double len() { return sqrt(x * x + y * y); }
} p[25010], dir[25010];
Vec operator+(const Vec& a, const Vec& b) { return Vec(a.x + b.x, a.y + b.y); }
Vec operator-(const Vec& a, const Vec& b) { return Vec(a.x - b.x, a.y - b.y); }
Vec operator*(const Vec& a, const double& b) { return Vec(a.x * b, a.y * b); }
Vec operator/(const Vec& a, const double& b) { return Vec(a.x / b, a.y / b); }
Line GetLine(Vec a, Vec b) {
  if (a.x > b.x) swap(a, b);
  Line res;
  res.l = a.x;
  res.r = b.x;
  res.k = (b.y - a.y) / (b.x - a.x);
  res.b = a.y - res.k * a.x;
  return res;
}
Line l[25010];
struct Event {
  double x;
  int id, op;
  Event() {}
  Event(double a, int b, int c) {
    x = a;
    id = b;
    op = c;
  }
} e[50010];
bool cmp(Event a, Event b) { return a.x < b.x; }
int n;
multiset<Line>::iterator It[25010];
bool check(double t) {
  multiset<Line> S;
  for (int i = 1; i <= n; i++) {
    l[i] = GetLine(p[i], p[i] + dir[i] * t);
    l[i].id = i;
    Vec to = p[i] + dir[i] * t;
    e[i * 2 - 1] = Event(l[i].l, i, 0);
    e[i * 2] = Event(l[i].r - eps, i, 1);
  }
  sort(e + 1, e + n * 2 + 1, cmp);
  for (int i = 1; i <= n * 2; i++) {
    int id = e[i].id;
    X = e[i].x;
    if (e[i].op == 0) {
      multiset<Line>::iterator it = S.insert(l[id]);
      multiset<Line>::iterator it1;
      It[id] = it;
      if (it != S.begin()) {
        it1 = it;
        it1--;
        if (check_inter(*it1, *it)) return true;
      }
      it1 = it;
      it1++;
      if (it1 != S.end()) {
        if (check_inter(*it1, *it)) return true;
      }
    } else {
      multiset<Line>::iterator it = It[id], it1, it2;
      it1 = it;
      it1++;
      it2 = it;
      if (it1 != S.end() && it2 != S.begin()) {
        it2--;
        if (check_inter(*it1, *it2)) return true;
      }
      S.erase(it);
    }
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    double s;
    scanf("%lf %lf %lf %lf %lf", &p[i].x, &p[i].y, &dir[i].x, &dir[i].y, &s);
    dir[i] = dir[i] / dir[i].len() * s;
  }
  double l = 0, r = 1e6;
  int tim = 80;
  while (tim--) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (r > 1e5)
    printf("No show :(\n");
  else
    printf("%.10lf\n", r);
  return 0;
}
