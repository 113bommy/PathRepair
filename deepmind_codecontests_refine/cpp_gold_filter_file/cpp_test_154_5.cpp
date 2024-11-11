#include <bits/stdc++.h>
const long double eps = 1e-9;
const long long mod = 1e9 + 7, ll_max = 1e18;
const int MX = 2e5 + 10, int_max = 0x3f3f3f3f;
using namespace std;
template <class T>
void read(T &x) {
  cin >> x;
}
template <class H, class T>
void read(pair<H, T> &p) {
  cin >> p.first >> p.second;
}
template <class T, size_t S>
void read(array<T, S> &a) {
  for (T &i : a) read(i);
}
template <class T>
void read(vector<T> &v) {
  for (T &i : v) read(i);
}
template <class H, class... T>
void read(H &h, T &...t) {
  read(h);
  read(t...);
}
template <class H, class T>
ostream &operator<<(ostream &o, pair<H, T> &p) {
  o << p.first << " " << p.second;
  return o;
}
template <class T, size_t S>
ostream &operator<<(ostream &o, array<T, S> &a) {
  string s;
  for (T i : a) o << s << i, s = " ";
  return o;
}
template <class T>
ostream &operator<<(ostream &o, vector<T> &v) {
  string s;
  for (T i : v) o << s << i, s = " ";
  return o;
}
template <class T>
void write(T x) {
  cout << x;
}
template <class H, class... T>
void write(const H &h, const T &...t) {
  write(h);
  write(t...);
}
void print() { write('\n'); }
template <class H, class... T>
void print(const H &h, const T &...t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
template <typename T>
void ckmin(T &a, const T &b) {
  a = min(a, b);
}
template <typename T>
void ckmax(T &a, const T &b) {
  a = max(a, b);
}
int solve(int a, int b, int c) {
  if (a % 2 && b % 2 && c % 2) return 0;
  if (a + b == c || b + c == a || c + a == b) return 1;
  if ((a == b && c % 2 == 0) || (b == c && a % 2 == 0) ||
      (c == a && b % 2 == 0))
    return 1;
  return 0;
}
void solve() {
  int a, b, c;
  read(a, b, c);
  print(solve(a, b, c) ? "YES" : "NO");
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
