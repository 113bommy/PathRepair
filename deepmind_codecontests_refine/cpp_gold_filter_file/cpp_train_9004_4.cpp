#include <bits/stdc++.h>
const int N = 2001000;
int a[N], l[N], r[N], c[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int t1 = 0, t2 = -1;
  for (int i = 1; i <= n; i++)
    if (a[i] > t2) t2 = a[i], t1 = i;
  for (int i = 1; i < t1; i++) a[n + i] = a[i];
  for (int i = t1; i <= n; i++) a[i - t1 + 1] = a[i];
  for (int i = n + 1; i < n + t1; i++) a[i - t1 + 1] = a[i];
  for (int i = n; i >= 1; --i) {
    r[i] = i + 1;
    while (r[i] <= n && a[i] > a[r[i]]) r[i] = r[r[i]];
    if (r[i] <= n && a[i] == a[r[i]]) {
      c[i] = c[r[i]] + 1;
      r[i] = r[r[i]];
    }
  }
  for (int i = 1; i <= n; i++) {
    l[i] = i - 1;
    while (l[i] >= 1 && a[i] > a[l[i]]) l[i] = l[l[i]];
    if (l[i] >= 1 && a[i] == a[l[i]]) {
      l[i] = l[l[i]];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += c[i];
    if (a[i] == a[1]) continue;
    ans += 2;
    if (l[i] == 1 && r[i] == n + 1) ans--;
  }
  printf("%I64d\n", ans);
  return 0;
}
