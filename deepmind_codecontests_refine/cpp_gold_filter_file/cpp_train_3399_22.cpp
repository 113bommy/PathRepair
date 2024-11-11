#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const ld eps = 1e-5;
template <class T>
struct pt {
  T x, y;
  pt operator+(const pt &p) const { return {x + p.x, y + p.y}; }
  pt operator-(const pt &p) const { return {x - p.x, y - p.y}; }
  pt operator*(T d) const { return {x * d, y * d}; }
  pt operator/(T d) const { return {x / d, y / d}; }
  bool operator<(const pt &p) const {
    if (::abs(x - p.x) < eps) return ::abs(y - p.y) < eps ? false : y < p.y;
    return x < p.x;
  }
  T sq() { return x * x + y * y; }
  T abs() { return sqrt(sq()); }
  pt rot(T a) {
    T nx = x * cos(a) - y * sin(a);
    T ny = x * sin(a) + y * cos(a);
    return {nx, ny};
  }
  friend ostream &operator<<(ostream &out, pt p) {
    out << '(' << p.x << ',' << p.y << ')';
    return out;
  }
};
using Pt = pt<long double>;
bool intersect(Pt c1, ld r1, Pt c2, ld r2, pair<Pt, Pt> &out) {
  ld d = (c2 - c1).abs();
  ld co = (d * d + r1 * r1 - r2 * r2) / (2 * d * r1);
  if (abs(co) > 1) return false;
  ld alpha = acos(co);
  Pt rad = (c2 - c1) / d * r1;
  out = {c1 + rad.rot(-alpha), c1 + rad.rot(alpha)};
  return true;
}
int n, dsu[3];
ld r[3];
Pt cir[3];
bool seen[8];
bool join(int u, int v) {
  while (dsu[u] != u) u = dsu[u];
  while (dsu[v] != v) v = dsu[v];
  if (u == v) return false;
  dsu[u] = v;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cir[i].x >> cir[i].y >> r[i];
    dsu[i] = i;
  }
  set<Pt> vert;
  int c = n;
  int e = 0;
  for (int i = 0; i < n; i++) {
    set<Pt> ivert;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      pair<Pt, Pt> it;
      if (intersect(cir[i], r[i], cir[j], r[j], it)) {
        ivert.insert(it.first);
        ivert.insert(it.second);
        if (join(i, j)) c--;
      }
    }
    e += ivert.size();
    for (auto p : ivert) {
      vert.insert(p);
    }
  }
  int v = vert.size();
  cout << e - v + c + 1 << '\n';
  return 0;
}
