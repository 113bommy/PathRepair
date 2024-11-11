#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int qkpow(int a, int b) {
  int base = a, ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * base % mod;
    base = 1ll * base * base % mod;
    b >>= 1;
  }
  return ans;
}
int fac[1000005], inv[1000005];
int C(int n, int m) {
  if (n < m || m < 0) return 0;
  return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
void init_C(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[0] = 1;
  inv[n] = qkpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 1; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
long long t, n, m, k, now, len1, len2, x[200005], y[200005], f[2][300005];
long long ans;
set<long long> X, Y;
struct node {
  long long x, y;
} a[300005];
bool cmp(node A, node B) { return A.x < B.x; }
signed main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld %lld", &n, &m, &k);
    X.clear(), Y.clear();
    len1 = len2 = 0;
    X.insert(1e9);
    Y.insert(1e9);
    for (long long i = 1; i <= n; i++) scanf("%lld", &x[i]), X.insert(x[i]);
    for (long long i = 1; i <= m; i++) scanf("%lld", &y[i]), Y.insert(y[i]);
    for (long long i = 1; i <= k; i++) {
      scanf("%lld %lld", &a[i].x, &a[i].y);
      if (X.count(a[i].x))
        f[0][i] = 1;
      else
        f[0][i] = 0;
      if (Y.count(a[i].y))
        f[1][i] = 1;
      else
        f[1][i] = 0;
    }
    ans = 0;
    map<long long, vector<long long>> XX, YY;
    for (long long i = 1; i <= k; i++) {
      if (f[0][i] && f[1][i]) continue;
      if (f[0][i]) {
        long long Id = *Y.lower_bound(a[i].y);
        YY[Id].push_back(a[i].x);
      }
      if (f[1][i]) {
        long long Id = *X.lower_bound(a[i].x);
        XX[Id].push_back(a[i].y);
      }
    }
    for (auto pi : XX) {
      vector<long long>& v = pi.second;
      sort(v.begin(), v.end());
      long long tot = v.size(), now = 0;
      for (long long i = 0; i < tot; i++) {
        while (now < tot && v[now] == v[i]) now++;
        ans += tot - now;
      }
    }
    for (auto pi : YY) {
      vector<long long>& v = pi.second;
      sort(v.begin(), v.end());
      long long tot = v.size(), now = 0;
      for (long long i = 0; i < tot; i++) {
        while (now < tot && v[now] == v[i]) now++;
        ans += tot - now;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
