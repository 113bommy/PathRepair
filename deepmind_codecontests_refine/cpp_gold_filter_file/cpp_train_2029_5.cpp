#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
using i64 = long long;
using i32 = int;
using f64 = long double;
template <class T>
using vec = vector<T>;
using str = string;
using p64 = pair<i64, i64>;
using v64 = vec<i64>;
using vv64 = vec<v64>;
using s64 = set<i64>;
using m64 = map<i64, i64>;
template <size_t Size1>
using a64 = array<i64, Size1>;
template <size_t Size1, size_t Size2>
using aa64 = array<a64<Size2>, Size1>;
template <class T>
using hash_set = unordered_set<T>;
template <class T, class U>
using hash_map = unordered_map<T, U>;
mt19937 gen(998244353);
const i64 inf = numeric_limits<i64>::max() / 2;
template <class T>
inline i64 len(const T& a) {
  return (i64)(a.size());
}
inline void fast() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
template <class T, class S>
inline bool check_min(T& a, S b) {
  if (a > b) return a = b, 1;
  return 0;
}
template <class T, class S>
inline bool check_max(T& a, S b) {
  if (a < b) return a = b, 1;
  return 0;
}
void read() {}
template <class T, class... U>
void read(T& a, U&... b) {
  cin >> a;
  read(b...);
}
void print() {}
template <class T>
void print(const T& a) {
  cout << a;
}
template <class T, class... U>
void print(const T& a, const U&... b) {
  cout << a << " ";
  print(b...);
}
void println() { cout << "\n"; }
template <class T>
void println(const T& a) {
  cout << a << "\n";
}
template <class T, class... U>
void println(const T& a, const U&... b) {
  cout << a << " ";
  println(b...);
}
struct Problem {
  void files(string in, string out) {
    freopen(in.c_str(), "r", stdin), freopen(out.c_str(), "w", stdout);
  }
  void solve(), input();
  void many() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
      input();
      solve();
    }
  }
  void make(bool mt = 0) {
    if (mt)
      many();
    else
      input(), solve();
  }
} problem;
signed main() {
  fast();
  problem.make();
  return 0;
}
str s;
i64 n;
i64 check(str& s, str who) {
  for (int i = 0; i < (len(s) - 1); i++) {
    if (s[i] == who[0] && s[i + 1] == who[1]) {
      return 1;
    }
  }
  return 0;
}
i64 cases(str who1, str who2) {
  i64 pos = -1;
  for (int i = 0; i < (n - 1); i++) {
    if (s[i] == who1[0] && s[i + 1] == who1[1]) {
      pos = i;
      break;
    }
  }
  if (pos == -1) {
    return 0;
  }
  str s1 = s.substr(0, pos);
  str s2 = s.substr(pos + 2);
  return check(s1, who2) || check(s2, who2);
}
void Problem::solve() {
  i64 ans = cases("AB", "BA") || cases("BA", "AB");
  println(ans ? "YES" : "NO");
}
void Problem::input() {
  read(s);
  n = len(s);
}
