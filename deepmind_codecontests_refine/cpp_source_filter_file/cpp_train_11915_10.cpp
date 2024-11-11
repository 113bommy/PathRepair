#include <bits/stdc++.h>
#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
using namespace std;
const long long mod = 1e9 + 7;
const int inf = 1e9;
const long long lnf = 1e18;
int setbit(int n, int pos) { return n = n | (1 << pos); }
int resetbit(int n, int pos) { return n = n & ~(1 << pos); }
bool checkbit(int n, int pos) { return (bool)(n & (1 << pos)); }
template <typename T>
void print(const T& v) {
  cerr << v << ' ';
}
template <typename T>
T modMul(T x, T y) {
  x %= mod;
  y %= mod;
  return (x * y) % mod;
}
template <typename T>
T modAdd(T x, T y) {
  x %= mod;
  y %= mod;
  return (x + y) % mod;
}
template <typename T>
T modPow(T x, T k) {
  if (k == 0) return 1;
  if (k & 1) {
    return ((x % mod) * modPow(x, k - 1, mod) % mod) % mod;
  } else {
    T ret = modPow(x, k / 2, mod);
    ret %= mod;
    return (ret * ret) % mod;
  }
}
template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest) {
  print(first);
  print(rest...);
}
template <typename T>
T ext_gcd(T num1, T num2, T& X, T& Y) {
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
T modInv(T x, T m) {
  return modPow(x, m - 2, m);
  long long ret, t;
  ext_gcd(x, m, ret, t);
  ret %= m;
  if (ret < 0) ret += m;
  return ret;
}
const int M = 2000002;
long long row[M + 2], col[M + 2], tcnt[2][M + 2];
long long n, m, k, p;
priority_queue<int> pq;
void func(int id, int fuk) {
  while (pq.size() != 0) pq.pop();
  int lim;
  if (id == 0) {
    for (int i = 0; i < n; i++) pq.push(row[i]);
  } else {
    for (int i = 0; i < n; i++) pq.push(col[i]);
  }
  for (int i = 1; i <= k; i++) {
    long long x = pq.top();
    pq.pop();
    tcnt[id][i] = x;
    x -= fuk * p;
    pq.push(x);
  }
  for (int i = 1; i <= k; i++) tcnt[id][i] += tcnt[id][i - 1];
}
void solve() {
  cin >> n >> m >> k >> p;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      row[i] += x;
      col[j] += x;
    }
  func(0, m);
  func(1, n);
  long long ans = -lnf;
  for (int i = 0; i < k + 1; i++) {
    long long tmp;
    tmp = tcnt[0][i] + tcnt[1][(k - i)] - i * (k - i) * p;
    ans = max(ans, tmp);
  }
  cout << ans << "\n";
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
