#include <bits/stdc++.h>
using namespace std;
int read() {
  bool f = 0;
  int x = 0;
  char c = getchar();
  while (c < '0' || '9' < c) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while ('0' <= c && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return !f ? x : -x;
}
int L[50000 + 5], R[50000 + 5];
int a[50000 + 5], sum[1000000 + 5], f[50000 + 5], ans[50000 + 5];
int main() {
  for (int i = 1; i <= 1000000; i++) sum[i] = sum[i - 1] ^ i;
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= m; i++) L[i] = read(), R[i] = read();
  for (int i = 1; i <= n; i++) {
    f[i] = a[i];
    for (int j = i + 1; j <= n; j++)
      f[j] = max(f[j - 1], sum[min(a[i], a[j]) - 1] ^ sum[max(a[i], a[j])]);
    for (int j = 1; j <= m; j++)
      if (L[j] <= i && i <= R[j]) ans[j] = max(ans[j], f[R[j]]);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
