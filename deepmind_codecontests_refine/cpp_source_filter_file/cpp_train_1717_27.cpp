#include <bits/stdc++.h>
using namespace std;
const int mod1 = 998244353, mod = 1e9 + 7;
const int MAXN = 1e5 + 6, MAXM = 2e5 + 5;
const int inf = 2e9;
const long long linf = 1e18;
const long long second = 2;
struct Mat {
  long long a[second][second];
  long long* operator[](long long x) { return a[x]; }
  const long long* operator[](long long x) const { return a[x]; }
  friend Mat operator*(const Mat& a, const Mat& b) {
    Mat r;
    for (long long i = 0; i < second; i++) {
      for (long long j = 0; j < second; j++) {
        r[i][j] = 0;
        for (long long k = 0; k < second; k++) {
          r[i][j] = r[i][j] + a[i][k] * b[k][j];
        }
      }
    }
    return r;
  }
  friend Mat operator%(const Mat& a, const long long x) {
    Mat r;
    for (long long i = 0; i < second; i++) {
      for (long long j = 0; j < second; j++) {
        r[i][j] = a[i][j] % x;
      }
    }
    return r;
  }
} base;
template <typename T>
T binpow(T a, long long x, long long md) {
  if (x == 1) return a % md;
  T t = binpow(a, x / 2, md);
  if (x & 1)
    return t * t % md * a % md;
  else
    return t * t % md;
}
void Solve() {
  long long n, k, l, md;
  cin >> n >> k >> l >> md;
  base[0][0] = base[0][1] = base[1][0] = 1;
  base = binpow(base, n + 1, md);
  long long c[2];
  c[0] = base[0][0];
  c[1] = (binpow(2ll, n, md) + md - c[0]) % md;
  long long ans = 1;
  for (long long i = 0; i < l; i++) {
    long long x = (k >> i) & 1;
    ans = ans * c[x] % md;
    k ^= (x << i);
  }
  if (k)
    cout << 0;
  else
    cout << ans;
}
signed main() {
  if (fopen(""
            ".inp",
            "r")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  };
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long TC = 1;
  while (TC--) Solve();
  return 0;
}
