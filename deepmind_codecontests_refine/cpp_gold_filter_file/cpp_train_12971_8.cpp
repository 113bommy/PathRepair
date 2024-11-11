#include <bits/stdc++.h>
const int maxn = 100010, maxa = 1 << 24;
int n, a[maxn], p[maxn], d[maxn], s[maxa];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 2; i <= n; i++) scanf("%d", p + i), d[i] = d[p[i]] + 1;
  int x = 0, c = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if ((d[i] - d[n]) % 2)
      s[a[i]]++;
    else
      x ^= a[i], c++;
  }
  if (!x) ans += c * (c - 1ll) / 2 + (n - c) * (n - c - 1ll) / 2;
  for (int i = 1; i <= n; i++)
    if ((d[i] - d[n]) % 2 == 0) ans += s[x ^ a[i]];
  printf("%lld\n", ans);
}
