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
  int N, M, K, P;
  re(N, M, K, P);
  vi h(N), a(N);
  for (int i = 0; i < (N); i++) re(h[i], a[i]);
  const ll MAXV = 1e9;
  ll ans = MAXV + M * MAXV;
  ll lo = *max_element((a).begin(), (a).end()), hi = ans - 1;
  while (lo <= hi) {
    ll mi = (lo + hi) / 2;
    bool ok = true;
    vll ht(N, mi);
    vi lupd(N, M);
    priority_queue<pll> pq;
    for (int i = 0; i < (N); i++) {
      ll j = M - ht[i] / a[i];
      assert(j < M);
      if (j > 0 || ht[i] - ll(M) * a[i] < h[i]) pq.push({j, i});
    }
    for (int i = (M)-1; i >= 0; i--) {
      for (int k = 0; k < (K); k++)
        if (!pq.empty()) {
          pii bb = pq.top();
          pq.pop();
          ht[bb.second] -= ll(lupd[bb.second] - i) * a[bb.second];
          lupd[bb.second] = i;
          bb.first = i - (ht[bb.second] += P) / a[bb.second];
          if (bb.first > 0 ||
              ht[bb.second] - ll(i) * a[bb.second] < h[bb.second])
            pq.push(bb);
        }
      if (!pq.empty() && pq.top().first >= i) {
        ok = false;
        goto DONE;
      }
    }
  DONE:
    ok &= pq.empty();
    if (ok) {
      ans = mi;
      hi = mi - 1;
    } else {
      lo = mi + 1;
    }
  }
  ps(ans);
  return 0;
}
