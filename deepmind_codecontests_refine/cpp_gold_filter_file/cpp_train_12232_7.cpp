#include <bits/stdc++.h>
using namespace std;
const long long EPS = 0;
struct PT {
  long long x, y;
  PT() {}
  PT(long long x, long long y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const {
    return make_pair(y, x) < make_pair(rhs.y, rhs.x);
  }
  bool operator==(const PT &rhs) const {
    return make_pair(y, x) == make_pair(rhs.y, rhs.x);
  }
};
long long cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }
long long area2(PT a, PT b, PT c) {
  return cross(a, b) + cross(b, c) + cross(c, a);
}
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a, b, c)) < EPS && (a.x - b.x) * (c.x - b.x) <= 0 &&
          (a.y - b.y) * (c.y - b.y) <= 0);
}
void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size() - 2], up.back(), pts[i]) >= 0)
      up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(), pts[i]) <= 0)
      dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int)up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size() - 2], dn[dn.size() - 1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
}
int n, m;
long long x, y;
vector<PT> mini;
vector<PT> maxi;
map<long long, long long> ma;
set<long long> se;
int main() {
  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) {
    long long aa, bb;
    cin >> aa >> bb;
    maxi.push_back(PT(aa, bb));
  }
  long long maxx = 0;
  long long maxy = 0;
  for (int i = 0; i < m; i++) {
    long long aa, bb;
    cin >> aa >> bb;
    mini.push_back(PT(aa, bb));
    maxx = max(maxx, aa);
    maxy = max(maxy, bb);
  }
  m += 3;
  mini.push_back(PT(0, 0));
  mini.push_back(PT(maxx, 0));
  mini.push_back(PT(0, maxy));
  ConvexHull(mini);
  for (int i = 2; i < mini.size(); i++) {
    ma[mini[i].x] = mini[i].y;
    se.insert(mini[i].x);
  }
  for (int i = 0; i < n; i++) {
    set<long long>::iterator a = se.lower_bound(maxi[i].x);
    if (a == se.end()) {
      cout << "Max";
      return 0;
    }
    if (maxi[i].x == maxx) {
      cout << "Max";
      return 0;
    }
    set<long long>::iterator ae = a;
    ae--;
    PT y = maxi[i];
    PT x = PT(*a, ma[*a]);
    PT xe = PT(*ae, ma[*ae]);
    if (area2(x, xe, y) <= 0) {
      cout << "Max";
      return 0;
    }
  }
  cout << "Min";
  return 0;
}
