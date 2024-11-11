#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
long long a[maxn], g[maxn];
int pri[maxn], lst[maxn], top;
void pre_treat() {
  static bool f[maxn];
  for (int i = 2, n = maxn - 5; i <= n; i++) {
    if (!f[i]) pri[++top] = i;
    for (int j = 1; i * pri[j] <= n && j <= top; j++) {
      f[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
}
void work() {
  long long n, ans = 0;
  scanf("%lld", &n);
  for (int i = 1; i <= top; i++)
    if (pri[i] * 1ll * pri[i] <= n / pri[i]) ++ans;
  int cnt = 0, s, fin = 0;
  for (s = 1; (s + 1) * 1ll * (s + 1) <= n; ++s)
    ;
  for (int i = 1; i <= s; i++) a[++cnt] = i;
  if (n / s != s) a[++cnt] = n / s;
  for (int i = s - 1; i; i--) a[++cnt] = n / i;
  for (int i = 1; i <= cnt; i++) g[i] = a[i];
  for (int i = 1; pri[i] <= s; i++) {
    fin = i;
    long long dow = pri[i] * 1ll * pri[i];
    for (int j = cnt; a[j] >= dow; j--) {
      lst[j] = i;
      long long els = a[j] / pri[i];
      if (els > s) els = cnt - n / els + 1;
      g[j] -= g[els] - (i - 1 - lst[els]);
    }
  }
  for (int i = 1, r = 1; i <= cnt; i++) {
    for (; r <= fin && a[i] >= pri[r]; r++)
      ;
    g[i] -= r - lst[i];
  }
  for (int i = 1; i <= fin; i++) {
    ans += fin - i;
    long long els = n / pri[i];
    if (els > s) els = cnt - n / els + 1;
    ans += g[els];
  }
  printf("%lld\n", ans);
}
int main() {
  pre_treat();
  work();
  return 0;
}
