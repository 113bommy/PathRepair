#include <bits/stdc++.h>
using namespace std;
const int INFI = 1e9 + 5;
const long long int INFL = 4e18 + 5;
template <class T>
void aread(T* arr, int ___n) {
  for (int i = 0; i < ___n; ++i) {
    cin >> arr[i];
  }
}
template <class crd>
long long int sgn(const crd& x) {
  return x > ((crd)((long double)1e-9))      ? 1
         : x < ((crd) - ((long double)1e-9)) ? -1
                                             : 0;
}
template <class crd>
struct pt {
  crd x;
  crd y;
  pt& operator=(const pt& other) {
    x = other.x;
    y = other.y;
    return *this;
  }
  pt& operator+=(const pt& other) {
    x += other.x;
    y += other.y;
    return *this;
  }
  pt& operator-=(const pt& other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }
  pt& operator*=(const crd& t) {
    x *= t;
    y *= t;
    return *this;
  }
  pt& operator/=(const crd& t) {
    assert(t != 0);
    x /= t;
    y /= t;
    return *this;
  }
  pt operator+(const pt& other) const { return pt<crd>(*this) += other; }
  pt operator-(const pt& other) const { return pt<crd>(*this) -= other; }
  pt operator*(const crd& t) const { return pt<crd>(*this) *= t; }
  pt operator/(const crd& t) const { return pt<crd>(*this) /= t; }
  operator pt<long double>() const {
    pt<long double> newpt;
    newpt.x = this->x;
    newpt.y = this->y;
    return newpt;
  }
};
template <class crd>
pt<crd> operator*(const crd& t, const pt<crd>& pt) {
  return pt * t;
}
template <class crd>
crd dot(const pt<crd>& l, const pt<crd>& r) {
  return l.x * r.x + l.y * r.y;
}
template <class crd>
crd norm(const pt<crd>& a) {
  return dot(a, a);
}
template <class crd>
long double abs(const pt<crd>& a) {
  return sqrtl(norm(a));
}
template <class crd>
crd cross(const pt<crd>& l, const pt<crd>& r) {
  return l.x * r.y - l.y * r.x;
}
template <class crd>
bool upper(const pt<crd>& a) {
  return ((a.y > 0) || (!a.y && a.x > 0));
}
template <class crd>
bool operator<(const pt<crd>& a, const pt<crd>& b) {
  if (upper(a) != upper(b)) return upper(a);
  return cross(a, b) > 0;
}
pt<long double> intersection(const pt<long double>& a1,
                             const pt<long double>& a2,
                             const pt<long double>& b1,
                             const pt<long double>& b2) {
  return a1 + ((a2 - a1) * cross(b1 - a1, b2 - b1) / cross(a2 - a1, b2 - b1));
}
template <class crd>
bool intersection1d(crd l1, crd r1, crd l2, crd r2) {
  if (l1 > r1) {
    r1 += l1;
    l1 = r1 - l1;
    r1 -= l1;
  }
  if (l2 > r2) {
    r2 += l2;
    l2 = r2 - l2;
    r2 -= l2;
  }
  return max(l1, l2) <= min(r1, r2) + ((crd)((long double)1e-9));
}
template <class crd>
bool segseg(const pt<crd>& a1, const pt<crd>& a2, const pt<crd>& b1,
            const pt<crd>& b2) {
  return intersection1d(a1.y, a2.y, b1.y, b2.y) &&
         intersection1d(a1.x, a2.x, b1.x, b2.x) &&
         sgn(cross(a1 - b1, b2 - b1)) * sgn(cross(a2 - b1, b2 - b1)) <= 0 &&
         sgn(cross(b1 - a1, a2 - a1)) * sgn(cross(b2 - a1, a2 - a1)) <= 0;
}
template <class crd>
long double polyarea(const vector<pt<crd>>& points) {
  int sz = points.size();
  long double res = 0;
  for (int i = 0; i < sz; ++i) {
    res += (long double)cross(points[i], points[(i == sz - 1) ? 0 : i + 1]);
  }
  return abs(res / 2.0);
}
long double evaluate_line(const pt<long double>& a, const pt<long double>& b,
                          long double x) {
  if (abs(a.x - b.x) < ((long double)1e-9)) {
    return a.y;
  }
  return a.y + (b.y - a.y) * (x - a.x) / (b.x - a.x);
}
const int maxn = 25e3 + 5;
int n;
struct car {
  pt<long double> o;
  pt<long double> d;
  long double s;
} cars[maxn];
typedef struct seg {
  pt<long double> s;
  pt<long double> e;
  int id;
} seg;
bool operator<(const seg& a, const seg& b) {
  long double ex = max(min(a.s.x, a.e.x), min(b.s.x, b.e.x));
  return evaluate_line(a.s, a.e, ex) <
         evaluate_line(b.s, b.e, ex) - ((long double)1e-9);
}
seg lines[maxn];
set<seg>::iterator prev(set<seg>::iterator it, const set<seg>& s) {
  return it == s.begin() ? s.end() : --it;
}
set<seg>::iterator next(set<seg>::iterator it, const set<seg>& s) {
  return ++it;
}
typedef struct ev {
  long double x;
  int type;
  int id;
} ev;
bool operator<(const ev& a, const ev& other) {
  if (abs(a.x - other.x) <= ((long double)1e-9)) {
    return a.type > other.type;
  }
  return a.x < other.x;
}
set<seg>::const_iterator where[maxn];
bool crash(long double m) {
  vector<ev> events;
  for (int i = 0; i < n; ++i) {
    lines[i].s = cars[i].o;
    lines[i].e = cars[i].o + cars[i].d * m;
    lines[i].id = i;
    events.push_back(ev{min(lines[i].s.x, lines[i].e.x), 1, i});
    events.push_back(ev{max(lines[i].s.x, lines[i].e.x), 0, i});
  }
  sort((events).begin(), (events).end());
  set<seg> ordering;
  for (auto e : events) {
    if (e.type == 1) {
      set<seg>::iterator up = ordering.lower_bound(lines[e.id]);
      set<seg>::iterator down = prev(up, ordering);
      if (up != ordering.end() &&
          segseg((*up).s, (*up).e, lines[e.id].s, lines[e.id].e)) {
        return true;
      }
      if (down != ordering.end() &&
          segseg((*down).s, (*down).e, lines[e.id].s, lines[e.id].e)) {
        return true;
      }
      where[e.id] = ordering.insert(lines[e.id]).first;
    } else {
      set<seg>::iterator up = next(where[e.id]);
      set<seg>::iterator down = prev(where[e.id]);
      if (up != ordering.end() && down != ordering.end() &&
          segseg((*up).s, (*up).e, (*down).s, (*down).e)) {
        return true;
      }
      ordering.erase(where[e.id]);
    }
  }
  return false;
}
int main() {
  const long double pers = 5e-7;
  cout << fixed << setprecision(20);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> cars[i].o.x >> cars[i].o.y >> cars[i].d.x >> cars[i].d.y >>
        cars[i].s;
    cars[i].d /= abs(cars[i].d);
    cars[i].d *= cars[i].s;
  }
  long double l = ((long double)1e-9);
  long double h = 1e12;
  if (!crash(h)) {
    cout << "No show :(" << endl;
  } else {
    while (h - l > pers) {
      long double m = l + (h - l) / 2.0;
      if (crash(m)) {
        h = m - ((long double)1e-9);
      } else {
        l = m + ((long double)1e-9);
      }
    }
    cout << l << endl;
  }
}
