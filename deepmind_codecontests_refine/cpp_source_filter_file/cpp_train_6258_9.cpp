#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
auto& errStream = cerr;
class CerrDummy {
} cerrDummy;
template <class T>
CerrDummy& operator<<(CerrDummy& cd, const T&) {
  return cd;
}
using charTDummy = char;
using traitsDummy = char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy& cd,
                      basic_ostream<charTDummy, traitsDummy>&(
                          basic_ostream<charTDummy, traitsDummy>&)) {
  return cd;
}
using pi = pair<ll, ll>;
using vi = vector<ll>;
using ld = long double;
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  for (ll i = ll(0); i < ll((ll)v.size()); i++) {
    if (i) os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}
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
  os << "(";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << ")";
}
ll read() {
  ll i;
  scanf("%" SCNd64, &i);
  return i;
}
double readDouble() {
  double d;
  scanf("%lf", &d);
  return d;
}
void printSpace() { printf(" "); }
void printEoln() { printf("\n"); }
void print(ll x, ll suc = 1) {
  printf("%" PRId64, x);
  if (suc == 1) printEoln();
  if (suc == 2) printSpace();
}
string readString() {
  static char buf[3341000];
  scanf("%s", buf);
  return string(buf);
}
char* readCharArray() {
  static char buf[3341000];
  static ll bufUsed = 0;
  char* ret = buf + bufUsed;
  scanf("%s", ret);
  bufUsed += strlen(ret) + 1;
  return ret;
}
template <class T, class U>
void chmax(T& a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
void chmin(T& a, U b) {
  if (b < a) a = b;
}
template <class T>
T Sq(const T& t) {
  return t * t;
}
void Yes(bool ex = true) {
  cout << "YES" << endl;
  if (ex) exit(0);
}
void No(bool ex = true) {
  cout << "NO" << endl;
  if (ex) exit(0);
}
const ll infLL = LLONG_MAX / 3;
const ll inf = infLL;
constexpr ll Ten(ll n) { return n == 0 ? 1 : Ten(n - 1) * 10; }
template <class T>
vector<T> Uniqued(const vector<T>& vv) {
  auto v(vv);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}
template <class T>
void MakeUniqued(vector<T>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
template <class Num>
struct Vector {
  vector<Num> v;
  Vector(ll s = 0) { v.resize(s, Num(0)); }
  ll size() const { return v.size(); }
  Num& operator[](ll i) { return v[i]; }
  Num const& operator[](ll i) const { return v[i]; }
  Vector& operator+=(const Vector& rhs) {
    assert(size() == rhs.size());
    for (ll i = ll(0); i < ll(size()); i++) v[i] += rhs[i];
    return *this;
  }
  Vector& operator-=(const Vector& rhs) {
    assert(size() == rhs.size());
    for (ll i = ll(0); i < ll(size()); i++) v[i] -= rhs[i];
    return *this;
  }
  Vector& operator*=(const Num& x) {
    for (ll i = ll(0); i < ll(size()); i++) v[i] *= x;
    return *this;
  }
  Vector& operator/=(const Num& x) {
    Num y = Num(1) / x;
    for (ll i = ll(0); i < ll(size()); i++) v[i] *= y;
    return *this;
  }
  Vector operator+(const Vector& rhs) const { return Vector(*this) += rhs; }
  Vector operator-(const Vector& rhs) const { return Vector(*this) -= rhs; }
  Vector operator*(const Num& x) const { return Vector(*this) *= x; }
  Vector operator/(const Num& x) const { return Vector(*this) /= x; }
};
template <class Num>
Num Dot(const Vector<Num>& a, const Vector<Num>& b) {
  assert(a.size() == b.size());
  const ll S = a.size();
  Num ans = 0;
  for (ll i = ll(0); i < ll(S); i++) ans += a[i] * b[i];
  return ans;
}
template <class Num>
struct Matrix {
  using V = Vector<Num>;
  vector<V> m;
  Matrix(ll s = 0, Num z = Num(0)) {
    m.resize(s, V(s));
    for (ll i = ll(0); i < ll(size()); i++) m[i][i] = z;
  }
  ll size() const { return m.size(); }
  Matrix operator*(const Matrix& rhs) const {
    assert(size() == rhs.size());
    Matrix res(size());
    for (ll i = ll(0); i < ll(size()); i++)
      for (ll j = ll(0); j < ll(size()); j++)
        for (ll k = ll(0); k < ll(size()); k++)
          res[i][j] += m[i][k] * rhs[k][j];
    return res;
  }
  V operator*(const V& rhs) const {
    assert(size() == rhs.size());
    V res(size());
    for (ll i = ll(0); i < ll(size()); i++) res[i] = Dot(m[i], rhs);
    return res;
  }
  V& operator[](ll i) { return m[i]; }
  V const& operator[](ll i) const { return m[i]; }
};
template <class Num>
ostream& operator<<(ostream& os, const Matrix<Num>& x) {
  const ll S = x.size();
  os << "----------" << endl;
  for (ll i = ll(0); i < ll(S); i++) {
    for (ll j = ll(0); j < ll(S); j++) {
      os << x[i][j];
      if (j == S - 1) {
        os << endl;
      } else {
        os << " ";
      }
    }
  }
  return os << "----------";
}
template <class Num>
Num Det(Matrix<Num> a) {
  const ll S = a.size();
  Num ans(1);
  for (ll i = ll(0); i < ll(S); i++) {
    for (ll j = ll(i + 1); j < ll(S); j++)
      if (a[j][i]) {
        ans = -ans;
        swap(a[j], a[i]);
        break;
      }
    if (!a[i][i]) return 0;
    ans *= a[i][i];
    for (ll j = ll(i + 1); j < ll(S); j++) a[j] -= a[i] * (a[j][i] / a[i][i]);
  }
  return ans;
}
using M = Matrix<ld>;
using V = Vector<ld>;
signed main() {
  ll n = read(), t = read();
  ld maxBP = 0;
  vector<pair<ld, ld>> rq;
  for (ll i = ll(0); i < ll(n); i++) {
    ll a = read(), b = read();
    ld p = readDouble();
    chmax(maxBP, b * p);
    rq.emplace_back(1 - p, a * p);
  }
  MakeUniqued(rq);
  const ld eps = 1e-15;
  vector<pair<ld, ld>> conv;
  ld last = 0;
  for (ll i = ll(0); i < ll(n); i++) {
    ld r = rq[i].first, q = rq[i].second;
    if (last + eps >= q) continue;
    last = q;
    while (conv.size() >= 2) {
      ll s = conv.size() - 2;
      ld a = conv[s - 1].first - conv[s - 2].first;
      ld b = conv[s - 1].second - conv[s - 2].second;
      ld c = r - conv[s - 1].first;
      ld d = q - conv[s - 1].second;
      if (b * c >= d * a + eps) break;
      conv.pop_back();
    }
    conv.push_back(rq[i]);
  }
  const ll L = 40;
  ld base = maxBP * t, g = 0;
  while (t) {
    ld r = conv.back().first, q = conv.back().second;
    M org(2);
    org[0][0] = r;
    org[0][1] = maxBP - q;
    org[1][1] = 1;
    vector<M> ms{org};
    for (ll _ = ll(0); _ < ll(L - 1); _++) {
      M m = ms.back();
      ms.push_back(m * m);
    }
    V cur(2);
    cur[0] = g;
    cur[1] = 1;
    if (conv.size() == 1) {
      for (ll i = ll(0); i < ll(L); i++)
        if ((t >> i) & 1) cur = ms[i] * cur;
      g = cur[0];
      t = 0;
      break;
    } else {
      ll s = conv.size();
      auto UseHead = [&](const ld x) {
        ld nxg[2];
        for (ll k = ll(0); k < ll(2); k++) {
          nxg[k] = maxBP - conv[s - 1 - k].second + conv[s - 1 - k].first * x;
        }
        return nxg[0] + eps <= nxg[1];
      };
      if (!UseHead(g)) {
        conv.pop_back();
        continue;
      }
      for (ll i = L - 1; i >= 0; i--) {
        ll len = ll(1) << i;
        if (len < t) {
          V nx = ms[i] * cur;
          if (UseHead(nx[0])) {
            cur = nx;
            t -= len;
          }
        }
      }
      cur = ms[0] * cur;
      g = cur[0];
      t--;
      conv.pop_back();
    }
  }
  cout << fixed << setprecision(20) << base - g << endl;
}
