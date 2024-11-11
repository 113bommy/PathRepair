#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
using namespace std;
template <class T, class U>
inline void checkmin(T &x, U y) {
  if (y < x) x = y;
}
template <class T, class U>
inline void checkmax(T &x, U y) {
  if (y > x) x = y;
}
template <class T, class U>
inline bool ifmax(T &x, U y) {
  if (y > x) return x = y, true;
  return false;
}
template <class T, class U>
inline bool ifmin(T &x, U y) {
  if (y < x) return x = y, true;
  return false;
}
template <class T>
inline void sort(T &a) {
  sort(a.begin(), a.end());
}
template <class T>
inline void rsort(T &a) {
  sort(a.rbegin(), a.rend());
}
template <class T>
inline void reverse(T &a) {
  reverse(a.begin(), a.end());
}
template <class T, class U>
inline istream &operator>>(istream &str, pair<T, U> &p) {
  return str >> p.first >> p.second;
}
template <class T>
inline istream &operator>>(istream &str, vector<T> &a) {
  for (auto &i : a) str >> i;
  return str;
}
void solve(long double &x, long double a, long double b, long double c) {
  long double D = b * b - 4 * a * c;
  checkmax(D, 0);
  D = sqrt(D);
  long double x1 = (-b - D) / (2 * a);
  long double x2 = (-b + D) / (2 * a);
  x = x1 < 0 ? x2 : x1;
  checkmax(x, 0);
  checkmin(x, 1);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(4);
  srand(94385);
  int n;
  cin >> n;
  vector<long double> mx(n), mn(n);
  cin >> mx >> mn;
  vector<long double> sum(n);
  for (int i = 0; i < n; ++i) sum[i] = mn[i] + mx[i];
  auto pref = mx;
  for (int i = 1; i < n; ++i) pref[i] += pref[i - 1];
  long double A = 0, B = 0;
  vector<long double> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    solve(b[i], -1, sum[i] + A - B, B * (sum[i] + A) - pref[i]);
    a[i] = sum[i] - b[i];
    A += a[i];
    B += b[i];
  }
  for (auto i : a) cout << i << ' ';
  cout << '\n';
  for (auto i : b) cout << i << ' ';
  return 0;
}
