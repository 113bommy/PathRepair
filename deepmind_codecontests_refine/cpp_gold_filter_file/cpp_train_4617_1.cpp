#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, n, m, s, an, sum, K, tot;
const long long N = 410000;
long long a[N], b[N], f[N];
bool work(long long L) {
  for (int i = 1; i <= n; i++) a[i] = b[i], f[i] = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = 1ll * (i + i + n * (L - 1)) * L / 2;
    if (f[i] > a[i]) return false;
  }
  long long now = m - n * L;
  long long k = 1;
  for (int i = 1; i <= n; i++)
    if (a[i] - f[i] < a[k] - f[k]) k = i;
  if (a[k] - f[k] >= now * L) {
    for (int i = 1; i <= n; i++) f[i] += now * L;
  } else {
    long long w = a[k] - f[k] - now * (L - 1);
    if (w < 0) w = 0;
    now -= w;
    long long v = a[k] - f[k];
    for (int i = n; i >= 1; i--) f[i] += v;
    for (int i = n; i >= 1; i--) {
      now = min(now, a[i] - f[i]);
      f[i] += now;
    }
  }
  long long s = 0;
  for (int i = 1; i <= n; i++) s += f[i];
  an = max(an, s);
  return true;
}
int main() {
  scanf("%I64d%I64d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]), b[i] = a[i];
  for (long long L = 1; L <= m / n; L++) {
    if (!work(L)) break;
  }
  printf("%I64d\n", an);
  return 0;
}
