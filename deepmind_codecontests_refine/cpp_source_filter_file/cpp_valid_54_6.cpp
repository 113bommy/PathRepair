#include <bits/stdc++.h>
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
  if (x < y) x = y;
}
mt19937 rnd(time(0));
int mod = 1000000007;
int mul(int a, int b) { return 1ll * a * b % mod; }
int add(int a, int b) {
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
int sub(int a, int b) {
  if (a - b < 0) return a - b + mod;
  return a - b;
}
int binpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
const int MAXN = 2e5 + 228;
int inv(int x) { return binpow(x, mod - 2); }
int fact[MAXN];
int rfact[MAXN];
int cnk(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mul(fact[n], mul(rfact[k], rfact[n - k]));
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.precision(20), cout.setf(ios::fixed);
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i) fact[i] = mul(fact[i - 1], i);
  rfact[MAXN - 1] = inv(fact[MAXN - 1]);
  for (int i = MAXN - 2; i >= 0; --i) rfact[i] = mul(rfact[i + 1], i + 1);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
      int am = 0;
      for (int bt = 0; bt < n; bt += 2) {
        am = add(am, cnk(n, bt));
      }
      int gl = binpow(2, k);
      int ans = 0;
      int nw = 1;
      for (int fbt = k - 1; fbt >= 0; --fbt) {
        ans = add(ans, mul(nw, binpow(gl, fbt)));
        nw = mul(nw, am);
      }
      ans = add(ans, nw);
      cout << ans << endl;
    } else {
      int am = 1;
      for (int bt = 0; bt <= n; bt += 2) {
        am = add(am, cnk(n, bt));
      }
      am = binpow(am, k);
      cout << am << '\n';
    }
  }
}
