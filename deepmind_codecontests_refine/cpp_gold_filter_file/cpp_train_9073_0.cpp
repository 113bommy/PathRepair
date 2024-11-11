#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class t, class u>
void chmax(t& first, u second) {
  if (first < second) first = second;
}
template <class t, class u>
void chmin(t& first, u second) {
  if (second < first) first = second;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using pi = pair<ll, ll>;
using vi = vc<ll>;
template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <class t>
ostream& operator<<(ostream& os, const vc<t>& v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
using uint = unsigned;
using ull = unsigned long long;
template <ll i, class T>
void print_tuple(ostream&, const T&) {}
template <ll i, class T, class H, class... Args>
void print_tuple(ostream& os, const T& t) {
  if (i) os << ",";
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}
template <class... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << "{";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << "}";
}
void print(ll x, ll suc = 1) {
  cout << x;
  if (suc == 1) cout << endl;
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(ll n, ll off = 0) {
  vi v(n);
  for (ll i = ll(0); i < ll(n); i++) v[i] = read() + off;
  return v;
}
template <class T>
void print(const vector<T>& v, ll suc = 1) {
  for (ll i = ll(0); i < ll(v.size()); i++)
    print(v[i], i == ll(v.size()) - 1 ? suc : 2);
}
string readString() {
  string s;
  cin >> s;
  return s;
}
template <class T>
T sq(const T& t) {
  return t * t;
}
void yes(bool ex = true) {
  cout << "Yes" << endl;
  if (ex) exit(0);
}
void no(bool ex = true) {
  cout << "No" << endl;
  if (ex) exit(0);
}
constexpr ll ten(ll n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const ll inf = infLL;
ll topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
ll topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
ll popcount(signed t) { return __builtin_popcount(t); }
ll popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(ll i) { return i && (i & -i) == i; }
bool inc(ll first, ll second, ll c) { return first <= second && second <= c; }
template <class t>
void mkuni(vc<t>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
ll rand_int(ll l, ll r) {
  static random_device rd;
  static mt19937 gen(rd());
  return uniform_int_distribution<ll>(l, r)(gen);
}
template <class t, class u>
struct slide {
  vc<t> x;
  vi y;
  u f;
  ll second, e, c, d;
  slide(ll n, u ff = u()) : x(n), y(n), f(ff) { init(); }
  void init() { second = e = c = d = 0; }
  void push(t first) {
    while (second < e && f(x[e - 1], first)) e--;
    x[e] = first;
    y[e++] = c++;
  }
  void pop() {
    if (y[second] == d) second++;
    d++;
  }
  t get() { return x[second]; }
};
using ld = long double;
using cm = complex<ld>;
const ld eps = 0;
const ld PI = acos(ld(-1));
ll sgn(ld first) { return first < -eps ? -1 : (first > eps ? 1 : 0); }
ld dot(cm first, cm second) {
  return first.real() * second.real() + first.imag() * second.imag();
}
ld crs(cm first, cm second) {
  return first.real() * second.imag() - first.imag() * second.real();
}
ld crs(cm first, cm second, cm c) { return crs(second - first, c - first); }
ll ccw(cm first, cm second) { return sgn(crs(first, second)); }
ll ccw(cm first, cm second, cm c) { return ccw(second - first, c - first); }
auto cmcmp = [](cm first, cm second) {
  ll s = sgn(first.real() - second.real());
  if (s)
    return s < 0;
  else
    return sgn(first.imag() - second.imag()) < 0;
};
bool cmeq(cm first, cm second) {
  return sgn(first.real() - second.real()) == 0 &&
         sgn(first.imag() - second.imag()) == 0;
};
ll argtype(cm first) {
  if (sgn(first.imag()) == 0) return first.real() < 0 ? 1 : 0;
  return first.imag() < 0 ? 0 : 1;
}
ll argcmp(cm first, cm second) {
  ll at = argtype(first), bt = argtype(second);
  if (at != bt) return at < bt ? -1 : 1;
  return -ccw(first, second);
};
ll bet(cm first, cm second, cm c) {
  cm d = second - first;
  ld e = dot(d, c - first);
  if (sgn(e) <= 0) return sgn(e) - 1;
  return sgn(e - norm(d)) + 1;
}
ll qeq(ld first, ld second, ld c, ld& d, ld& e) {
  ld f = second * second - 4 * first * c;
  if (sgn(f) < 0) return 0;
  ld g = sqrt(max(f, ld(0)));
  d = (-second + g) / (2 * first);
  e = (-second - g) / (2 * first);
  return sgn(f) + 1;
}
ll cont(cm first, cm second, cm c, cm d) {
  if (ccw(first, second, c) == -1) swap(second, c);
  return min({ccw(first, second, d), ccw(second, c, d), ccw(c, first, d)}) + 1;
}
ld arg(ld first, ld second, ld c) {
  return acos(
      min(max((first * first + second * second - c * c) / (2 * first * second),
              ld(-1)),
          ld(1)));
}
ld turn(cm first, cm second, cm c) {
  return arg((c - second) / (second - first));
}
using ln = pair<cm, cm>;
cm dir(ln first) { return first.second - first.first; }
cm eval(ln first, ld second) { return first.first + dir(first) * second; }
ll bet(ln first, cm second) { return bet(first.first, first.second, second); }
ll ccw(ln first, cm second) { return ccw(first.first, first.second, second); }
cm proj(ln first, cm second) {
  cm c = dir(first);
  return first.first + c * dot(c, second - first.first) / norm(c);
}
cm refl(ln first, cm second) { return ld(2) * proj(first, second) - second; }
ld dsp(ln first, cm second) {
  cm c = proj(first, second);
  if (abs(bet(first.first, first.second, c)) <= 1) return abs(second - c);
  return min(abs(second - first.first), abs(second - first.second));
}
ll iss(ln first, ln second) {
  ll c1 = ccw(first.first, first.second, second.first),
     c2 = ccw(first.first, first.second, second.second);
  ll d1 = ccw(second.first, second.second, first.first),
     d2 = ccw(second.first, second.second, first.second);
  if (c1 || c2 || d1 || d2) return 1 - max(c1 * c2, d1 * d2);
  ll f = bet(first.first, first.second, second.first),
     g = bet(first.first, first.second, second.second);
  if (max(f, g) == -2 || min(f, g) == 2) return 0;
  return 3;
}
cm cll(ln first, ln second) {
  return eval(first, crs(second.first, second.second, first.first) /
                         crs(dir(first), dir(second)));
}
ld dss(ln first, ln second) {
  if (iss(first, second)) return 0;
  return min({dsp(first, second.first), dsp(first, second.second),
              dsp(second, first.first), dsp(second, first.second)});
}
ln vbis(cm first, cm second) {
  cm c = (first + second) * ld(0.5), d = second - first;
  return ln(c, cm(c.real() - d.imag(), c.imag() + d.real()));
}
using cr = pair<cm, ld>;
ll cont(cr first, cm second) {
  return sgn(first.second - abs(second - first.first)) + 1;
}
ll ids(cr first, ln second) {
  return sgn(first.second - dsp(second, first.first)) + 1;
}
ll ics(cr first, ln second) {
  ll c = ids(first, second);
  if (c <= 1) return 4 - c;
  return sgn(max(abs(second.first - first.first),
                 abs(second.second - first.first)) -
             first.second) +
         1;
}
ll ccl(cr first, ln second, ld& c, ld& d) {
  cm e = dir(second);
  cm f = second.first - first.first;
  return qeq(norm(e), 2 * dot(e, f), norm(f) - first.second * first.second, c,
             d);
}
ll icc(cr first, cr second) {
  ld c = abs(first.first - second.first);
  if (sgn(c) == 0 && sgn(first.second - second.second) == 0) return 1;
  ll d = sgn(c + first.second - second.second);
  if (d <= 0) return d + 3;
  ll e = sgn(c + second.second - first.second);
  if (e <= 0) return e + 5;
  ll f = sgn(first.second + second.second - c);
  if (f >= 0) return f + 6;
  return 0;
}
pair<ld, ld> ccc(cr first, cr second) {
  ld c = arg(second.first - first.first);
  ld d = arg(first.second, abs(second.first - first.first), second.second);
  return make_pair(c - d, c + d);
}
ld cseg(ld first, ld second) {
  return first * first * (second - sin(second)) / 2;
}
cr circumc(cm first, cm second, cm c) {
  second -= first;
  c -= first;
  cm r = norm(second) * c - norm(c) * second;
  r = cm(r.imag(), -r.real()) / (2 * crs(second, c));
  return cr(first + r, abs(r));
}
cr mindisc(const vc<cm>& p, array<cm, 3> q, ll i, ll j) {
  if (i == ll(p.size())) {
    if (j == 0)
      return {{0, 0}, -1};
    else if (j == 1)
      return {q[0], 0};
    else if (j == 2)
      return {(q[0] + q[1]) * ld(0.5), abs(q[0] - q[1]) / 2};
    else if (j == 3)
      return circumc(q[0], q[1], q[2]);
    else
      assert(false);
  }
  cr c = mindisc(p, q, i + 1, j);
  if (sgn(abs(c.first - p[i]) - c.second) == 1) {
    assert(j < 3);
    q[j] = p[i];
    return mindisc(p, q, i + 1, j + 1);
  } else
    return c;
}
cr mindisc(vc<cm> p) {
  shuffle(p.begin(), p.end(), mt19937());
  return mindisc(p, array<cm, 3>(), 0, 0);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  ll n, canuse;
  cin >> n >> canuse;
  vc<cm> z;
  ld mn = 0, mx = 1e9;
  for (ll i = ll(0); i < ll(n); i++) {
    ll first, second;
    cin >> first >> second;
    if (first == 0 && second == 0) {
      cout << 0 << endl;
      return 0;
    }
    z.emplace_back(first, second);
    chmin(mx, abs(z.back()));
  }
  vc<ld> ag(n);
  for (ll i = ll(0); i < ll(n); i++) ag[i] = arg(z[i]);
  auto rel = [](ld first) {
    while (sgn(first) < 0) first += 2 * PI;
    while (sgn(first - 2 * PI) > 1) first -= 2 * PI;
    return first;
  };
  slide<pi, greater<pi>> sld(n * 4);
  for (ll _ = ll(0); _ < ll(50); _++) {
    const ld mid = (mn + mx) / 2;
    vc<pair<ld, ld>> lr;
    for (ll i = ll(0); i < ll(n); i++) {
      ld t = acos(min(ld(1), mid / abs(z[i])));
      lr.emplace_back(rel(ag[i] - t), rel(ag[i] + t));
    }
    vc<ld> pos;
    for (auto w : lr) {
      pos.push_back(w.first);
      pos.push_back(w.second);
    }
    sort(pos.begin(), pos.end());
    pos.erase(
        unique(pos.begin(), pos.end(),
               [](ld first, ld second) { return sgn(first - second) == 0; }),
        pos.end());
    ll m = pos.size() * 2;
    vi lf(m, -1);
    for (auto w : lr) {
      ll first =
          lower_bound(pos.begin(), pos.end(), w.first - eps) - pos.begin();
      ll second =
          lower_bound(pos.begin(), pos.end(), w.second - eps) - pos.begin();
      if (second < first) second += m / 2;
      assert(second + 1 < m);
      chmax(lf[second + 1], first);
    }
    for (ll i = ll(0); i < ll(m - 1); i++) chmax(lf[i + 1], lf[i]);
    ll ans = inf;
    sld.init();
    ll j = 0;
    for (ll i = ll(0); i < ll(m); i++) {
      while (j < lf[i]) {
        sld.pop();
        j++;
      }
      pi cur;
      if (lf[i] == -1)
        cur = pi(0, i);
      else
        cur = sld.get();
      if (i >= m / 2) chmin(ans, cur.first + (i - m / 2 < cur.second));
      cur.first++;
      sld.push(cur);
    }
    void(0);
    if (ans <= canuse)
      mn = mid;
    else
      mx = mid;
  }
  cout << mn << endl;
}
