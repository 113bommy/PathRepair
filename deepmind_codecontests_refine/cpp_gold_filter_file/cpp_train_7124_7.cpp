#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-8;
const double PI = acos(-1);
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &t) {
  os << "[";
  for (__typeof((t).begin()) it = (t).begin(); it != (t).end(); ++it) {
    if (it != t.begin()) os << ",";
    os << *it;
  }
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &t) {
  os << "{";
  for (__typeof((t).begin()) it = (t).begin(); it != (t).end(); ++it) {
    if (it != t.begin()) os << ",";
    os << *it;
  }
  os << "}";
  return os;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) {
  return os << "(" << t.first << "," << t.second << ")";
}
template <int N, class Tuple>
void out(ostream &, const Tuple &) {}
template <int N, class Tuple, class, class... Ts>
void out(ostream &os, const Tuple &t) {
  if (N) os << ",";
  os << get<N>(t);
  out<N + 1, Tuple, Ts...>(os, t);
}
template <class... Ts>
ostream &operator<<(ostream &os, const tuple<Ts...> &t) {
  os << "(";
  out<0, tuple<Ts...>, Ts...>(os, t);
  os << ")";
  return os;
}
template <class T>
void output(T *a, int n) {
  for (int i = 0; i < (int)(n); ++i) {
    if (i) cout << ",";
    cout << a[i];
  }
  cout << endl;
}
template <class T>
void output(T *a, int n, int m) {
  for (int i = 0; i < (int)(n); ++i) output(a[i], m);
}
double cross(const complex<double> &a, const complex<double> &b) {
  return imag(conj(a) * b);
}
double dot(const complex<double> &a, const complex<double> &b) {
  return real(conj(a) * b);
}
struct C {
  complex<double> p;
  double r;
  C(const complex<double> &p, double r) : p(p), r(r) {}
};
vector<complex<double> > crosspointCC(double r, const C &c) {
  vector<complex<double> > ret;
  double d = abs(c.p);
  if (abs(r - c.r) > d + EPS) return ret;
  double x = (d * d + r * r - c.r * c.r) / (2 * d);
  complex<double> cent = c.p / d * x;
  complex<double> vect = c.p * complex<double>(0, 1 / d);
  double t = sqrt(max(0., r * r - x * x));
  ret.push_back(cent - vect * t);
  ret.push_back(cent + vect * t);
  return ret;
}
vector<complex<double> > crosspointCC(const C &c1, const C &c2) {
  return crosspointCC(c1.r, C(c2.p - c1.p, c2.r));
}
int quadrant(const complex<double> &a) {
  if (a.real() > 0 && a.imag() >= 0) return 0;
  if (a.real() <= 0 && a.imag() > 0) return 1;
  if (a.real() < 0 && a.imag() <= 0) return 2;
  return 3;
}
bool cmpAngle(const complex<double> &a, const complex<double> &b) {
  int q1 = quadrant(a);
  int q2 = quadrant(b);
  if (q1 != q2) return q1 < q2;
  return cross(a, b) > 0;
}
complex<double> p[20000];
double r[20000];
struct Event {
  complex<double> p;
  bool in;
  pair<int, int> id;
  Event(const complex<double> &p, bool in, const pair<int, int> &id)
      : p(p), in(in), id(id) {}
  bool operator<(const Event &e) const {
    if (dot(p, e.p) > 0 && abs(cross(p, e.p)) < EPS) {
      return in > e.in;
    } else {
      return cmpAngle(p, e.p);
    }
  }
};
int main() {
  int n, d;
  while (cin >> n >> d) {
    for (int i = 0; i < (int)(n); ++i) {
      int X, Y, R;
      scanf("%d%d%d", &X, &Y, &R);
      p[i] = complex<double>(X, Y);
      r[i] = R;
    }
    vector<Event> events;
    for (int i = 0; i < (int)(n); ++i) {
      double dis = abs(p[i]);
      for (int j = max(0, int((dis - r[i]) / d) - 1);; ++j) {
        if (d * j > dis + r[i] + EPS) break;
        if (d * j < dis - r[i] - EPS) continue;
        vector<complex<double> > vp = crosspointCC(d * j, C(p[i], r[i]));
        if (vp.size() == 0) continue;
        if (cross(vp[0], vp[1]) < 0) {
          swap(vp[0], vp[1]);
        }
        events.emplace_back(vp[0], 1, pair<int, int>(i, j));
        events.emplace_back(vp[1], 0, pair<int, int>(i, j));
      }
    }
    sort((events).begin(), (events).end());
    int cnt = 0;
    int ans = 0;
    set<pair<int, int> > S;
    for (int ii = 0; ii < (int)(2 * events.size()); ++ii) {
      int i = ii % events.size();
      if (events[i].in) {
        cnt++;
        S.insert(events[i].id);
        chmax(ans, cnt);
      } else {
        if (S.count(events[i].id)) {
          cnt--;
        }
      }
    }
    cout << ans << endl;
  }
}
