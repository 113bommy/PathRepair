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
  cout.precision(15);
  if (int((second).size())) {
    setIn(second + ".in"), setOut(second + ".out");
  }
}
}  // namespace __io
using namespace __io;
pll operator+(pll a, pll b) { return {a.first + b.first, a.second + b.second}; }
template <typename T, typename U, bool PROP = true>
struct segment_tree_lazy {
  size_t SZ;
  T tid;
  vector<T> table;
  vb has;
  vector<U> ops;
  segment_tree_lazy() {}
  segment_tree_lazy(int _SZ, T _tid) : SZ(_SZ), tid(_tid) {
    table.resize(2 * SZ, tid), has.resize(SZ), ops.resize(SZ);
  }
  template <typename L>
  void set_leaves(L create) {
    for (int i = 0; i < (SZ); i++) table[SZ + i] = create(i);
    for (int i = (SZ)-1; i >= (1); i--)
      table[i] = table[2 * i] + table[2 * i + 1];
  }
  void apply(int i, const U& op) { table[i] = op + table[i]; }
  void operator()(int i, int j, U op) {
    i += SZ, j += SZ;
    for (int l = i, r = j; l < r; l /= 2, r /= 2) {
      if (l & 1) apply(l++, op);
      if (r & 1) apply(--r, op);
    }
  }
  T operator[](int i) {
    pll res = tid;
    for (i += SZ; i; i /= 2) res = res + table[i];
    return res;
  }
};
int main() {
  setIO();
  int N, Q;
  re(N, Q);
  vi p(N);
  re(p);
  vi l(Q), r(Q);
  re(l, r);
  for (int q = 0; q < (Q); q++) {
    l[q]--;
    r[q]--;
    if (l[q] > r[q]) swap(l[q], r[q]);
  }
  vll ans(Q);
  for (int q = 0; q < (Q); q++) ans[q] = r[q] - l[q] + 1;
  for (int _ = 0; _ < (2); _++) {
    segment_tree_lazy<pll, pll, true> seg(N, {0, 0});
    vvi at_r(N);
    for (int q = 0; q < (Q); q++) at_r[r[q]].push_back(q);
    stack<pii> st;
    st.push({-1, INT_MAX});
    for (int i = 0; i < (N); i++) {
      while (st.top().second < p[i]) st.pop();
      seg(0, st.top().first + 1, {0, i - 1 - st.top().first});
      seg(st.top().first + 1, i, {-1, i});
      st.push({i, p[i]});
      for (auto& q : at_r[i]) {
        pll first = seg[l[q]];
        ans[q] += first.first * l[q] + first.second;
      }
    }
    reverse((p).begin(), (p).end());
    for (int q = 0; q < (Q); q++) {
      tie(l[q], r[q]) = make_pair(N - 1 - r[q], N - 1 - l[q]);
    }
  }
  pc(ans);
  return 0;
}
