#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
void adskiy_razgon() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0},
          dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
void sp(long long a, double b) { cout << fixed << setprecision(a) << b; }
template <class A>
void read(vector<A>& v);
template <class A, size_t S>
void read(array<A, S>& a);
template <class T>
void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class A, size_t S>
void read(array<A, S>& x) {
  for (auto& a : x) read(a);
}
string to_string(char c) { return string(1, c); }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
  string res;
  for (int i = (0); (1) > 0 ? i < ((int)(v).size()) : i > ((int)(v).size());
       i += (1))
    res += char('0' + v[i]);
  return res;
}
template <size_t S>
string to_string(bitset<S> b) {
  string res;
  for (int i = (0); (1) > 0 ? i < (S) : i > (S); i += (1))
    res += char('0' + b[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool f = 1;
  string res;
  for (auto& x : v) {
    if (!f) res += ' ';
    f = 0;
    res += to_string(x);
  }
  return res;
}
template <class A>
void write(A x) {
  cout << to_string(x);
}
inline int bitCount(int number) { return __builtin_popcount(number); }
inline int bitCount(long long number) { return __builtin_popcount(number); }
template <class H, class... T>
void write(const H& h, const T&... t) {
  write(h);
  write(t...);
}
void print() { write("\n"); }
template <class H, class... T>
void print(const H& h, const T&... t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
template <class T>
bool umin(T& a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T& a, T b) {
  return a < b ? (a = b, true) : false;
}
void yes(bool ok) { print((ok ? "YES" : "Yes")); }
void no(bool ok) { print((ok ? "NO" : "No")); }
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
const long long INF = 1e21;
const long double PI = acos((long double)-1);
const int M = 1005;
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return ((binpow(a, n - 1)) * a);
  else {
    long long b = (binpow(a, n / 2));
    return (b * b);
  }
}
void solve() {
  int x;
  string n;
  int m;
  read(x, m, n);
  if (x == 1) {
    if (m == 0)
      print(n);
    else
      print(0);
    return;
  }
  if (n[0] != '1') {
    if (m) n[0] = '1', m--;
  }
  int cnt = 1;
  while (m > 0 && cnt < (int)(n).size()) {
    if (n[cnt] != '0') n[cnt] = '0', m--;
    cnt++;
  }
  print(n);
}
int main() {
  adskiy_razgon();
  long long t = 1;
  for (int i = (0); (1) > 0 ? i < (t) : i > (t); i += (1)) {
    solve();
  }
  return 0;
}
