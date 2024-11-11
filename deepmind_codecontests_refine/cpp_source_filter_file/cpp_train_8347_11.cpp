#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;
template <typename T>
void ckmin(T& a, const T& b) {
  a = min(a, b);
}
template <typename T>
void ckmax(T& a, const T& b) {
  a = max(a, b);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace __input {
template <class T1, class T2>
void re(pair<T1, T2>& p);
template <class T>
void re(vector<T>& a);
template <class T, size_t SZ>
void re(array<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(double& x) {
  string t;
  re(t);
  x = stod(t);
}
template <class Arg, class... Args>
void re(Arg& first, Args&... rest) {
  re(first);
  re(rest...);
}
template <class T1, class T2>
void re(pair<T1, T2>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& a) {
  for (int i = 0; i < (int((a).size())); i++) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a) {
  for (int i = 0; i < (SZ); i++) re(a[i]);
}
}  // namespace __input
using namespace __input;
namespace __output {
template <class T1, class T2>
void pr(const pair<T1, T2>& x);
template <class T, size_t SZ>
void pr(const array<T, SZ>& x);
template <class T>
void pr(const vector<T>& x);
template <class T>
void pr(const deque<T>& x);
template <class T>
void pr(const set<T>& x);
template <class T1, class T2>
void pr(const map<T1, T2>& x);
template <class T>
void pr(const T& x) {
  cout << x;
}
template <class Arg, class... Args>
void pr(const Arg& first, const Args&... rest) {
  pr(first);
  pr(rest...);
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x) {
  pr("{", x.first, ", ", x.second, "}");
}
template <class T, bool pretty = true>
void prContain(const T& x) {
  if (pretty) pr("{");
  bool fst = 1;
  for (const auto& a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0;
  if (pretty) pr("}");
}
template <class T>
void pc(const T& x) {
  prContain<T, false>(x);
  pr("\n");
}
template <class T, size_t SZ>
void pr(const array<T, SZ>& x) {
  prContain(x);
}
template <class T>
void pr(const vector<T>& x) {
  prContain(x);
}
template <class T>
void pr(const deque<T>& x) {
  prContain(x);
}
template <class T>
void pr(const set<T>& x) {
  prContain(x);
}
template <class T1, class T2>
void pr(const map<T1, T2>& x) {
  prContain(x);
}
void ps() { pr("\n"); }
template <class Arg>
void ps(const Arg& first) {
  pr(first);
  ps();
}
template <class Arg, class... Args>
void ps(const Arg& first, const Args&... rest) {
  pr(first, " ");
  ps(rest...);
}
}  // namespace __output
using namespace __output;
namespace __algorithm {
template <typename T>
void dedup(vector<T>& v) {
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
}
template <typename T>
typename vector<T>::iterator find(vector<T>& v, const T& x) {
  auto it = lower_bound((v).begin(), (v).end(), x);
  return it != v.end() && *it == x ? it : v.end();
}
template <typename T>
size_t index(vector<T>& v, const T& x) {
  auto it = find(v, x);
  assert(it != v.end() && *it == x);
  return it - v.begin();
}
template <typename C, typename T, typename OP>
vector<T> prefixes(const C& v, T id, OP op) {
  vector<T> r(int((v).size()) + 1, id);
  for (int i = 0; i < (int((v).size())); i++) r[i + 1] = op(r[i], v[i]);
  return r;
}
template <typename C, typename T, typename OP>
vector<T> suffixes(const C& v, T id, OP op) {
  vector<T> r(int((v).size()) + 1, id);
  for (int i = (int((v).size())) - 1; i >= 0; i--) r[i] = op(v[i], r[i + 1]);
  return r;
}
}  // namespace __algorithm
using namespace __algorithm;
struct monostate {
  friend istream& operator>>(istream& is,
                             const __attribute__((unused)) monostate& ms) {
    return is;
  }
  friend ostream& operator<<(ostream& os,
                             const __attribute__((unused)) monostate& ms) {
    return os;
  }
} ms;
template <typename W = monostate>
struct wedge {
  int u, v, i;
  W w;
  wedge<W>(int _u = -1, int _v = -1, int _i = -1) : u(_u), v(_v), i(_i) {}
  int operator[](int loc) const { return u ^ v ^ loc; }
  friend void re(wedge& e) {
    re(e.u, e.v, e.w);
    --e.u, --e.v;
  }
  friend void pr(const wedge& e) { pr(e.u, "<-", e.w, "->", e.v); }
};
namespace __io {
void setIn(string second) { freopen(second.c_str(), "r", stdin); }
void setOut(string second) { freopen(second.c_str(), "w", stdout); }
void setIO(string second = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(15);
  if (int((second).size())) {
    setIn(second + ".in"), setOut(second + ".out");
  }
}
}  // namespace __io
using namespace __io;
int main() {
  setIO();
  int N;
  re(N);
  vi a(N);
  re(a);
  const int MAXV = 5e5 + 1;
  vi ct(MAXV);
  for (auto& e : a) ct[e]++;
  vi pf = prefixes(ct, 0, plus<int>());
  int last = -1, llast = -1;
  vi pv(MAXV), ppv(MAXV);
  for (int i = 0; i < (MAXV); i++) {
    if (ct[i] >= 2)
      last = llast = i;
    else if (ct[i] >= 1)
      swap(last, llast), last = i;
    pv[i] = last;
    ppv[i] = llast;
  }
  ll ans = 0;
  sort((a).begin(), (a).end());
  for (int y = 2; y <= MAXV; y++) {
    ll make = 0;
    for (int z = y; z < MAXV; z += y) {
      int h = pf[min(MAXV, z + y)] - pf[z];
      make += h * (z / y);
    }
    int xlo = 2, xhi = int(min(make, ll(a.back())));
    while (xlo <= xhi) {
      int x = (xlo + xhi) / 2;
      bool ok = false;
      if (a.back() >= 2 * x) {
        bool good = false;
        for (int z = 0; z < MAXV; z += y) {
          int zz = pv[min(MAXV, z + y - 1)];
          if (zz >= z && zz >= 2 * x && (zz % y >= (2 * x) % y)) good = true;
        }
        ll cy = make - !good - (2 * x) / y;
        if (cy >= x) ok = true;
      }
      if (int((a).size()) >= 2 && a[int((a).size()) - 2] >= x) {
        int safely = 0;
        for (int z = 0; z < MAXV; z += y) {
          int zz = pv[min(MAXV, z + y - 1)];
          if (zz >= z && zz >= x && (zz % y >= x % y)) safely++;
          zz = ppv[min(MAXV, z + y - 1)];
          if (zz >= z && zz >= x && (zz % y >= x % y)) safely++;
        }
        ll cy = make - 2 + min(safely, 2) - 2 * (x / y);
        if (cy >= x) ok = true;
      }
      if (ok) {
        ckmax(ans, ll(x) * y);
        xlo = x + 1;
      } else {
        xhi = x - 1;
      }
    }
  }
  ps(ans);
  return 0;
}
