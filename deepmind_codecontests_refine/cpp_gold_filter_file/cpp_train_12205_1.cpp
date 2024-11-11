#include <bits/stdc++.h>
#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long mod = 1e9 + 7;
const int inf = 1e9 + 7;
const long long infL = 1e18;
int setbit(int n, int pos) { return n = n | (1 << pos); }
int resetbit(int n, int pos) { return n = n & ~(1 << pos); }
bool checkbit(int n, int pos) { return (bool)(n & (1 << pos)); }
template <typename T>
T mul(T x, T y) {
  x %= mod;
  y %= mod;
  return (x * y) % mod;
}
template <typename T>
T add(T x, T y) {
  x %= mod;
  y %= mod;
  return (x + y) % mod;
}
template <typename T>
T modPow(T x, T k, T mod) {
  if (k == 0) return 1;
  if (k & 1) {
    return ((x % mod) * modPow(x, k - 1, mod) % mod) % mod;
  } else {
    T ret = modPow(x, k / 2, mod);
    ret %= mod;
    return (ret * ret) % mod;
  }
}
template <typename T>
T ext_gcd(T num1, T num2, T &X, T &Y) {
  T r2, r1, q2, q1, x2, x1, y2, y1, x, y, r;
  x2 = 1;
  y2 = 0;
  x1 = 0;
  y1 = 1;
  for (r2 = num1, r1 = num2; r1 != 0;
       y2 = y1, y1 = y, x2 = x1, x1 = x, r2 = r1, r1 = r) {
    q1 = r2 / r1;
    x = x2 - q1 * x1;
    y = y2 - q1 * y1;
    r = r2 % r1;
  }
  X = x2;
  Y = y2;
  return r2;
}
template <typename T>
void print(const T &v) {
  cerr << v << ' ';
}
template <typename T1, typename... T2>
void print(const T1 &first, const T2 &...rest) {
  print(first);
  print(rest...);
}
template <typename T>
T modInv(T x, T m) {
  return modPow(x, m - 2, m);
}
template <typename T>
void dbg_a(T a[], int n = 10) {
  for (int i = 0; i < n; i++) cerr << a[i] << ' ';
  cerr << "\n";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S> &p) {
  return os << "[ " << p.first << ", " << p.second << " ]";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[ ";
  for (int i = 0; i < v.size(); i++) os << v[i] << ' ';
  return os << " ]";
}
long long modAdd(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
const int M = (int)2e5 + 123;
const int nx = 1000 - 23;
int n, k, a[M + 2], res = 0, center = 102;
int vis[101][52][2][210];
string s;
void func(int id, int cnt, int f, int dist) {
  if (id >= s.size()) {
    if (cnt == 0) res = max(res, abs(dist));
    return;
  }
  int &v = vis[id][cnt][f][dist + center];
  if (v == 1) return;
  v = 1;
  for (int i = 0; i < cnt + 1; i++) {
    if (s[id] == 'F') {
      if (i & 1) {
        func(id + 1, cnt - i, 1 - f, dist);
      } else {
        func(id + 1, cnt - i, f, dist + (f == 0 ? 1 : -1));
      }
    } else {
      if (i & 1) {
        func(id + 1, cnt - i, f, dist + (f == 0 ? 1 : -1));
      } else {
        func(id + 1, cnt - i, 1 - f, dist);
      }
    }
  }
}
void solve() {
  cin >> s >> k;
  func(0, k, 0, 0);
  cout << res << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1, c = 0;
  while (t--) {
    solve();
  }
  return 0;
}
