#include <bits/stdc++.h>
using namespace std;
template <typename U, typename T1, typename T2>
U& operator>>(U& is, std::pair<T1, T2>& p) {
  return is >> p.first >> p.second;
}
template <typename U, typename T1, typename T2>
U& operator<<(U& os, const std::pair<T1, T2>& p) {
  return os << p.first << " " << p.second;
}
template <typename U, typename T,
          typename enable_if<!is_same<T, string>::value>::type* = nullptr>
U& operator>>(U& is, T& a) {
  for (auto&& e : a) {
    is >> e;
  }
  return is;
}
template <typename U, typename T,
          typename enable_if<!is_same<T, string>::value>::type* = nullptr>
U& operator<<(U& os, const T& a) {
  bool f = true;
  for (auto&& e : a) {
    if (f)
      f = false;
    else
      os << " ";
    os << e;
  }
  return os;
}
template <typename T>
void read(T& value) {
  cin >> value;
}
template <typename T, typename... Args>
void read(T& value, Args&&... args) {
  cin >> value;
  read(forward<Args>(args)...);
}
template <typename T>
void print(const T& value) {
  cout << value << '\n';
  ;
}
template <typename T, typename... Args>
void print(const T& value, Args&&... args) {
  cout << value << ' ';
  print(forward<Args>(args)...);
}
template <typename T, typename U>
void setmin(T& a, const U& b) {
  if (b < a) a = b;
}
template <typename T, typename U>
void setmax(T& a, const U& b) {
  if (b > a) a = b;
}
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
int sign(T a) {
  return a < 0 ? -1 : (a > 0 ? 1 : 0);
}
string OK(bool a) { return a ? "YES" : "NO"; }
string Ok(bool a) { return a ? "Yes" : "No"; }
constexpr long long inf = (int)1e9 + 7;
constexpr long long md = (int)1e9 + 7;
void solve() {
  int n;
  string s;
  read(n, s);
  set<char> uniq((s).begin(), (s).end());
  if (n <= 26) {
    print(n - uniq.size());
  } else {
    print(-1);
  }
}
void go() {
  int testn = 1;
  for (int testi = 1; testi <= testn; testi++) {
    solve();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  go();
}
