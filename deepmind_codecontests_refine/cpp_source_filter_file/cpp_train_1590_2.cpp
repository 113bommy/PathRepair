#include <bits/stdc++.h>
using namespace std;
template <class A>
void read(vector<A> &v);
template <class A, size_t S>
void read(array<A, S> &a);
template <class T>
void read(T &x) {
  cin >> x;
}
void read(double &d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double &d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T>
void read(H &h, T &...t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A> &x) {
  for (auto &a : x) read(a);
}
template <class A, size_t S>
void read(array<A, S> &x) {
  for (auto &a : x) read(a);
}
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "yes" : "no"; }
string to_string(const char *s) { return string(s); }
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
  for (auto &x : v) {
    if (!f) res += ' ';
    f = 0;
    res += to_string(x);
  }
  return res;
}
template <class A>
void write(A x) {
  cout << to_string(x) << " ";
}
template <class H, class... T>
void write(const H &h, const T &...t) {
  write(h);
  write(t...);
}
void print() { cout << ("\n"); }
template <class H, class... T>
void print(const H &h, const T &...t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
void deb() { cerr << endl; }
template <typename Head, typename... Tail>
void deb(Head H, Tail... T) {
  cerr << to_string(H) << " ";
  deb(T...);
}
using ll = long long;
pair<const int, const int> dxdy[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n, 0);
  read(a);
  sort((a).begin(), (a).end());
  ll ans = INT64_MAX;
  double x = 1 / ((double)n - 1);
  ll val = pow((1e9), x) + 10;
  for (int i = 1; i <= val; i++) {
    ll sum = 0;
    int fl = 1;
    for (int j = 1; j < n; j++) {
      if (pow(i, j) > INT32_MAX) {
        fl = 0;
        break;
      }
      if (fl) sum += abs(a[j] - pow(i, j));
    }
    ans = min(sum, ans);
  }
  write(ans + abs(a[0] - 1));
  print();
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  for (int i = (0); (1) > 0 ? i < (tc) : i > (tc); i += (1)) {
    solve();
  }
}
