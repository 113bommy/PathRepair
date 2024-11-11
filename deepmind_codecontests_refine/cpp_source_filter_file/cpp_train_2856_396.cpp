#include <bits/stdc++.h>
using namespace std;
void adskiy_razgon() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const long long INF = 1e18;
const long double PI = acos((long double)-1);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
long long nod(long long a, long long b) {
  if (b > a) {
    swap(a, b);
  }
  while (b > 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long nok(long long a, long long b) { return a * b / nod(a, b); }
void sp(long long a, double b) { cout << fixed << setprecision(a) << b; }
long long binpow(long long a, long long n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 1) {
    return binpow(a, n - 1) * a;
  } else {
    long long b = binpow(a, n / 2);
    return b * b;
  }
}
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
string to_string(bool b) { return b ? "true" : "false"; }
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
int a[1000000] = {0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1};
void solve() {
  int n;
  cin >> n;
  cout << a[n];
}
int main() {
  adskiy_razgon();
  long long t = 1;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
