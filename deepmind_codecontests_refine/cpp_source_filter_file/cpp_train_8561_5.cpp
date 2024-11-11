#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
const double EPS = 1E-9;
struct pt {
  double x, y;
};
struct seg {
  pt p, q;
  int id;
  double get_y(double x) const {
    if (abs(p.x - q.x) < EPS) return p.y;
    return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
  }
};
bool intersect1d(double l1, double r1, double l2, double r2) {
  if (l1 > r1) swap(l1, r1);
  if (l2 > r2) swap(l2, r2);
  return max(l1, l2) <= min(r1, r2) + EPS;
}
int vec(const pt& a, const pt& b, const pt& c) {
  double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  return abs(s) < EPS ? 0 : s > 0 ? +1 : -1;
}
bool intersect(const seg& a, const seg& b) {
  return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
         intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
         vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
         vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}
bool operator<(const seg& a, const seg& b) {
  double x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
  return a.get_y(x) < b.get_y(x) - EPS;
}
struct event {
  double x;
  int tp, id;
  event() {}
  event(double x, int tp, int id) : x(x), tp(tp), id(id) {}
  bool operator<(const event& e) const {
    if (abs(x - e.x) > EPS) return x < e.x;
    return tp > e.tp;
  }
};
multiset<seg> s;
vector<multiset<seg>::iterator> where;
multiset<seg>::iterator prev(multiset<seg>::iterator it) {
  return it == s.begin() ? s.end() : --it;
}
multiset<seg>::iterator next(multiset<seg>::iterator it) { return ++it; }
pair<int, int> solve(const vector<seg>& a) {
  int n = (int)a.size();
  vector<event> e;
  for (int i = 0; i < n; ++i) {
    e.push_back(event(min(a[i].p.x, a[i].q.x), +1, i));
    e.push_back(event(max(a[i].p.x, a[i].q.x), -1, i));
  }
  sort(e.begin(), e.end());
  s.clear();
  where.resize(a.size());
  for (size_t i = 0; i < e.size(); ++i) {
    int id = e[i].id;
    if (e[i].tp == +1) {
      multiset<seg>::iterator nxt = s.lower_bound(a[id]), prv = prev(nxt);
      if (nxt != s.end() && intersect(*nxt, a[id]))
        return make_pair(nxt->id, id);
      if (prv != s.end() && intersect(*prv, a[id]))
        return make_pair(prv->id, id);
      where[id] = s.insert(nxt, a[id]);
    } else {
      multiset<seg>::iterator nxt = next(where[id]), prv = prev(where[id]);
      if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
        return make_pair(prv->id, nxt->id);
      s.erase(where[id]);
    }
  }
  return make_pair(-1, -1);
}
int sx[60000], sy[60000], ss[60000];
double dx[60000], dy[60000];
int n;
vector<seg> V;
bool ok(double t) {
  V.clear();
  for (int i = (1); i <= (n); i++) {
    pt X;
    X.x = sx[i];
    X.y = sy[i];
    pt Y;
    Y.x = sx[i] + dx[i] * t;
    Y.y = sy[i] + dy[i] * t;
    seg W;
    W.p = X;
    W.q = Y;
    W.id = i;
    V.push_back(W);
  }
  pair<int, int> Z = solve(V);
  return (Z.first != -1);
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) {
    scanf("%d%d%lf%lf%d", &sx[i], &sy[i], &dx[i], &dy[i], &ss[i]);
    double len =
        sqrt(dx[i] * dx[i] * 1.00 + dy[i] * dy[i] * 1.00) / (1.0 * ss[i]);
    dx[i] /= len;
    dy[i] /= len;
  }
  double ret = -1.00;
  double low = 0.00, high = 100000000.00;
  for (int j = (1); j <= (60); j++) {
    double mid = (low + high) / 2.00;
    if (ok(mid)) {
      ret = mid;
      high = mid;
    } else {
      low = mid;
    }
  }
  if (ret < -(1e-9)) {
    puts("No show :(");
  } else {
    printf("%.12f\n", ret);
  }
  return 0;
}
