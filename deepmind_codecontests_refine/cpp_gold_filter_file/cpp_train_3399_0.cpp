#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-12;
struct point {
  long double x, y;
  point() { x = y = 0; }
  point(long double a, long double b) { x = a, y = b; }
  long double dist() const { return sqrt(x * x + y * y); }
  point operator+(const point &nd) const { return point(x + nd.x, y + nd.y); }
  point operator-(const point &t) const { return point(x - t.x, y - t.y); }
  point operator*(const long double val) const {
    return point(x * val, y * val);
  }
  point operator/(const long double val) const {
    return point(x / val, y / val);
  }
  point anti90() const { return point(-y, x); }
};
inline bool operator<(const point &a, const point &b) {
  return (fabs(a.x - b.x) < eps ? a.y > b.y + eps : a.x < b.x);
}
struct circle {
  point o;
  long double r;
} p[4];
vector<point> findIntersection(const circle &c1, const circle &c2) {
  long double c1c2 = (c1.o - c2.o).dist();
  if (c1c2 > (c1.r + c2.r) + eps or c1c2 < fabs(c1.r - c2.r) - eps)
    return vector<point>();
  point unit = (c2.o - c1.o) / c1c2;
  long double h = (c1.r * c1.r - c2.r * c2.r) / c1c2;
  long double c1p = (h + c1c2) / 2;
  point c1pv = c1.o + (unit * c1p);
  unit = unit.anti90();
  h = sqrt(max(0.0L, c1.r * c1.r - c1p * c1p));
  return vector<point>{c1pv + unit * h, c1pv - unit * h};
}
int par[5];
int root(int i) {
  while (i != par[i]) {
    par[i] = par[par[i]];
    i = par[i];
  }
  return i;
}
void Union(int p, int q) {
  p = root(p);
  q = root(q);
  par[p] = q;
}
int main() {
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    cin >> p[i].o.x >> p[i].o.y >> p[i].r;
  }
  int e = 0, v = 0;
  set<point> vertices;
  for (int i = 0; i < n; ++i) {
    set<point> edges;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      vector<point> interPoints = findIntersection(p[i], p[j]);
      if (!interPoints.empty()) {
        Union(i, j);
        for (int k = 0; k < 2; ++k) {
          edges.insert(interPoints[k]);
          vertices.insert(interPoints[k]);
        }
      }
    }
    e += (int)edges.size();
  }
  v = (int)vertices.size();
  int c = 0;
  for (int i = 0; i < n; ++i) {
    if (root(i) == i) {
      ++c;
    }
  }
  cout << e - v + 1 + c << "\n";
  return 0;
}
