#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n, a[2000005], f[2000005], g[2000005], b[2000005], p[2000005], c[2000005];
long long ans = 1;
bool ok;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int o;
    scanf("%d", &o);
    ++a[o];
  }
  for (int i = 2000000; i; --i) {
    if (!a[i]) continue;
    if (a[i] > 2) ok = 1;
    if (a[i] > 1) {
      f[i] = f[i - 1] = 1;
      continue;
    }
    bool fl = 0;
    for (int j = i; j <= 2000000; j += i)
      if (f[j]) fl = 1, j = 2000000;
    if (fl)
      f[i - 1] = 1;
    else
      f[i] = 1;
  }
  if (f[1]) ok = 1;
  for (int i = 2; i <= 2000000; ++i) {
    if (p[i]) continue;
    for (int j = i + i; j <= 2000000; j += i) p[j] = 1;
  }
  for (int i = 2000000; i >= 2; --i) {
    if (p[i]) continue;
    p[i] = i;
    int t = i;
    while (t <= 2000000 / i) t *= i, p[t] = i;
  }
  for (int i = 2000000; i > 1; --i) {
    if (p[i] == 1) continue;
    bool fl = 0;
    for (int j = i + i; j <= 2000000; j += i)
      if (b[j]) fl = 1, j = 2000000;
    if (fl) continue;
    for (int j = i; j <= 2000000; j += i)
      if (f[j]) ++fl;
    if (fl == 1) {
      for (int j = i; j <= 2000000; j += i)
        if (f[j]) g[j] = 1;
    }
    if (fl) b[i] = 1;
  }
  for (int i = 2; i <= 2000000; ++i)
    if (f[i] && !g[i]) ok = 1;
  for (int i = 2; i <= 2000000; ++i)
    if (b[i]) ans = ans * 1ll * i % 1000000007ll;
  if (ok) ans = (ans + 1ll) % 1000000007ll;
  ans = (ans % 1000000007ll + 1000000007ll) % 1000000007ll;
  printf("%I64d\n", ans);
  return 0;
}
