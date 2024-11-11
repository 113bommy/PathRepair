#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
const int mod = 1e9 + 7;
pair<int, int> a[maxn];
int fac[maxn], rfac[maxn];
int f[maxn];
inline int pow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = (long long)ans * a % mod;
    a = (long long)a * a % mod;
  }
  return ans;
}
inline int C(int n, int m) {
  return (long long)fac[n] * rfac[m] % mod * rfac[n - m] % mod;
}
inline void dec(int &a, int b) {
  a -= b;
  while (a < 0) a += mod;
  while (a >= mod) a -= mod;
}
int main() {
  fac[0] = rfac[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fac[i] = (long long)fac[i - 1] * i % mod;
    rfac[i] = pow(fac[i], mod - 2);
  }
  int h, w, n;
  scanf("%d%d%d", &h, &w, &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a + 1, a + n + 1);
  a[n + 1] = make_pair(h, w);
  for (int i = 1; i <= n + 1; i++) {
    f[i] = C(a[i].first + a[i].second - 2, a[i].first - 1);
    for (int j = 1; j < i; j++)
      if (a[i].first > a[j].first || a[i].second > a[j].second)
        dec(f[i], (long long)f[j] *
                      C(a[i].first - a[j].first + a[i].second - a[j].second,
                        a[i].first - a[j].first) %
                      mod);
  }
  printf("%d\n", f[n + 1]);
  return 0;
}
