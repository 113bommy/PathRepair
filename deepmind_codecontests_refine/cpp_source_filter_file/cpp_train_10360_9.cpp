#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void checkMin(T &a, T b) {
  if (b < a) a = b;
}
template <typename T>
inline void checkMax(T &a, T b) {
  if (a < b) a = b;
}
const double EPS = 1E-8;
const double PI = acos(-1.0);
inline int sgn(double x) { return x < -EPS ? -1 : x > EPS; }
struct Point {
  double x, y;
  Point() {}
  Point(double a, double b) : x(a), y(b) {}
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  double abs() { return hypot(x, y); }
  void read() {
    cin >> x >> y;
    x /= 1000, y /= 1000;
  }
  void write() { cout << "(" << x << "," << y << ")" << endl; }
};
const int MAX_N = 50010;
const int MAX_M = MAX_N * 2;
struct Bit {
  int a[MAX_M];
  void clear() { fill(a, a + MAX_M, 0); }
  void add(int i, int d) {
    for (; i < MAX_M; i += i & -i) {
      a[i] += d;
    }
  }
  int query(int i) {
    if (i <= 0) return 0;
    int s = 0;
    for (; i; i -= i & -i) s += a[i];
    return s;
  }
  int query(int i, int j) { return query(j) - query(i - 1); }
} bit;
int n, m;
Point o;
double a[MAX_N], b[MAX_N];
inline double calc_dis(int i, int j) {
  double x = (b[i] - b[j]) / (a[j] - a[i]);
  double y = a[i] * x + b[i];
  return (o - Point(x, y)).abs();
}
int pos[MAX_N];
vector<pair<double, int>> es;
void init_es(double d) {
  es.clear();
  for (int i = 1; i <= n; ++i) {
    double A = a[i] * a[i] + 1;
    double B = 2 * a[i] * (b[i] - o.y) - 2 * o.x;
    double C = o.x * o.x + (b[i] - o.y) * (b[i] - o.y) - d * d;
    double D = B * B - 4 * A * C;
    if (sgn(D) <= 0) continue;
    D = sqrt(D);
    double x1 = (-B + D) / (2 * A), x2 = (-B - D) / (2 * A);
    double y1 = a[i] * x1 + b[i], y2 = a[i] * x2 + b[i];
    es.emplace_back(atan2(y1 - o.y, x1 - o.x), i);
    es.emplace_back(atan2(y2 - o.y, x2 - o.x), i);
  }
  sort((es).begin(), (es).end());
}
long long count_num(double d) {
  init_es(d);
  long long ans = 0;
  for (int i = 0; i < int(int((es).size())); ++i) {
    int id = es[i].second;
    if (pos[id] == -1) {
      bit.add(pos[id] = i + 1, 1);
    } else {
      bit.add(pos[id], -1);
      ans += bit.query(pos[id], i + 1);
      pos[id] = -1;
    }
  }
  return ans;
}
double calc_sum(double d) {
  if (count_num(d) > m) {
    return 0;
  }
  vector<pair<double, int>> sp;
  static pair<int, int> p[MAX_N], q[MAX_M];
  int x = int((es).size());
  for (int i = 0; i < int(x); ++i) {
    int id = es[i].second;
    if (pos[id] == -1) {
      p[id].first = i;
      pos[id] = i + 1;
    } else {
      p[id].second = i;
      double o = es[i].first - es[pos[id] - 1].first;
      if (o > PI) {
        o = 2 * PI - o;
        swap(p[id].first, p[id].second);
      }
      pos[id] = -1;
      sp.emplace_back(o, id);
    }
    q[i] = make_pair(i - 1, i + 1);
  }
  sort((sp).begin(), (sp).end());
  q[0].first = x - 1, q[x - 1].second = 0;
  double ans = 0;
  for (const auto &o : sp) {
    int s = p[o.second].first, t = p[o.second].second;
    for (int j = s; (j = q[j].second) != t;) {
      ans += calc_dis(es[j].second, o.second);
      --m;
    }
    q[q[s].second].first = q[s].first, q[q[s].first].second = q[s].second;
    q[q[t].second].first = q[t].first, q[q[t].first].second = q[t].second;
  }
  return ans + m * d;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  while (cin >> n) {
    o.read();
    cin >> m;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i] >> b[i];
      a[i] /= 1000, b[i] /= 1000;
    }
    fill(pos, pos + MAX_N, -1);
    double l = 0, r = 1e10;
    for (int i = 0; i < int(100); ++i) {
      double mid = (l + r) * 0.5;
      (count_num(mid) < m ? l : r) = mid;
    }
    printf("%.20f\n", calc_sum(l));
  }
  return 0;
}
