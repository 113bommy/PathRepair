#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
const long long MOD = 1000000007;
const long long INF = 2000000000;
const long long DESPACITO = 1000000000000000000;
namespace minmax {
template <class T>
T max(T&& A) {
  return A;
}
template <class T>
T min(T&& A) {
  return A;
}
template <class T>
T max(T&& A, T&& B) {
  return A > B ? A : B;
}
template <class T>
T chmin2(T&& A, T&& B) {
  return A < B ? A : B;
}
template <class T, class... Ts>
T max(T&& A, Ts&&... ts) {
  T B = max(ts...);
  return A > B ? A : B;
}
template <class T, class... Ts>
T min(T&& A, Ts&&... ts) {
  T B = min(ts...);
  return A < B ? A : B;
}
template <class T, class... Ts>
T chmax(T&& A, Ts&&... ts) {
  A = max(A, ts...);
  return A;
}
template <class T, class... Ts>
T chmin(T&& A, Ts&&... ts) {
  A = min(A, ts...);
  return A;
}
template <class T1, class T2>
void chmin2(T1&& A, T2&& Aa, T1&& B, T2&& Bb) {
  if (B < A) A = B, Aa = Bb;
}
template <class T1, class T2>
void chmax2(T1&& A, T2&& Aa, T1&& B, T2&& Bb) {
  if (B > A) A = B, Aa = Bb;
}
}  // namespace minmax
namespace input {
template <class T>
void re(T&& Xx) {
  cin >> Xx;
}
template <class T1, class T2>
void re(pair<T1, T2>& Pp) {
  re(Pp.first);
  re(Pp.second);
}
template <class T>
void re(vector<T>& Aa) {
  for (long long i = 0; i < (long long)(Aa).size(); i++) re(Aa[i]);
}
template <class T1, class T2>
void rea(T1&& Aa, T2 t) {
  for (long long i = 0; i < t; i++) re(Aa[i]);
}
template <class T1, class T2, class... Ts>
void rea(T1&& Aa, T2 t, Ts&&... ts) {
  rea(Aa, t);
  rea(ts...);
}
template <class T1, class T2>
void rea1(T1&& Aa, T2 t) {
  for (long long i = 1; i <= t; i++) re(Aa[i]);
}
template <class T1, class T2, class... Ts>
void rea1(T1&& Aa, T2 t, Ts&... ts) {
  rea1(Aa, t);
  rea1(ts...);
}
template <class T, class... Ts>
void re(T&& t, Ts&... ts) {
  re(t);
  re(ts...);
}
}  // namespace input
namespace output {
void pr(int32_t Xx) { cout << Xx; }
void pr(bool Xx) { cout << Xx; }
void pr(long long Xx) { cout << Xx; }
void pr(long long unsigned Xx) { cout << Xx; }
void pr(double Xx) { cout << Xx; }
void pr(char Xx) { cout << Xx; }
void pr(const string& Xx) { cout << Xx; }
void pr(const char* Xx) { cout << Xx; }
void pr(const char* Xx, size_t len) { cout << string(Xx, len); }
void ps() { cout << "\n"; }
void pn() {}
void pw() { pr(" "); }
void pc() {
  pr("]");
  ps();
}
template <class T1, class T2>
void pr(const pair<T1, T2>& Xx) {
  pr(Xx.first);
  pw();
  pr(Xx.second);
}
template <class T>
void pr(const T&);
bool parse(const char* t) {
  if (t == "\n") return true;
  return false;
}
template <class T>
bool parse(T&& t) {
  return false;
}
template <class T1, class T2>
bool parsepair(const pair<T1, T2>& Xx) {
  return true;
}
template <class T>
bool parsepair(T&& t) {
  return false;
}
template <class T1, class T2>
void psa(T1&& Aa, T2 t) {
  for (long long i = 0; i < t; i++) pr(Aa[i]), pw();
  ps();
}
template <class T1, class T2>
void pna(T1&& Aa, T2 t) {
  for (long long i = 0; i < t; i++) pr(Aa[i]), ps();
}
template <class T1, class T2>
void psa2(T1&& Aa, T2 t1, T2 t2) {
  for (long long i = 0; i < t1; i++) {
    for (long long j = 0; j < t2; j++) pr(Aa[i][j]), pw();
    ps();
  }
}
template <class T>
void pr(const T& Xx) {
  if (!(long long)(Xx).size()) return;
  bool fst = 1;
  bool op = 0;
  if (parsepair(*Xx.begin())) op = 1;
  for (const auto& Aa : Xx) {
    if (!fst) pw();
    if (op) pr("{");
    pr(Aa), fst = 0;
    if (op) pr("}");
  }
}
template <class T, class... Ts>
void pr(const T& t, const Ts&... ts) {
  pr(t);
  pr(ts...);
}
template <class T, class... Ts>
void ps(const T& t, const Ts&... ts) {
  pr(t);
  if (sizeof...(ts)) {
    if (!parse(t)) pw();
  }
  ps(ts...);
}
template <class T>
void pn(const T& t) {
  for (const auto& Aa : t) ps(Aa);
}
template <class T, class... Ts>
void pw(const T& t, const Ts&... ts) {
  pr(t);
  if (sizeof...(ts)) pw();
  pw(ts...);
}
template <class T, class... Ts>
void pc(const T& t, const Ts&... ts) {
  bool op = 0;
  if (parsepair(t)) op = 1;
  if (op) pr("{");
  pr(t);
  if (op) pr("}");
  if (sizeof...(ts)) pr(", ");
  pc(ts...);
}
namespace trace {
template <class T1, class T2>
void __f(const char* name, const T1& Xx, const T2& y) {
  pr("[", y, "] = ");
  ps(Xx);
}
template <class T1, class T2, class... Ts>
void __f(const char* name, const T1& Xx, const T2& y, const Ts&... rest) {
  const char* open = strchr(name, '[');
  pr("[", y, "]");
  __f(open + 1, Xx, rest...);
}
template <class T1, class T2, class... Ts>
void __f0(const char* name, const T1& Xx, const T2& y, const Ts&... rest) {
  const char* open = strchr(name, '[');
  pr(name, size_t(open - name));
  __f(name, Xx, y, rest...);
}
template <class T>
void __fn(long long n, const char* name, const T& Xx) {
  for (long long i = 0; i < n; i++) pr(name), __f(name, Xx[i], i);
}
}  // namespace trace
}  // namespace output
using namespace minmax;
using namespace input;
using namespace output;
using namespace output::trace;
const long long N = 2e5 + 5;
long long solve() {
  long long i, n, k;
  re(n, k);
  vector<long long> ans1(k - 1, 1), ans2(k - 1, 2);
  if (n - k + 1 > 0 and (n - k + 1) & 1) {
    ans1.emplace_back(n - k + 1);
    return ps("YES", "\n", ans1), 0;
  }
  if (n - 2 * k + 2 > 0 and (n - 2 * k + 2) % 2 == 0) {
    ans2.emplace_back(n - 2 * k + 2);
    return ps("YES", "\n", ans2), 0;
  }
  ps("NO");
  return 0;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long Q;
  for (cin >> Q; Q; Q--) solve();
  return 0;
}
