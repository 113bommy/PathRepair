#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using vl = vector<long long>;
using vi = vector<int>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using P = pair<long long, long long>;
using vvc = vector<vc>;
using vd = vector<double>;
using vp = vector<P>;
using vb = vector<bool>;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const long long inf = 2e18;
const long long MOD = 1000000007;
const long long mod = 998244353;
const double pi = acos(-1);
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &in : v) {
    is >> in;
  }
  return is;
}
void scan() {}
template <class Head, class... Tail>
void scan(Head &head, Tail &...tail) {
  cin >> head;
  scan(tail...);
}
template <class T>
void print(const T &t) {
  cout << t << '\n';
}
template <class Head, class... Tail>
void print(const Head &head, const Tail &...tail) {
  cout << head << ' ';
  print(tail...);
}
template <class... T>
void fin(const T &...a) {
  print(a...);
  exit(0);
}
template <typename T>
T sum_(vector<T> a) {
  return accumulate(a.begin(), a.end(), T(0));
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(15);
  ;
  string s;
  scan(s);
  long long n = s.size();
  long long MIN = powl(10, n - 1);
  if (n == 1)
    MIN = 0;
  else if (n == 2)
    MIN = 25;
  long long MAX = powl(10, n) - 1;
  long long ans = 0;
  for (long long i = MIN; i <= MAX; i += 25) {
    string a = to_string(i);
    long long f = -1;
    bool ok = false;
    for (long long j = 0; j < (long long)(n); j++) {
      if (s[j] == '_') continue;
      if (s[j] == 'X') {
        if (f == -1)
          f = a[j] - '0';
        else if (f != a[j] - '0')
          ok = true;
      } else if (s[j] != a[j])
        ok = true;
    }
    if (!ok) ans++;
  }
  fin(ans);
}
