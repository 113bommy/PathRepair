#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MOD2 = 1007681537;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline long long isqrt(long long k) {
  long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
const int maxn = 21;
int n;
char s[1 << maxn];
int f[1 << maxn];
void XORFFT(int a[], int n, int p, int invert) {
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j += i << 1) {
      for (int k = 0; k < i; k++) {
        int u = a[j + k], v = a[i + j + k];
        a[j + k] = u + v;
        if (a[j + k] >= p) a[j + k] -= p;
        a[i + j + k] = u - v;
        if (a[i + j + k] < 0) a[i + j + k] += p;
      }
    }
  }
  if (invert) {
    long long inv = fpow(n, p - 2, p);
    for (int i = 0; i < n; i++) a[i] = a[i] * inv % p;
  }
}
void solve() {
  scanf("%d%s", &n, s);
  for (int i = (0); i < (1 << n); i++) f[i] = s[i] - '0';
  XORFFT(f, 1 << n, MOD, 0);
  for (int i = (0); i < (1 << n); i++) f[i] = mult(f[i], f[i], MOD);
  XORFFT(f, 1 << n, MOD, 1);
  int ans = 0;
  for (int i = (0); i < (1 << n); i++) {
    int k = n - __builtin_popcountll(i);
    addmod(ans, mult(f[i], fpow(2, k)));
  }
  ans = mult(ans, 3);
  cout << ans << "\n";
}
int main() {
  int JUDGE_ONLINE = 1;
  if (fopen("in.txt", "r")) {
    JUDGE_ONLINE = 0;
    assert(freopen("in.txt", "r", stdin));
  } else {
  }
  solve();
  if (!JUDGE_ONLINE) {
  }
  return 0;
}
