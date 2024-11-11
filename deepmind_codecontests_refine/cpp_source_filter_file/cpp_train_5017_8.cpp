#include <bits/stdc++.h>
using namespace std;
int setbit(int n, int pos) { return n = n | (1 << pos); }
int resetbit(int n, int pos) { return n = n & ~(1 << pos); }
bool checkbit(int n, int pos) { return (bool)(n & (1 << pos)); }
template <typename T>
T modMul(T x, T y, T mod = 1e9 + 7) {
  x %= mod;
  y %= mod;
  return (x * y) % mod;
}
template <typename T>
T modAdd(T x, T y, T mod = 1e9 + 7) {
  x %= mod;
  y %= mod;
  return (x + y) % mod;
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
template <class T>
string to_str(T t) {
  stringstream second;
  second << t;
  return second.str();
}
template <typename T>
T modPow(T x, T k, T mod = 1e9 + 7) {
  if (k == 0) return (T)1;
  if (k & 1) {
    return ((x % mod) * modPow(x, k - 1, mod) % mod) % mod;
  } else {
    T ret = modPow(x, k / 2, mod);
    ret %= mod;
    return (ret * ret) % mod;
  }
}
template <typename T>
T modInv(T x, T m) {
  return modPow(x, m - 2, m);
}
template <typename T>
void dbg_a(T a[], int n = 10) {
  cerr << "[ ";
  for (int i = 0; i < n; i++) cerr << a[i] << ' ';
  cerr << " ]"
       << "\n";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S> &p) {
  return os << "[ " << p.first << ", " << p.second << " ]";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[ ";
  for (int i = 0; i < v.size(); i++) os << v[i] << ' ';
  return os << " ]\n";
}
template <typename T>
ostream &operator<<(ostream &os, const map<T, T> &Map) {
  os << "[ ";
  for (__typeof((Map).begin()) it = (Map).begin(); it != (Map).end(); ++it)
    os << "[" << (*it).first << ' ' << (*it).second << "] ";
  return os << "]\n";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &Set) {
  os << "[ ";
  for (__typeof((Set).begin()) it = (Set).begin(); it != (Set).end(); ++it)
    os << *it << ' ';
  return os << " ]\n";
}
const int maxn = (int)2e6 + 123;
const int inf = 0x3f;
const long long mod = (long long)1e9 + 7LL;
int a[maxn], b[maxn], vis[maxn];
void solve() {
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) {
      for (; j < n; j++) {
        vis[b[j]]++;
        if (b[j] == a[i]) {
          j++;
          break;
        }
        cnt++;
      }
    }
  }
  cout << cnt << "\n";
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1, c = 0;
  while (t--) {
    solve();
  }
  return 0;
}
