#include <bits/stdc++.h>
using namespace std;
struct pt {
  long double x, y;
  pt(long double x, long double y) : x(x), y(y) {}
  pt() {}
  long double norm2() { return *this * *this; }
  long double norm() { return sqrt(norm2()); }
  bool operator==(pt p) { return abs(x - p.x) < 1e-14 && abs(y - p.y) < 1e-14; }
  pt operator+(pt p) { return pt(x + p.x, y + p.y); }
  pt operator-(pt p) { return pt(x - p.x, y - p.y); }
  pt operator*(long double t) { return pt(x * t, y * t); }
  pt operator/(long double t) { return pt(x / t, y / t); }
  long double operator*(pt p) { return x * p.x + y * p.y; }
  long double angle(pt p) { return acos(*this * p / (norm() * p.norm())); }
  pt unit() { return *this / norm(); }
  long double operator%(pt p) { return x * p.y - y * p.x; }
  bool operator<(pt p) const {
    return x < p.x || (abs(x - p.x) < 1e-14 && y < p.y);
  }
  bool left(pt p, pt q) { return (q - p) % (*this - p) >= -1e-14; }
  pt rot(pt r) { return pt(*this % r, *this * r); }
  pt rot(long double a) { return rot(pt(sin(a), cos(a))); }
};
pt ccw90(1, 0);
pt cw90(-1, 0);
vector<pt> chull(vector<pt> p) {
  if (((int)p.size()) < 3) return p;
  vector<pt> r;
  sort(p.begin(), p.end());
  for (int i = 0, ThxDem = p.size(); i < ThxDem; ++i) {
    while (r.size() >= 2 && r.back().left(r[r.size() - 2], p[i])) r.pop_back();
    r.push_back(p[i]);
  }
  r.pop_back();
  int k = r.size();
  for (int i = p.size() - 1; i >= 0; --i) {
    while (r.size() >= k + 2 && r.back().left(r[r.size() - 2], p[i]))
      r.pop_back();
    r.push_back(p[i]);
  }
  r.pop_back();
  return r;
}
int n, m;
vector<pt> pingo;
map<pair<int, int>, vector<int> > ereccion;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int xi, yi;
    scanf("%d %d", &xi, &yi);
    pingo.push_back(pt(1. / xi, 1. / yi));
    ereccion[make_pair(xi, yi)].push_back(i + 1);
  }
  vector<pt> concha = chull(pingo);
  vector<pt> ura, pito;
  for (auto p : concha) {
    ura.push_back(pt(p.x, p.y));
    pito.push_back(pt(p.y, p.x));
  }
  sort(ura.begin(), ura.end());
  pt leftmost = pt(ura[0].x, ura[0].y);
  sort(pito.begin(), pito.end());
  pt downmost = pt(pito[0].y, pito[0].x);
  set<int> ans;
  for (auto p : concha) {
    if (p.x - 1e-14 < downmost.x && p.y - 1e-14 < leftmost.y &&
        (p - leftmost) % (downmost - leftmost) >= -1e-14) {
      int xx = (1. / p.x + 1e-3);
      int yy = (1. / p.y + 1e-3);
      assert(ereccion[make_pair(xx, yy)].size());
      for (auto d : ereccion[make_pair(xx, yy)]) ans.insert(d);
    }
  }
  for (auto d : ans) {
    printf("%d ", d);
  }
  puts("");
  return 0;
}
