#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-9;
double fRand(double fMin, double fMax) {
  double f = (double)rand() / RAND_MAX;
  return fMin + f * (fMax - fMin);
}
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
struct pt {
  double x, y;
  pt operator+(pt p) { return {x + p.x, y + p.y}; }
  pt operator-(pt p) { return {x - p.x, y - p.y}; }
  pt operator*(double k) { return {x * k, y * k}; }
  pt operator/(double k) { return {x / k, y / k}; }
  double operator*(pt p) { return x * p.y - y * p.x; }
  double operator|(pt p) { return x * p.x + y * p.y; }
  friend istream &operator>>(istream &is, pt &p) {
    is >> p.x >> p.y;
    return is;
  }
  friend ostream &operator<<(ostream &os, pt &p) {
    os << "(" << p.x << " " << p.y << ")";
    return os;
  }
};
pt perp(pt v) { return {-v.y, v.x}; }
double sq(pt v) { return v | v; }
double tangentsPolar(pt o1, double r1, pt o2, double r2, bool inner, int sgn) {
  if (inner) r2 = -r2;
  pt d = o2 - o1;
  double dr = r1 - r2, d2 = sq(d), h2 = d2 - dr * dr;
  pt v = (d * dr + perp(d) * sqrt(h2) * sgn) / d2;
  pt p1 = o1 + v * r1, p2 = o2 + v * r2;
  double x = (p1.x - p2.x) * sgn, y = (p1.y - p2.y) * sgn;
  return atan2(y, x);
}
struct Event {
  double polar;
  bool open;
  bool operator<(const Event &rhs) const { return polar < rhs.polar; }
};
bool cmp(Event e, double polar) { return e.polar <= polar; }
const int MAXN = 1005;
int n, k;
pt o[MAXN];
double r[MAXN];
int main() {
  cin >> n >> k;
  for (int i = (0); i <= (n - 1); ++i) cin >> o[i] >> r[i];
  int maxCir = 1;
  for (int i = (0); i <= (n - 1); ++i) {
    vector<Event> events;
    for (int j = (0); j <= (n - 1); ++j) {
      if (i == j) continue;
      for (int sgn : {-1, 1}) {
        double lo = tangentsPolar(o[i], r[i], o[j], r[j], false, sgn);
        double hi = tangentsPolar(o[i], r[i], o[j], r[j], true, sgn);
        if (sgn == 1) swap(lo, hi);
        if (lo < hi) {
          events.push_back({lo, true});
          events.push_back({hi, false});
        } else {
          events.push_back({lo, true});
          events.push_back({PI + EPS, false});
          events.push_back({-PI, true});
          events.push_back({hi, false});
        }
      }
    }
    sort(events.begin(), events.end());
    int cnt = 1, j = 0;
    for (Event e : events) {
      while (j < (int)events.size() && cmp(events[j], e.polar)) {
        cnt += (events[j].open) ? 1 : -1;
        ++j;
      }
      maxCir = max(maxCir, cnt);
    }
  }
  cout << 1 + 1LL * k * (k + 1) / 2 + 1LL * (k + 1) * (maxCir - 1) +
              (n - maxCir);
  return 0;
}
