#include <bits/stdc++.h>
const int mod = 1000000007;
const int gmod = 3;
const int inf = 1039074182;
const double eps = 1e-9;
const long long llinf = 2LL * inf * inf;
template <typename T1, typename T2>
inline void chmin(T1 &x, T2 b) {
  if (b < x) x = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &x, T2 b) {
  if (b > x) x = b;
}
inline void chadd(int &x, int b) {
  x += b - mod;
  x += (x >> 31 & mod);
}
template <typename T1, typename T2>
inline void chadd(T1 &x, T2 b) {
  x += b;
  if (x >= mod) x -= mod;
}
template <typename T1, typename T2>
inline void chmul(T1 &x, T2 b) {
  x = 1LL * x * b % mod;
}
template <typename T1, typename T2>
inline void chmod(T1 &x, T2 b) {
  x %= b, x += b;
  if (x >= b) x -= b;
}
template <typename T>
inline T mabs(T x) {
  return (x < 0 ? -x : x);
}
using namespace std;
using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, vector<T> vec) {
  cout << "{";
  for (int i = 0; i < (int)vec.size(); i++) {
    cout << vec[i];
    if (i != (int)vec.size() - 1) cout << ',';
  }
  cout << "}";
  return cout;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p) {
  cout << "(" << p.first << ',' << p.second << ")";
  return cout;
}
template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s) {
  vector<T> t;
  for (auto x : s) t.push_back(x);
  cout << t;
  return cout;
}
template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s) {
  vector<T> t;
  for (auto x : s) t.push_back(x);
  cout << t;
  return cout;
}
template <typename T>
ostream &operator<<(ostream &cout, queue<T> q) {
  vector<T> t;
  while (q.size()) {
    t.push_back(q.front());
    q.pop();
  }
  cout << t;
  return cout;
}
template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m) {
  for (auto &x : m) {
    cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
  }
  return cout;
}
template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x, const pair<T1, T2> y) {
  x.first += y.first;
  x.second += y.second;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return make_pair(x.first + y.first, x.second + y.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return make_pair(x.first - y.first, x.second - y.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x) {
  return make_pair(-x.first, -x.second);
}
template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec) {
  vector<vector<T>> v;
  int n = vec.size(), m = vec[0].size();
  v.resize(m);
  for (int i = 0; i < m; i++) {
    v[i].resize(n);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = vec[j][i];
    }
  }
  return v;
}
void print0x(int x) {
  std::vector<int> vec;
  while (x) {
    vec.push_back(x & 1);
    x >>= 1;
  }
  std::reverse(vec.begin(), vec.end());
  for (int i = 0; i < (int)vec.size(); i++) {
    std::cout << vec[i];
  }
  std::cout << ' ';
}
template <typename T>
void print0x(T x, int len) {
  std::vector<int> vec;
  while (x) {
    vec.push_back(x & 1);
    x >>= 1;
  }
  reverse(vec.begin(), vec.end());
  for (int i = (int)vec.size(); i < len; i++) {
    putchar('0');
  }
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i];
  }
  std::cout << ' ';
}
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
struct Double {
 public:
  double x;
  Double() {}
  template <typename T>
  Double(const T &_x) : x(_x) {}
  void operator=(const Double &d) { x = d.x; }
  template <typename T>
  void operator=(const T &d) {
    x = d;
  }
  Double operator-() const & { return -x; }
  bool operator==(const Double &d) const & { return (abs(x - d.x) <= eps); }
  bool operator!=(const Double &d) const & { return !(*this == d); }
  bool operator<(const Double &d) const & { return x + eps < d.x; }
  bool operator>(const Double &d) const & { return x - eps > d.x; }
  template <typename T>
  bool operator>(const T &d) const & {
    return x > d;
  }
  bool operator<=(const Double d) const { return !(*this > d); }
  bool operator>=(const Double d) const { return !(*this < d); }
  Double operator-(const Double d) const { return x - d.x; }
  Double operator+(const Double d) const { return x + d.x; }
  Double operator*(const Double d) const { return x * d.x; }
  Double operator/(const Double d) const { return (Double)(x / d.x); }
  void operator++(int) { x++; }
  Double operator/(Double d) { return (Double)(x / d.x); }
  template <typename T>
  Double operator/(T d) {
    return (Double)(x / (double)d);
  }
  void operator+=(const Double &d) { x += d.x; }
  void operator-=(const Double &d) { x -= d.x; }
  void operator*=(const Double &d) { x *= d.x; }
  void operator/=(Double d) { x /= d.x; }
  template <typename T>
  void operator+=(T d) {
    x += d;
  }
  template <typename T>
  void operator-=(T d) {
    x -= d;
  }
  template <typename T>
  void operator*=(T d) {
    x *= d;
  }
};
ostream &operator<<(ostream &cout, Double x) {
  cout << x.x;
  return cout;
}
istream &operator>>(istream &cin, Double &x) {
  cin >> x.x;
  return cin;
}
template <typename T>
struct Point {
  T x;
  T y;
  Point() {}
  Point(T _x, T _y) {
    x = _x;
    y = _y;
  }
  inline T sqrLen() const & { return x * x + y * y; }
  inline bool operator==(const Point<T> &p) const & {
    return (x == p.x && y == p.y);
  }
  inline bool operator!=(const Point<T> &p) const { return !((*this) == p); }
  Point<T> &operator+=(const Point<T> &p) {
    x += p.x;
    y += p.y;
    return (*this);
  }
  Point<T> &operator-=(const Point<T> &p) {
    x -= p.x;
    y -= p.y;
    return (*this);
  }
  Point<T> &operator*=(T k) {
    x *= k;
    y *= k;
    return (*this);
  }
  Point<T> operator+(const Point<T> &p) const & { return Point<T>(*this) += p; }
  Point<T> operator-(const Point<T> &p) const & { return Point<T>(*this) -= p; }
  Point<T> operator*(int k) const & { return Point<T>(*this) *= k; }
  T dotProduct(const Point<T> &p) const & { return x * p.x + y * p.y; }
  T crossProduct(const Point<T> &p) const & { return x * p.y - y * p.x; }
  inline bool counterClockwise(const Point<T> &a, const Point<T> &b) const & {
    return (a - (*this)).crossProduct(b - (*this)) > 0;
  }
  inline bool clockwise(const Point<T> &a, const Point<T> &b) const & {
    return (a - (*this)).crossProduct(b - (*this)) < 0;
  }
  inline bool collinear(const Point<T> &a, const Point<T> &b) const & {
    return ((a - (*this)).crossProduct(b - (*this)) == 0);
  }
  bool operator<(const Point<T> &a) const & {
    if (x != a.x) return x < a.x;
    return y < a.y;
  }
  bool operator>(const Point<T> &a) const & { return a < (*this); }
};
template <typename T>
istream &operator>>(istream &cin, Point<T> &p) {
  cin >> p.x >> p.y;
  return cin;
}
template <typename T>
ostream &operator<<(ostream &cout, const Point<T> &p) {
  cout << make_pair(p.x, p.y);
  return cout;
}
template <typename T>
struct ConvexHull {
  using PT = Point<T>;
  vector<PT> points;
  vector<PT> cuts;
  static inline T mabs(const T &x) { return (x < 0 ? -x : x); }
  static inline T areaOfTriangle(const PT &a, const PT &b, const PT &c) {
    return mabs((b - a).crossProduct(c - a));
  }
  static inline T directedAreaOfTriangle(const PT &a, const PT &b,
                                         const PT &c) {
    return (b - a).crossProduct(c - a);
  }
  inline void init(vector<PT> v) {
    sort(v.begin(), v.end(), [](const PT &a, const PT &b) {
      if (a.x != b.x) return a.x < b.x;
      return a.y < b.y;
    });
    const PT &a = v.front();
    const PT &b = v.back();
    vector<PT> u, d;
    u.push_back(a);
    d.push_back(a);
    for (size_t i = 1; i < v.size(); i++) {
      auto &p = v[i];
      if (p == v.back() || a.counterClockwise(b, p)) {
        while (u.size() >= 2 && !u[u.size() - 2].clockwise(u.back(), p))
          u.pop_back();
        u.push_back(p);
      }
      if (p == v.back() || a.clockwise(b, p)) {
        while (d.size() >= 2 && !d[d.size() - 2].counterClockwise(d.back(), p))
          d.pop_back();
        d.push_back(p);
      }
    }
    for (size_t i = 0; i < d.size(); i++) {
      points.push_back(d[i]);
    }
    for (size_t i = u.size() - 2; i >= 1; i--) {
      points.push_back(u[i]);
    }
    for (size_t i = 1; i < points.size(); i++) {
      cuts.push_back(points[i] - points[0]);
    }
  }
  inline size_t size() const & { return points.size(); }
  inline bool occupy(const PT &_x) {
    PT x = _x - points[0];
    int pos = lower_bound(cuts.begin(), cuts.end(), x,
                          [](const PT &a, const PT &b) {
                            return a.crossProduct(b) > 0;
                          }) -
              cuts.begin();
    if (pos == 0 && x.crossProduct(cuts[0]) == 0) pos++;
    if (pos == int(cuts.size()) || pos == 0) return false;
    PT A = Point<T>(0, 0), B = cuts[pos - 1], C = cuts[pos], D = x;
    return (areaOfTriangle(A, B, C) == areaOfTriangle(A, B, D) +
                                           areaOfTriangle(B, C, D) +
                                           areaOfTriangle(C, A, D));
  }
  PT operator[](size_t pos) const & { return points[pos]; }
  PT &operator[](size_t pos) & { return points[pos]; }
};
template <typename T>
inline ConvexHull<T> minkowskiSum(const ConvexHull<T> &a,
                                  const ConvexHull<T> &b) {
  vector<Point<T>> va, vb;
  ConvexHull<T> hc;
  auto &vc = hc.points;
  for (size_t i = 0; i < a.size() - 1; i++) {
    va.push_back(a[i + 1] - a[i]);
  }
  va.push_back(a[0] - a.points.back());
  for (size_t i = 0; i < b.size() - 1; i++) {
    vb.push_back(b[i + 1] - b[i]);
  }
  vb.push_back(b[0] - b.points.back());
  vc.push_back(a[0] + b[0]);
  vc.resize(va.size() + vb.size() + 1);
  merge(va.begin(), va.end(), vb.begin(), vb.end(), vc.begin() + 1,
        [](const Point<T> &a, const Point<T> &b) {
          return a.crossProduct(b) > 0;
        });
  for (size_t i = 1; i < vc.size(); i++) {
    vc[i] += vc[i - 1];
  }
  vc.pop_back();
  for (size_t i = 1; i < vc.size(); i++) {
    hc.cuts.push_back(vc[i] - vc[0]);
  }
  return hc;
}
template <typename T>
struct LowerHull {
  using PT = Point<T>;
  bool polarCompare(PT o, PT a, PT b) { return (a - o).clockwise(b - o); }
  vector<PT> points;
  inline int size() { return (int)points.size(); }
  inline int insert(PT p) {
    while (size() > 1 &&
           !polarCompare(points[size() - 2], points[size() - 1], p)) {
      points.pop_back();
    }
    points.push_back(p);
    return size();
  }
};
template <typename T>
ostream &operator<<(ostream &cout, LowerHull<T> x) {
  cout << x.points;
  return cout;
}
template <typename T>
struct PersistentLowerHull : public LowerHull<T> {
  using PT = Point<T>;
  struct Event {
    vector<PT> points;
  };
  vector<Event> events;
  inline size_t size() { return LowerHull<T>::size(); }
  inline int persistentInsert(PT p) {
    Event event;
    while (size() > 1 && !polarCompare(p, LowerHull<T>::points[size() - 2],
                                       LowerHull<T>::points[size() - 1])) {
      event.points.push_back(LowerHull<T>::points.back());
      LowerHull<T>::points.pop_back();
    }
    LowerHull<T>::points.push_back(p);
    events.push_back(event);
    return size();
  }
  inline void rollback() {
    LowerHull<T>::points.pop_back();
    while (events.back().points.size()) {
      LowerHull<T>::points.push_back(events.back().points.back());
      events.back().points.pop_back();
    }
    events.pop_back();
  }
};
namespace LICHAOTREE {
template <typename T>
struct DefaultFunction {
  T k;
  T b;
  inline T operator()(T x) const & { return k * x + b; }
  inline void inf() {
    k = 0;
    b = numeric_limits<T>::max() / 2;
    if (b == 0) throw logic_error("no limits for non-fundamental type");
  }
  DefaultFunction() {}
  DefaultFunction(T _k, T _b) : k(_k), b(_b) {}
};
template <typename T, typename _Compare = std::less<T>,
          typename Function = DefaultFunction<T>>
struct LiChaoTree {
  vector<Function> data;
  vector<T> lsh;
  int nn;
  _Compare _comp;
  inline void _init(int n) {
    nn = 1;
    while (nn < n) nn <<= 1;
    data.resize(nn * 2 + 5);
  }
  inline void init(int n) {
    _init(n);
    for (int i = 0; i < nn; i++) {
      lsh.push_back(i);
    }
  }
  inline void init(const vector<T> &_lsh) {
    int n = _lsh.size();
    _init(n);
    lsh = _lsh;
    sort(lsh.begin(), lsh.end());
    for (int i = n; i < nn; i++) {
      lsh.push_back(lsh.back());
    }
  }
  inline void clear() {
    for (int i = 0; i < nn * 2; i++) {
      data[i].inf();
    }
  }
  void insert(int x, int l, int r, Function f) {
    bool mid = _comp(f(lsh[(l + r) >> 1]), data[x](lsh[(l + r) >> 1]));
    bool lef = _comp(f(lsh[l]), data[x](lsh[l]));
    bool rgt = _comp(f(lsh[r]), data[x](lsh[r]));
    if (mid) {
      swap(data[x], f);
    }
    if (lef == rgt) return;
    if (r - l == 1) return;
    if (lef != mid) {
      insert(x * 2, l, (l + r) >> 1, f);
    } else {
      insert(x * 2 + 1, (l + r) >> 1, r, f);
    }
  }
  inline void insert(Function f) { insert(1, 0, nn, f); }
  inline void insert(T k, T b) { insert(Function(k, b)); }
  inline T query(T value) {
    int pos = lower_bound(lsh.begin(), lsh.end(), value) - lsh.begin() + nn;
    int now = 1;
    T res = data[now](value);
    while (pos >= 1) {
      T v = data[pos](value);
      if (_comp(v, res)) res = v;
      pos >>= 1;
    }
    return res;
  }
};
}  // namespace LICHAOTREE
using LICHAOTREE::LiChaoTree;
using namespace std;
int n, m;
using PT = Point<Double>;
PT edges[1005];
struct Segment {
  PT st;
  PT ed;
  Segment() {}
  Segment(PT a, PT b) : st(a), ed(b) {}
  inline Double length() {
    double dx = (ed.x - st.x).x;
    double dy = (ed.y - st.y).x;
    return sqrt(dx * dx + dy * dy);
  }
} theLine;
istream &operator>>(istream &cin, Segment &t) {
  cin >> t.st >> t.ed;
  return cin;
}
ostream &operator<<(ostream &cout, Segment &t) {
  cout << make_pair(t.st, t.ed);
  return cout;
}
PT noInt(2984, 123);
struct Line {
  Double a, b, c;
};
ostream &operator<<(ostream &cout, Line t) {
  cout << '(' << t.a << ',' << t.b << ',' << t.c << ')';
  return cout;
}
inline Double det(Double a, Double b, Double c, Double d) {
  return a * d - b * c;
}
bool equivalent(Line a, Line b) {
  return (det(a.a, a.b, b.a, b.b) == 0 && det(a.b, a.c, b.b, b.c) == 0 &&
          det(a.c, a.a, b.c, b.a) == 0);
}
bool intersect(Line a, Line b, PT &c) {
  Double d = det(a.a, a.b, b.a, b.b);
  if (d == 0) return false;
  c.x = -det(a.c, a.b, b.c, b.b) / d;
  c.y = -det(a.a, a.c, b.a, b.c) / d;
  return true;
}
Line toLine(Segment t) {
  Line res;
  res.a = (t.ed.y - t.st.y);
  res.b = -(t.ed.x - t.st.x);
  res.c = -res.a * t.st.x - res.b * t.st.y;
  return res;
}
bool intersect(Segment a, Line b, PT &c) {
  PT ta = theLine.st, tb = theLine.ed, tc = a.st, td = a.ed;
  if ((ta.clockwise(tb, tc) ^ ta.clockwise(tb, td)) == 0) return 0;
  bool f = intersect(toLine(a), b, c);
  assert(f);
  return true;
}
inline Double dis(PT a, PT b) {
  return sqrt(((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)).x);
}
Double solve(PT a, PT b, PT c, Line t, int bi) {
  Segment x(a, b), y(b, c), z(c, a);
  assert(!equivalent(toLine(x), t));
  cout << fixed;
  cout.precision(10);
  if (equivalent(toLine(y), t)) return (bi ? y.length() : 0);
  assert(!equivalent(toLine(z), t));
  PT ix, iy, iz;
  bool fx, fy, fz;
  tie(fx, fy, fz) =
      make_tuple(intersect(x, t, ix), intersect(y, t, iy), intersect(z, t, iz));
  PT l(numeric_limits<double>::max(), numeric_limits<double>::max()),
      r(numeric_limits<double>::lowest(), numeric_limits<double>::lowest());
  if (fx) chmin(l, ix), chmax(r, ix);
  if (fy) chmin(l, iy), chmax(r, iy);
  if (fz) chmin(l, iz), chmax(r, iz);
  if (!fx && !fy && !fz) return 0;
  return dis(l, r);
}
ConvexHull<Double> hull;
Double query(Line t) {
  Double res = 0;
  for (int i = 0; i < n; i++) {
    int positive =
        (hull.directedAreaOfTriangle(noInt, edges[i], edges[(i + 1) % n]) > 0);
    Double len = solve(noInt, edges[i], edges[(i + 1) % n], t, positive);
    if (positive)
      res += len;
    else
      res -= len;
  }
  return mabs(res);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> edges[i];
    edges[i].x.x *= 100;
    edges[i].y.x *= 100;
  }
  Double area = 0;
  for (int i = 0; i < n; i++) {
    area += hull.directedAreaOfTriangle({0, 0}, edges[i], edges[(i + 1) % n]);
  }
  if (area < 0) {
    reverse(edges + 1, edges + n);
  }
  for (int i = 0; i < m; i++) {
    cin >> theLine;
    theLine.st.x *= 100.0;
    theLine.st.y *= 100.0;
    theLine.ed.x *= 100.0;
    theLine.ed.y *= 100.0;
    cout << fixed;
    cout.precision(10);
    cout << query(toLine(theLine)).x / 100 << endl;
  }
  return 0;
}
