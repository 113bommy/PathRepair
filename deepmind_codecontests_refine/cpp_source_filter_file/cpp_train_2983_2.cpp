#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using db = double;
using pii = pair<int, int>;
const db pi = 3.14159265358979323846264338;
const db eps = 1E-9;
int sgn(db x, db y = 0) {
  x -= y;
  return int(x > eps) - (x < -eps);
}
struct poi {
  db x, y;
  poi operator-(poi b) { return {x - b.x, y - b.y}; }
  poi operator+(poi b) { return {x + b.x, y + b.y}; }
  db len2() { return x * x + y * y; }
  poi operator*(db b) { return {x * b, y * b}; }
  poi rot(db b) { return {x * cos(b) - y * sin(b), x * sin(b) + y * cos(b)}; }
  bool operator<(poi b) const {
    return sgn(x, b.x) == -1 || sgn(x, b.x) == 0 && sgn(y, b.y) == -1;
  }
};
struct circle {
  poi p;
  db r;
};
vector<circle> a;
vector<poi> cc(poi c1, double r1, poi c2, double r2) {
  vector<poi> ret;
  double x = (c1 - c2).len2();
  if (!(sgn(abs(r1 - r2), sqrt(x)) <= 0 && sgn(sqrt(x), r1 + r2) <= 0))
    return {};
  double y = ((r1 * r1 - r2 * r2) / x + 1) / 2;
  double d = r1 * r1 / x - y * y;
  if (sgn(d) == -1) return ret;
  d = max(d, 0.0);
  poi p1 = c1 + (c2 - c1) * y;
  poi p2 = ((c2 - c1) * sqrt(d)).rot(pi / 2);
  ret.push_back(p1 - p2);
  ret.push_back(p1 + p2);
  return ret;
}
int n;
int V, E, N;
set<poi> as;
int p[10];
int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }
void merge(int x, int y) { p[root(x)] = root(y); }
int main() {
  cin >> n;
  iota(p, p + n, 0);
  for (int i = 0; i < n; ++i) {
    db x, y, r;
    cin >> x >> y >> r;
    a.push_back({{x, y}, r});
  }
  for (int i = 0; i < n; ++i) {
    set<poi> s;
    for (int j = 0; j < n; ++j)
      if (j != i)
        for (poi k : cc(a[i].p, a[i].r, a[j].p, a[j].r)) {
          s.insert(k);
          as.insert(k);
          merge(i, j);
        }
    E += s.size();
  }
  for (int i = 0; i < n; ++i)
    if (root(i) == i) ++N;
  V = as.size();
  int F = E - V + N + 1;
  cout << F << endl;
  return 0;
}
