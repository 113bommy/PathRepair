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
using vpll = vector<pll>;
using vpdd = vector<pdd>;
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
typename vector<T>::const_iterator find(const vector<T>& v, const T& x) {
  auto it = lower_bound((v).begin(), (v).end(), x);
  return it != v.end() && *it == x ? it : v.end();
}
template <typename T>
size_t index(const vector<T>& v, const T& x) {
  auto it = find(v, x);
  assert(it != v.end() && *it == x);
  return it - v.begin();
}
template <typename T1, typename T2>
typename vector<pair<T1, T2>>::iterator lower_bound(
    const vector<pair<T1, T2>>& v, const T1& x) {
  return lower_bound(
      (v).begin(), (v).end(), x,
      [](pair<T1, T2> a, pair<T1, T2> b) { return a.first < b.first; });
}
template <typename T1, typename T2>
typename vector<pair<T1, T2>>::iterator upper_bound(
    const vector<pair<T1, T2>>& v, const T1& x) {
  return upper_bound(
      (v).begin(), (v).end(), x,
      [](pair<T1, T2> a, pair<T1, T2> b) { return a.first < b.first; });
}
}  // namespace __algorithm
using namespace __algorithm;
struct __monostate {
  friend istream& operator>>(istream& is,
                             const __attribute__((unused)) __monostate& ms) {
    return is;
  }
  friend ostream& operator<<(ostream& os,
                             const __attribute__((unused)) __monostate& ms) {
    return os;
  }
} ms;
namespace __io {
FILE* setIn(string second) { return freopen(second.c_str(), "r", stdin); }
FILE* setOut(string second) { return freopen(second.c_str(), "w", stdout); }
void setIO(string second = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(15);
  if (int((second).size())) {
    setIn(second + ".in"), setOut(second + ".out");
  }
}
}  // namespace __io
using namespace __io;
int query(int u, int v, int w) {
  assert(u != v && u != w && v != w);
  if (u > v) swap(u, v);
  ps("?", u + 1, v + 1, w + 1);
  cout << flush;
  int lca;
  re(lca);
  return lca - 1;
}
int main() {
  setIO();
  int H;
  re(H);
  int N = (1 << H) - 1;
  int u = -1, v = -1;
  set<pii> tried = {{-1, -1}};
  const int ATTEMPTS = 6;
  for (int _ = 0; _ < (ATTEMPTS); _++) {
    u = v = -1;
    while (tried.count(make_pair(u, v))) {
      u = v = rng() % N;
      while (u == v) v = rng() % N;
      if (u > v) swap(u, v);
    }
    tried.insert(make_pair(u, v));
    map<int, int> lcas;
    int Q;
    if (N - 2 <= 420 / ATTEMPTS) {
      Q = N - 2;
      for (int w = 0; w < (N); w++)
        if (w != u && w != v) {
          lcas[query(u, v, w)]++;
        }
    } else {
      Q = 420 / ATTEMPTS;
      for (int REP = 0; REP < (Q); REP++) {
        int w = rng() % N;
        while (w == u || w == v) w = rng() % N;
        lcas[query(u, v, w)]++;
      }
    }
    bool ok = true;
    for (auto& e : lcas) {
      if (double(e.second) / Q > .41) ok = false;
    }
    if (ok)
      break;
    else
      v = -1;
  }
  if (v == -1) {
    while (true)
      ;
  }
  vi ct(N);
  for (int w = 0; w < (N); w++)
    if (w != u && w != v) ct[query(u, v, w)]++;
  for (int i = 0; i < (N); i++) {
    if (i != u && i != v && ct[i] == 1) {
      ps("!", i + 1);
      cout << flush;
      return 0;
    }
  }
  ps("!", ct[u] > ct[v] ? u + 1 : v + 1);
  cout << flush;
  return 0;
}
