#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  point(double x = 0, double y = 0) {
    this->x = x;
    this->y = y;
  }
};
inline double cp(point O, point A, point B) {
  double x1 = A.x - O.x, y1 = A.y - O.y, x2 = B.x - O.x, y2 = B.y - O.y;
  return x1 * y2 - x2 * y1;
}
inline double dist2(point A, point B) {
  return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}
inline double dist(point A, point B) { return sqrt(dist2(A, B)); }
inline double radius(point A, point B, point C) {
  double a = dist(B, C), b = dist(A, C), c = dist(A, B);
  double s = cp(A, B, C);
  if (s < 0) s *= 1;
  return a * b * c / (2 * s);
}
double area(vector<point> p) {
  double s = 0;
  point O;
  p.push_back(p[0]);
  for (size_t i = 0; i < p.size() - 1; ++i) s += cp(O, p[i], p[i + 1]);
  s *= 0.5;
  if (s < 0) s *= -1;
  return s;
}
struct point_comp {
  point O;
  point_comp(point O) { this->O = O; }
  bool operator()(point A, point B) { return cp(O, A, B) > 0; }
};
vector<point> convex_hull(vector<point> p) {
  if (p.size() < 3) return p;
  for (size_t i = 1; i < p.size(); ++i)
    if (p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x))
      swap(p[0], p[i]);
  point_comp cmp(p[0]);
  sort(p.begin() + 1, p.end(), cmp);
  vector<point> q;
  q.push_back(p[0]);
  size_t k = 2;
  while (k < p.size() && cp(p[0], p[1], p[k]) == 0) ++k;
  for (size_t i = 2; i < k; ++i)
    if (dist2(p[i], p[0]) > dist2(p[0], p[1])) swap(p[1], p[i]);
  q.push_back(p[1]);
  while (k < p.size() && cp(p[0], p.back(), p[k]) != 0) q.push_back(p[k++]);
  while (k < p.size() && cp(p[0], p.back(), p[k]) == 0) {
    if (dist2(p[0], p[k]) > dist2(p[0], p.back())) swap(p[k], p.back());
    ++k;
  }
  q.push_back(p.back());
  p = q;
  p.push_back(p[0]);
  vector<point> ch;
  ch.push_back(p[0]);
  ch.push_back(p[1]);
  int z = 1;
  for (size_t i = 2; i < p.size(); ++i) {
    while (cp(ch[z], ch[z - 1], p[i]) >= 0) ch.pop_back(), --z;
    ch.push_back(p[i]), ++z;
  }
  ch.pop_back();
  return ch;
}
inline double seg_area(double r, double d) {
  double alfa = acos((2 * r * r - d * d) / r / r * 0.5);
  return 0.5 * (alfa - sin(alfa)) * r * r;
}
int main() {
  int N;
  double R;
  cin >> N >> R;
  vector<point> p(N);
  for (int i = 0; i < N; ++i) cin >> p[i].x >> p[i].y;
  p = convex_hull(p);
  N = p.size();
  vector<int> l(N), r(N);
  for (int i = 0; i < N; ++i) l[i] = (i - 1 + N) % N, r[i] = (i + 1) % N;
  vector<double> rad(N);
  set<pair<double, int> > S;
  for (int i = 0; i < N; ++i) {
    rad[i] = radius(p[l[i]], p[i], p[r[i]]);
    S.insert(make_pair(-rad[i], i));
  }
  while (S.size() > 2 && -S.begin()->first > R) {
    int i = S.begin()->second;
    point A = p[i], B = p[l[i]], C = p[r[i]];
    double a = dist2(B, C), b = dist2(A, C), c = dist2(A, B);
    if (b > a && b > c)
      i = l[i];
    else if (c > a && c > b)
      i = r[i];
    S.erase(make_pair(-rad[i], i));
    r[l[i]] = r[i];
    l[r[i]] = l[i];
    S.erase(make_pair(-rad[l[i]], l[i]));
    S.erase(make_pair(-rad[r[i]], r[i]));
    rad[l[i]] = radius(p[l[l[i]]], p[l[i]], p[r[l[i]]]);
    rad[r[i]] = radius(p[l[r[i]]], p[r[i]], p[r[r[i]]]);
    S.insert(make_pair(-rad[l[i]], l[i]));
    S.insert(make_pair(-rad[r[i]], r[i]));
  }
  vector<point> q;
  for (int i = S.begin()->second, j = 0; j < (int)S.size(); i = r[i], ++j)
    q.push_back(p[i]);
  p = q;
  double ans = area(p);
  p.push_back(p[0]);
  for (size_t i = 0; i < p.size() - 1; ++i)
    ans += seg_area(R, dist(p[i], p[i + 1]));
  cout << fixed << setprecision(8) << ans << "\n";
  return 0;
}
