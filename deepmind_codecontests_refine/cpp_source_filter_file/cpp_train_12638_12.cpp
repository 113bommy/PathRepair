#include <bits/stdc++.h>
using namespace std;
int n;
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
void ConvexHull(vector<PT> &pts) {
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
}
long long area(const PT &a, const PT &b, const PT &c) {
  return abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}
long long sq(long long x) { return x * x; }
long long dist(const PT &a, const PT &b) {
  return sq(a.x - b.x) + sq(a.y - b.y);
}
long long diameter(const vector<PT> &p) {
  if (p.size() <= 1) return 0;
  vector<PT> h = p;
  ConvexHull(h);
  int m = h.size();
  if (m == 1) return 0;
  if (m == 2) return dist(h[0], h[1]);
  int k = 1;
  while (area(h[m - 1], h[0], h[(k + 1) % m]) > area(h[m - 1], h[0], h[k])) ++k;
  long long res = 0;
  for (int i = 0, j = k; i <= k && j < m; i++) {
    res = max(res, 1LL * dist(h[i], h[j]));
    while (j < m && area(h[i], h[(i + 1) % m], h[(j + 1) % m]) >
                        area(h[i], h[(i + 1) % m], h[j])) {
      res = max(res, 1LL * dist(h[i], h[(j + 1) % m]));
      ++j;
    }
  }
  return res;
}
vector<double> len;
std::vector<double> dis;
std::vector<PT> v;
int check(int id) {
  double x = len[id];
  for (int(i) = 0; (i) < (n); (i)++) {
    vector<PT> temp;
    for (int(j) = 0; (j) < (n); (j)++)
      if (i != j and dist(v[i], v[j]) > x * x - 1e-8) temp.push_back(v[j]);
    if (diameter(temp) > x * x) return 1;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int(i) = 0; (i) < (n); (i)++) {
    int t1, t2;
    cin >> t1 >> t2;
    v.push_back(PT(t1, t2));
  }
  sort(v.begin(), v.end());
  int l = 0, r = n * (n - 1) / 2;
  for (int(i) = 0; (i) < (n); (i)++)
    for (int(j) = 0; (j) < (i); (j)++) {
      len.push_back(hypot(v[i].x - v[j].x, v[i].y - v[j].y));
    }
  sort(len.begin(), len.end());
  while (r - l > 1) {
    double m = (l + r) / 2;
    if (check(m) == 1)
      l = m;
    else
      r = m - 1;
  }
  if (check(r)) l = r;
  cout << fixed << setprecision(7) << len[l] / 2 << "\n";
  return 0;
}
