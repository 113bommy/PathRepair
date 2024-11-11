#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class U>
T fstTrue(T lo, T hi, U first) {
  hi++;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    first(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class U>
T lstTrue(T lo, T hi, U first) {
  lo--;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    first(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
template <class T>
void remDup(vector<T>& v) {
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
}
template <class T, class U>
void erase(T& t, const U& u) {
  auto it = t.find(u);
  assert(it != end(t));
  t.erase(u);
}
template <class T>
void re(complex<T>& c);
template <class T, class U>
void re(pair<T, U>& p);
template <class T>
void re(vector<T>& v);
template <class T, size_t SZ>
void re(AR<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(db& d) {
  str t;
  re(t);
  d = stod(t);
}
void re(ld& d) {
  str t;
  re(t);
  d = stold(t);
}
template <class T, class... U>
void re(T& t, U&... u) {
  re(t);
  re(u...);
}
template <class T>
void re(complex<T>& c) {
  T a, b;
  re(a, b);
  c = {a, b};
}
template <class T, class U>
void re(pair<T, U>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& x) {
  for (auto& a : x) re(a);
}
template <class T, size_t SZ>
void re(AR<T, SZ>& x) {
  for (auto& a : x) re(a);
}
str to_string(char c) { return str(1, c); }
str to_string(const char* second) { return (str)second; }
str to_string(str second) { return second; }
str to_string(bool b) { return to_string((int)b); }
template <class T>
str to_string(complex<T> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}
str to_string(vector<bool> v) {
  str res = "{";
  for (int i = (0); i < ((int)(v).size()); ++i) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t SZ>
str to_string(bitset<SZ> b) {
  str res = "";
  for (int i = (0); i < (SZ); ++i) res += char('0' + b[i]);
  return res;
}
template <class T, class U>
str to_string(pair<T, U> p);
template <class T>
str to_string(T v) {
  bool fst = 1;
  str res = "";
  for (const auto& x : v) {
    if (!fst) res += " ";
    fst = 0;
    res += to_string(x);
  }
  return res;
}
template <class T, class U>
str to_string(pair<T, U> p) {
  return to_string(p.first) + " " + to_string(p.second);
}
template <class T>
void pr(T x) {
  cout << to_string(x);
}
template <class T, class... U>
void pr(const T& t, const U&... u) {
  pr(t);
  pr(u...);
}
void ps() { pr("\n"); }
template <class T, class... U>
void ps(const T& t, const U&... u) {
  pr(t);
  if (sizeof...(u)) pr(" ");
  ps(u...);
}
void DBG() { cerr << "]" << endl; }
template <class T, class... U>
void DBG(const T& t, const U&... u) {
  cerr << to_string(t);
  if (sizeof...(u)) cerr << ", ";
  DBG(u...);
}
void setIn(str second) { freopen(second.c_str(), "r", stdin); }
void setOut(str second) { freopen(second.c_str(), "w", stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str second = "") {
  unsyncIO();
  if ((int)(second).size()) {
    setIn(second + ".in"), setOut(second + ".out");
  }
}
using T = db;
int sgn(T a) { return (a > 0) - (a < 0); }
T sq(T a) { return a * a; }
T norm(const pair<T, T>& p) { return sq(p.first) + sq(p.second); }
T abs(const pair<T, T>& p) { return sqrt(norm(p)); }
T arg(const pair<T, T>& p) { return atan2(p.second, p.first); }
pair<T, T> conj(const pair<T, T>& p) { return pair<T, T>(p.first, -p.second); }
pair<T, T> perp(const pair<T, T>& p) { return pair<T, T>(-p.second, p.first); }
pair<T, T> dir(T ang) { return pair<T, T>(cos(ang), sin(ang)); }
pair<T, T> operator-(const pair<T, T>& l) {
  return pair<T, T>(-l.first, -l.second);
}
pair<T, T> operator+(const pair<T, T>& l, const pair<T, T>& r) {
  return pair<T, T>(l.first + r.first, l.second + r.second);
}
pair<T, T> operator-(const pair<T, T>& l, const pair<T, T>& r) {
  return pair<T, T>(l.first - r.first, l.second - r.second);
}
pair<T, T> operator*(const pair<T, T>& l, const T& r) {
  return pair<T, T>(l.first * r, l.second * r);
}
pair<T, T> operator*(const T& l, const pair<T, T>& r) { return r * l; }
pair<T, T> operator/(const pair<T, T>& l, const T& r) {
  return pair<T, T>(l.first / r, l.second / r);
}
pair<T, T> operator*(const pair<T, T>& l, const pair<T, T>& r) {
  return pair<T, T>(l.first * r.first - l.second * r.second,
                    l.second * r.first + l.first * r.second);
}
pair<T, T> operator/(const pair<T, T>& l, const pair<T, T>& r) {
  return l * conj(r) / norm(r);
}
pair<T, T>& operator+=(pair<T, T>& l, const pair<T, T>& r) { return l = l + r; }
pair<T, T>& operator-=(pair<T, T>& l, const pair<T, T>& r) { return l = l - r; }
pair<T, T>& operator*=(pair<T, T>& l, const T& r) { return l = l * r; }
pair<T, T>& operator/=(pair<T, T>& l, const T& r) { return l = l / r; }
pair<T, T>& operator*=(pair<T, T>& l, const pair<T, T>& r) { return l = l * r; }
pair<T, T>& operator/=(pair<T, T>& l, const pair<T, T>& r) { return l = l / r; }
pair<T, T> unit(const pair<T, T>& p) { return p / abs(p); }
T dot(const pair<T, T>& a, const pair<T, T>& b) {
  return a.first * b.first + a.second * b.second;
}
T cross(const pair<T, T>& a, const pair<T, T>& b) {
  return a.first * b.second - a.second * b.first;
}
T cross(const pair<T, T>& p, const pair<T, T>& a, const pair<T, T>& b) {
  return cross(a - p, b - p);
}
pair<T, T> reflect(const pair<T, T>& p, const pair<T, T>& a,
                   const pair<T, T>& b) {
  return a + conj((p - a) / (b - a)) * (b - a);
}
pair<T, T> foot(const pair<T, T>& p, const pair<T, T>& a, const pair<T, T>& b) {
  return (p + reflect(p, a, b)) / (T)2;
}
bool onSeg(const pair<T, T>& p, const pair<T, T>& a, const pair<T, T>& b) {
  return cross(a, b, p) == 0 && dot(p - a, p - b) <= 0;
}
int N;
vector<pair<T, T> > poly;
vd dists;
int par;
void genDists() {
  dists = {0};
  for (int i = (0); i < (N); ++i)
    dists.push_back(dists.back() + abs(poly[i] - poly[i + 1]));
}
void rev() {
  par ^= 1;
  db maxY = poly.back().second;
  reverse(begin(poly), end(poly));
  genDists();
  for (auto& t : poly) t.second = maxY - t.second;
}
vector<pair<T, T> > ans;
db vel;
pair<T, T> ternary(db lo, db hi, function<db(db)> eval) {
  for (int _ = (0); _ < (40); ++_) {
    db m1 = (2 * lo + hi) / 3;
    db m2 = (lo + 2 * hi) / 3;
    if (eval(m1) < eval(m2))
      hi = m2;
    else
      lo = m1;
  }
  return {lo, eval(lo)};
}
map<pi, pair<T, T> > calced[2];
void tri(int l, int r) {
  assert(l < r);
  pair<T, T> dirl = unit(poly[l + 1] - poly[l]),
             dirr = unit(poly[r + 1] - poly[r]);
  auto eval = [&](db t1, db t2) {
    pair<T, T> pos1 = poly[l] + t1 * dirl;
    pair<T, T> pos2 = poly[r] + t2 * dirr;
    return abs(pos2 - pos1) / ((dists[r] + t2) - (dists[l] + t1));
  };
  function<db(db)> getMin = [&](db rig) {
    return ternary(0, dists[l + 1] - dists[l],
                   [&](db x) { return eval(x, rig); })
        .second;
  };
  if (!calced[par].count({l, r}))
    calced[par][{l, r}] = ternary(0, dists[r + 1] - dists[r], getMin);
  pair<T, T> mid = calced[par][{l, r}];
  if (mid.second > 1 / vel) return;
  db L, R;
  {
    db lo = 0, hi = mid.first;
    for (int _ = (0); _ < (40); ++_) {
      db m = (lo + hi) / 2;
      if (getMin(m) < 1 / vel)
        hi = m;
      else
        lo = m;
    }
    L = lo;
  }
  {
    db lo = mid.first, hi = dists[r + 1] - dists[r];
    for (int _ = (0); _ < (40); ++_) {
      db m = (lo + hi) / 2;
      if (getMin(m) < 1 / vel)
        lo = m;
      else
        hi = m;
    }
    R = lo;
  }
  ans.push_back({dists[r] + L, dists[r] + R});
}
vector<pair<T, T> > ranges() {
  ans.clear();
  for (int i = (0); i < (N); ++i)
    for (int j = (i + 1); j < (N); ++j) tri(i, j);
  sort(begin(ans), end(ans));
  vector<pair<T, T> > ANS;
  for (auto& t : ans) {
    if (!(int)(ANS).size() || ANS.back().second < t.first)
      ANS.push_back(t);
    else
      ckmax(ANS.back().second, t.second);
  }
  return ANS;
}
bool intervalIsect(pair<T, T> a, pair<T, T> b) {
  if (a.second < b.first) return 0;
  if (b.second < a.first) return 0;
  return 1;
}
bool escape(db mid) {
  0;
  vel = mid;
  vector<pair<T, T> > lef = ranges();
  rev();
  vector<pair<T, T> > rig = ranges();
  rev();
  for (auto& t : rig) t = {dists.back() - t.second, dists.back() - t.first};
  reverse(begin(rig), end(rig));
  int il = 0, ir = 0;
  while (il < (int)(lef).size() && ir < (int)(rig).size()) {
    if (intervalIsect(lef[il], rig[ir])) return 1;
    if (lef[il].first < rig[ir].first)
      il++;
    else
      ir++;
  }
  return 0;
}
int main() {
  clock_t beg = clock();
  setIO();
  re(N);
  poly.resize(N + 1);
  re(poly);
  genDists();
  db lo = 1, hi = 1e4;
  while (hi / lo > 1 + 1e-7) {
    db mid = sqrt(lo * hi);
    if (escape(mid))
      lo = mid;
    else
      hi = mid;
  }
  cout << fixed << setprecision(9) << lo;
  0;
}
