#include <bits/stdc++.h>
using namespace std;
const long long inf = 2147383647;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
inline long long gcd(long long a, long long b) {
  a = ((a) < 0 ? -(a) : (a));
  b = ((b) < 0 ? -(b) : (b));
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
int ext_gcd(int A, int B, int* X, int* Y) {
  int x, y, u, v, m, n, a, b, q, r;
  x = 0;
  y = 1;
  u = 1;
  v = 0;
  for (a = A, b = B; 0 != a; b = a, a = r, x = u, y = v, u = m, v = n) {
    q = b / a;
    r = b % a;
    m = x - (u * q);
    n = y - (v * q);
  }
  *X = x;
  *Y = y;
  return b;
}
inline long long modInv(int a, int m) {
  int x, y;
  ext_gcd(a, m, &x, &y);
  if (x < 0) x += m;
  return x;
}
inline long long power(long long a, long long p) {
  long long res = 1, x = a;
  while (p) {
    if (p & 1) res = (res * x);
    x = (x * x);
    p >>= 1;
  }
  return res;
}
inline long long bigmod(long long a, long long p, long long m) {
  long long res = 1 % m, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
int n, a[200005];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int k = (n - 1) / 2;
  int u, v;
  u = 0, v = n - 1 - k;
  int ans = a[v] - a[u];
  for (int i = 0; i < k; i++, u++, v++) {
    if (a[v] - a[u] < ans) ans = a[v] - a[u];
  }
  cout << ans << endl;
  return 0;
}
