#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
struct pt {
  long double x, y;
};
struct seg {
  pt p, q;
  int id;
  long double get_y(long double x) const {
    if (abs(p.x - q.x) < EPS) return p.y;
    return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
  }
};
inline bool intersect1d(long double l1, long double r1, long double l2,
                        long double r2) {
  if (l1 > r1) swap(l1, r1);
  if (l2 > r2) swap(l2, r2);
  return max(l1, l2) <= min(r1, r2) + EPS;
}
inline int vec(const pt& a, const pt& b, const pt& c) {
  long double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  return abs(s) < EPS ? 0 : s > 0 ? +1 : -1;
}
bool intersect(const seg& a, const seg& b) {
  return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
         intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
         vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
         vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}
bool operator<(const seg& a, const seg& b) {
  long double x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
  return a.get_y(x) < b.get_y(x) - EPS;
}
struct event {
  long double x;
  int tp, id;
  event() {}
  event(long double x, int tp, int id) : x(x), tp(tp), id(id) {}
  bool operator<(const event& e) const {
    if (abs(x - e.x) > EPS) return x < e.x;
    return tp > e.tp;
  }
};
set<seg> s;
vector<set<seg>::iterator> where;
inline set<seg>::iterator prevq(set<seg>::iterator it) {
  return it == s.begin() ? s.end() : --it;
}
inline set<seg>::iterator nextq(set<seg>::iterator it) { return ++it; }
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
      set<seg>::iterator nxt = s.lower_bound(a[id]), prv = prevq(nxt);
      if (nxt != s.end() && intersect(*nxt, a[id]))
        return make_pair(nxt->id, id);
      if (prv != s.end() && intersect(*prv, a[id]))
        return make_pair(prv->id, id);
      where[id] = s.insert(nxt, a[id]);
    } else {
      set<seg>::iterator nxt = nextq(where[id]), prv = prevq(where[id]);
      if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
        return make_pair(prv->id, nxt->id);
      s.erase(where[id]);
    }
  }
  return make_pair(-1, -1);
}
struct Car {
  long double x, y, dx, dy, s;
  Car(long double x, long double y, long double dx, long double dy,
      long double s)
      : x(x), y(y), dx(dx), dy(dy), s(s){};
};
int main() {
  ios_base ::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  vector<Car> cars;
  for (int i = 0; i < n; i++) {
    long double x, y, dx, dy, s;
    cin >> x >> y >> dx >> dy >> s;
    long double ll = dx * dx + dy * dy;
    ll = sqrt(ll);
    if (ll > EPS) {
      dx /= ll;
      dy /= ll;
    }
    cars.push_back(Car(x, y, dx, dy, s));
  }
  long double l = 0;
  long double r = 10;
  bool ok = false;
  for (int it = 0; it < 200; it++) {
    if (abs(r - l) < EPS) break;
    long double mid = (r + l) / 2.;
    vector<seg> a(n);
    for (int i = 0; i < n; i++) {
      a[i].p.x = cars[i].x;
      a[i].p.y = cars[i].y;
      a[i].q.x = cars[i].x + cars[i].dx * cars[i].s * mid;
      a[i].q.y = cars[i].y + cars[i].dy * cars[i].s * mid;
      a[i].id = i;
    }
    auto pr = solve(a);
    if (pr.first == -1) {
      l = mid;
    } else {
      r = mid;
      ok = true;
    }
  }
  cout.precision(30);
  if (ok) {
    cout << l << endl;
  } else {
    cout << "No show :(" << endl;
  }
}
