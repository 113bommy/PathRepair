#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const long double eps = 1e-7;
long double T;
bool the_same(long double x, long double y) { return fabsl(x - y) < eps; }
struct point {
  long double x, y;
  long double len() { return sqrt(x * x + y * y); }
};
struct line {
  point s, t;
  void sort() {
    if (the_same(s.x, t.x)) {
      if (s.y > t.y) swap(s, t);
    } else {
      if (s.x > t.x) swap(s, t);
    }
  }
  long double x2y(long double x) const {
    return s.y + (t.y - s.y) / (t.x - s.x) * (x - s.x);
  }
  long double k() const { return (t.y - s.y) / (t.x - s.x); }
};
struct cmp {
  bool operator()(const line& n1, const line& n2) const {
    long double y1 = n1.x2y(T), y2 = n2.x2y(T);
    if (the_same(y1, y2)) {
      if (the_same(n1.k(), n2.k())) {
        if (!the_same(n1.t.x, n2.t.x)) return n1.t.x < n2.t.x;
        if (!the_same(n1.s.x, n2.s.x)) return n1.s.x < n2.s.x;
        if (!the_same(n1.t.y, n2.t.y)) return n1.t.y < n2.t.y;
        if (!the_same(n1.s.y, n2.s.y)) return n1.s.y < n2.s.y;
        return 0;
      }
      return n1.k() < n2.k();
    }
    return y1 < y2;
  }
};
int n;
int x[N], y[N];
long double dx[N], dy[N];
point operator-(point a, point b) { return {a.x - b.x, a.y - b.y}; }
long double operator*(point a, point b) { return a.x * b.y - a.y * b.x; }
long double cross(point a, point b, point c) { return (b - a) * (c - a); }
bool s2s_is_intersect(const line& a, const line& b) {
  long double v1 = cross(a.s, a.t, b.t) * cross(a.s, a.t, b.s);
  long double v2 = cross(b.s, b.t, a.t) * cross(b.s, b.t, a.s);
  if (fabsl(v1) < eps && fabsl(v2) < eps) {
    return max(max((a.s - b.s).len(), (a.s - b.t).len()),
               max((a.t - b.s).len(), (a.t - b.t).len())) <=
           (a.s - a.t).len() + (b.s - b.t).len();
  }
  return v1 <= eps && v2 <= eps;
}
bool check(const vector<line>& d) {
  vector<pair<long double, pair<pair<line, int>, int> > > q;
  int tot = 0;
  for (auto u : d) {
    auto v = u;
    v.sort();
    if (the_same(v.s.x, v.t.x)) {
      q.push_back({v.s.x, {{v, 2}, tot++}});
    } else {
      q.push_back({v.s.x, {{v, 0}, tot}});
      q.push_back({v.t.x, {{v, 1}, tot++}});
    }
  }
  sort(q.begin(), q.end(),
       [](pair<long double, pair<pair<line, int>, int> > a,
          pair<long double, pair<pair<line, int>, int> > b) {
         return the_same(a.first, b.first)
                    ? a.second.first.second < b.second.first.second
                    : a.first < b.first;
       });
  set<line, cmp> f;
  set<line, cmp>::iterator v;
  vector<set<line, cmp>::iterator> i_f(d.size(), f.end());
  for (auto u : q) {
    T = u.first;
    switch (u.second.first.second) {
      case 0:
        i_f[u.second.second] = v = f.insert(u.second.first.first).first;
        if (next(v) != f.end() &&
            s2s_is_intersect(*next(v), u.second.first.first))
          return 1;
        if (v != f.begin() && s2s_is_intersect(*prev(v), u.second.first.first))
          return 1;
        break;
      case 1:
        v = i_f[u.second.second];
        if (next(v) != f.end() &&
            s2s_is_intersect(*next(v), u.second.first.first))
          return 1;
        if (v != f.begin() && s2s_is_intersect(*prev(v), u.second.first.first))
          return 1;
        f.erase(v);
        break;
      case 2:
        v = f.upper_bound(
            {u.second.first.first.s,
             {u.second.first.first.s.x + 1, u.second.first.first.s.y}});
        if (v != f.end() && s2s_is_intersect(*v, u.second.first.first))
          return 1;
        if (v != f.begin() && s2s_is_intersect(*prev(v), u.second.first.first))
          return 1;
        v = f.upper_bound(
            {u.second.first.first.s,
             {u.second.first.first.t.x + 1, u.second.first.first.t.y}});
        if (v != f.end() && s2s_is_intersect(*v, u.second.first.first))
          return 1;
        if (v != f.begin() && s2s_is_intersect(*prev(v), u.second.first.first))
          return 1;
        break;
    }
  }
  return 0;
}
bool check(long double t) {
  vector<line> d;
  for (int i = 1; i <= n; i++) {
    line tmp;
    tmp.s = {(long double)x[i], (long double)y[i]};
    tmp.t = {x[i] + dx[i] * t, y[i] + dy[i] * t};
    d.push_back(tmp);
  }
  return check(d);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int xx, yy, s;
    scanf("%d %d %d %d %d", &x[i], &y[i], &xx, &yy, &s);
    long double tmp = s / sqrtl(xx * xx + yy * yy);
    dx[i] = xx * tmp;
    dy[i] = yy * tmp;
  }
  long double l = 0, r = 1e6, mid;
  if (!check(1e6)) {
    puts("No show :(");
    return 0;
  }
  for (int i = 0; i < 80; i++) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10Lf\n", l);
  return 0;
}
