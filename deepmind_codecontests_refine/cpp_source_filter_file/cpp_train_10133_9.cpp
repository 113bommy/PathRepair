#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
template <class T>
using vec = vector<T>;
using vb = vec<bool>;
using vi = vec<int>;
using vl = vec<ll>;
using vd = vec<ld>;
using vs = vec<str>;
using vpi = vec<pi>;
using vpl = vec<pl>;
using vpd = vec<pd>;
template <class Key, class T, class Hash = hash<Key>,
          class Pred = equal_to<Key>,
          class Alloc = allocator<pair<const Key, T>>>
using umap = unordered_map<Key, T, Hash, Pred, Alloc>;
template <class Key, class Hash = hash<Key>, class Pred = equal_to<Key>,
          class Alloc = allocator<Key>>
using uset = unordered_set<Key, Hash, Pred, Alloc>;
int MOD = 1e9 + 7, MX = 5e5 + 5;
ll INF = 1e18;
ld PI = acos((ld)-1), EPS = 1e-8;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
namespace input {
template <class T>
inline void re(complex<T>& first);
template <class T1, class T2>
inline void re(pair<T1, T2>& p);
template <class T>
inline void re(vector<T>& a);
template <class T, size_t SZ>
inline void re(array<T, SZ>& a);
template <class T>
inline void re(T& first) {
  cin >> first;
}
inline void re(double& first) {
  string t;
  re(t);
  first = stod(t);
}
inline void re(ld& first) {
  string t;
  re(t);
  first = stold(t);
}
template <class T, class... Ts>
inline void re(T& t, Ts&... ts) {
  re(t);
  re(ts...);
}
template <class T>
inline void re(complex<T>& first) {
  T a, b;
  re(a, b);
  first = {a, b};
}
template <class T1, class T2>
inline void re(pair<T1, T2>& p) {
  re(p.f, p.s);
}
template <class T>
inline void re(vector<T>& a) {
  for (int i = (0); i != ((int)(a.size())); i += (0 < (int)(a.size()) ? 1 : -1))
    re(a[i]);
}
template <class T, size_t SZ>
inline void re(array<T, SZ>& a) {
  for (int i = (0); i != (SZ); i += (0 < SZ ? 1 : -1)) re(a[i]);
}
inline void setin(string s) { freopen(s.c_str(), "r", stdin); }
}  // namespace input
namespace output {
inline void pr(int first) { cout << first; }
inline void pr(long first) { cout << first; }
inline void pr(ll first) { cout << first; }
inline void pr(unsigned first) { cout << first; }
inline void pr(unsigned long first) { cout << first; }
inline void pr(unsigned long long first) { cout << first; }
inline void pr(float first) { cout << first; }
inline void pr(double first) { cout << first; }
inline void pr(ld first) { cout << first; }
inline void pr(char first) { cout << first; }
inline void pr(const char* first) { cout << first; }
inline void pr(const string& first) { cout << first; }
inline void pr(bool first) { pr(first ? "true" : "false"); }
template <class T>
inline void pr(const complex<T>& first) {
  cout << first;
}
template <class T1, class T2>
inline void pr(const pair<T1, T2>& first);
template <class T>
inline void pr(const T& first);
template <class T, class... Ts>
inline void pr(const T& t, const Ts&... ts) {
  pr(t);
  pr(ts...);
}
template <class T1, class T2>
inline void pr(const pair<T1, T2>& first) {
  pr("{", first.first, ", ", first.second, "}");
}
template <class T>
inline void pr(const T& first) {
  pr("{");
  bool fst = 1;
  for (const auto& a : first) pr(!fst ? ", " : "", a), fst = 0;
  pr("}");
}
inline void ps() { pr("\n"); }
template <class T, class... Ts>
inline void ps(const T& t, const Ts&... ts) {
  pr(t);
  if (sizeof...(ts)) pr(" ");
  ps(ts...);
}
inline void pc() { pr("]\n"); }
template <class T, class... Ts>
inline void pc(const T& t, const Ts&... ts) {
  pr(t);
  if (sizeof...(ts)) pr(", ");
  pc(ts...);
}
inline void setout(string s) { freopen(s.c_str(), "w", stdout); }
}  // namespace output
using namespace input;
using namespace output;
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
int N, A, D, T, V;
void solve() {
  re(N, A, D);
  ld lf = 0;
  for (int i = (0); i != (N); i += (0 < N ? 1 : -1)) {
    re(T, V);
    ld at = (ld)V / A;
    ld d = .5 * A * at * at;
    0;
    ld t;
    if (d <= D)
      t = (D - d) / V + at;
    else
      t = sqrt(2.0 * D / A);
    ps(max(lf, T + t));
    lf = T + t;
  }
}
