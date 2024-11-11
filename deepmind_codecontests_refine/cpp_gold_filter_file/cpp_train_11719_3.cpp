#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const long long INF = 1e17 + 7;
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
T modInv(T x, T m = 1e9 + 7) {
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
  return os << " ]";
}
const int M = (int)2e6 + 5;
const int mx = 4000 + 23;
int n, dp[102][102][26];
int cost[30][30];
string s;
int func(int id, int cnt, int pre) {
  if (cnt < 0) return -inf;
  if (id < 1) return 0;
  int &ans = dp[id][cnt][pre];
  if (ans != -1) return ans;
  ans = -inf;
  for (int i = 0; i < 26; i++) {
    ans = max(ans, func(id - 1, ((i == (s[id] - 'a')) ? cnt : cnt - 1), i) +
                       cost[i][pre]);
  }
  return ans;
}
void solve() {
  cerr << "program running ... "
       << "\n";
  int q, x, k;
  cin >> s >> k;
  cin >> q;
  for (int i = 0; i < q; i++) {
    string s1, s2;
    cin >> s1 >> s2 >> x;
    cost[s1[0] - 'a'][s2[0] - 'a'] = x;
  }
  s = ' ' + s;
  memset(dp, -1, sizeof dp);
  int ans = -inf;
  for (int i = 0; i < 26; i++) {
    ans = max(ans,
              func(s.size() - 2, (s[s.size() - 1] - 'a' == i) ? k : k - 1, i));
  }
  cout << ans << "\n";
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
