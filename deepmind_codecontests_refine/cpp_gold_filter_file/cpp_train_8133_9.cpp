#include <bits/stdc++.h>
using namespace std;
namespace io {
template <typename Test, template <typename...> class Ref>
struct is_specialization : std::false_type {};
template <template <typename...> class Ref, typename... Args>
struct is_specialization<Ref<Args...>, Ref> : std::true_type {};
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)(s).size()) {
    setIn(s + ".in"), setOut(s + ".out");
  }
}
void re(double& x) {
  string t;
  cin >> t;
  x = stod(t);
}
void re(long double& x) {
  string t;
  cin >> t;
  x = stold(t);
}
template <class T>
void re(T& x) {
  cin >> x;
}
template <class Arg, class... Args>
void re(Arg& first, Args&... rest) {
  re(first);
  re(rest...);
}
template <class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& a) {
  for (auto i = (0) - ((0) > ((int)(a).size()));
       i != ((int)(a).size()) - ((0) > ((int)(a).size()));
       i += 1 - 2 * ((0) > ((int)(a).size())))
    is >> a[i];
  return is;
}
template <class T>
void pr(const T& x) {
  cout << x << '\n';
}
template <class Arg, class... Args>
void pr(const Arg& first, const Args&... rest) {
  cout << first << ' ';
  pr(rest...);
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& a) {
  os << '{' << a.first << ", " << a.second << '}';
  return os;
}
template <class K, class V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
  os << '{';
  for (auto it = (m.begin()); (it) != (m.end()); (it)++) {
    os << ", "[it == m.begin()] << *it;
  }
  os << " }";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << '{';
  for (auto it = (s.begin()); (it) != (s.end()); (it)++) {
    os << ", "[it == s.begin()] << *it;
  }
  os << " }";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& a) {
  os << '[';
  for (auto i = (0) - ((0) > ((int)(a).size()));
       i != ((int)(a).size()) - ((0) > ((int)(a).size()));
       i += 1 - 2 * ((0) > ((int)(a).size()))) {
    if (i) {
      os << ", ";
      if (is_specialization<T, vector>::value) os << '\n';
    }
    os << a[i];
  }
  os << ']';
  return os;
}
}  // namespace io
using namespace io;
inline void prep() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
void solve();
int main() {
  prep();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
const int MOD = 1000000007;
const int MX = 101;
const double INF = 1e10;
void solve() {
  int n, k;
  re(n, k);
  if (k == 1 || k == n)
    pr(n * 3);
  else
    pr(n * 3 + min(n - k, k - 1));
}
