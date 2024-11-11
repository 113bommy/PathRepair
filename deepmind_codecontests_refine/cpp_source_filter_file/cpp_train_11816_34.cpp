#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int mod = 1000000007;
pair<int, int> a[N];
int h, w, n, f[N];
long long fac[200010], facm[200010];
long long p_m(long long a, int b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int calc(int n, int m) { return fac[n] * facm[m] % mod * facm[n - m] % mod; }
int main() {
  fac[0] = 1;
  facm[0] = 1;
  for (int i = 1; i <= 200000; ++i)
    fac[i] = fac[i - 1] * i % mod, facm[i] = p_m(fac[i], mod - 2);
  scanf("%d%d%d", &h, &w, &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a + 1, a + n + 1);
  a[n + 1].first = h, a[n + 1].second = w;
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n + 1; ++i) {
    f[i] = calc(a[i].first + a[i].second - 2, a[i].first - 1);
    for (int j = 1; j < i; ++j) {
      if (a[i].first < a[j].first || a[i].second < a[j].second) continue;
      f[i] = (f[i] - (long long)f[j] * calc(a[i].first + a[i].second -
                                                a[j].first - a[j].second,
                                            a[i].first - a[j].first)) %
             mod;
    }
  }
  printf("%d\n", f[n + 1] + mod % mod);
  return 0;
}
