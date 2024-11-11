#include <bits/stdc++.h>
using namespace std;
pair<long double, long double> operator+(
    const pair<long double, long double> &p1,
    const pair<long double, long double> &p2) {
  return {p1.first + p2.first, p1.second + p2.second};
}
pair<long double, long double> operator-(
    const pair<long double, long double> &p1,
    const pair<long double, long double> &p2) {
  return {p1.first - p2.first, p1.second - p2.second};
}
pair<long double, long double> operator*(
    const long double &d, const pair<long double, long double> &p) {
  return {d * p.first, d * p.second};
}
long double operator*(const pair<long double, long double> &p1,
                      const pair<long double, long double> &p2) {
  return p1.first * p2.first + p1.second * p2.second;
}
long double operator^(const pair<long double, long double> &p1,
                      const pair<long double, long double> &p2) {
  return p1.first * p2.second - p1.second * p2.first;
}
const long double eps = 1e-8;
bool is_0(long double x) { return fabs(x) <= eps; }
int sgn(long double x) { return (x > eps) - (x < -eps); }
const int N = 100006;
pair<long double, long double> intersect(pair<long double, long double> p1,
                                         pair<long double, long double> p2,
                                         pair<long double, long double> q1,
                                         pair<long double, long double> q2) {
  return p1 + ((q1 - p1) ^ (q2 - q1)) / ((p2 - p1) ^ (q2 - q1)) * (p2 - p1);
}
bool on_seg(pair<long double, long double> p1,
            pair<long double, long double> p2,
            pair<long double, long double> q) {
  if (sgn((p1 - p2) ^ (p1 - q)) != 0) return false;
  return sgn((p1 - q) * (p2 - q)) == -1;
}
bool banana(pair<long double, long double> p1,
            pair<long double, long double> p2,
            pair<long double, long double> q1,
            pair<long double, long double> q2) {
  if (sgn((p1 - p2) ^ (q1 - q2)) == 0) {
    return false;
  }
  return sgn((p1 - q1) ^ (p2 - q1)) * sgn((p1 - q2) ^ (p2 - q2)) == -1 &&
         sgn((q1 - p1) ^ (q2 - p1)) * sgn((q1 - p2) ^ (q2 - p2)) == -1;
}
long double dis(pair<long double, long double> p) { return sqrt(p * p); }
vector<pair<long double, long double> > pts[N];
pair<pair<long double, long double>, pair<long double, long double> > line[N];
int n;
bool in_polygon(pair<long double, long double> p) {
  for (int i = 0; i < n; ++i) {
    pair<long double, long double> a = line[3 * i].first;
    pair<long double, long double> b = line[3 * i + 1].first;
    pair<long double, long double> c = line[3 * i + 2].first;
    pair<long double, long double> d = {889301, 890501};
    if (on_seg(a, b, p)) continue;
    if (on_seg(b, c, p)) continue;
    if (on_seg(a, c, p)) continue;
    int cnt = 0;
    if (banana(p, d, a, b)) ++cnt;
    if (banana(p, d, b, c)) ++cnt;
    if (banana(p, d, a, c)) ++cnt;
    if (cnt & 1) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int id = 0;
  for (int i = 1; i <= n; ++i) {
    pair<long double, long double> a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    pts[id].push_back(a);
    pts[id].push_back(b);
    line[id] = {a, b};
    ++id;
    pts[id].push_back(b);
    pts[id].push_back(c);
    line[id] = {b, c};
    ++id;
    pts[id].push_back(a);
    pts[id].push_back(c);
    line[id] = {c, a};
    ++id;
  }
  for (int i = 0; i < id; ++i) {
    for (int j = i + 1; j < id; ++j) {
      pair<long double, long double> a = line[i].first, b = line[i].second,
                                     c = line[j].first, d = line[j].second;
      if (a == c || a == d || b == c || b == d) continue;
      if (banana(a, b, c, d)) {
        pair<long double, long double> ret = intersect(a, b, c, d);
        pts[i].push_back(ret);
        pts[j].push_back(ret);
      }
    }
  }
  long double ans = 0;
  for (int i = 0; i < id; ++i) {
    sort(pts[i].begin(), pts[i].end());
    pts[i].resize(unique(pts[i].begin(), pts[i].end()) - pts[i].begin());
    for (int j = 0; j < (int)pts[i].size() - 1; ++j) {
      if (!in_polygon(0.5 * (pts[i][j] + pts[i][j + 1]))) {
        ans += dis(pts[i][j + 1] - pts[i][j]);
      }
    }
  }
  cout << fixed << setprecision(12) << ans << endl;
}
