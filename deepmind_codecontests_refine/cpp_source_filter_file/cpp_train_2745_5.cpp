#include <bits/stdc++.h>
const int N = 100005;
int K, n, maxb, t;
int f[N], a[N];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  K = read(), n = read(), maxb = read(), t = read();
  t = std::min(maxb, t);
  while (K--) {
    for (int i = 1; i <= n; i++) a[i] = read();
    memset(f, sizeof(f), 0);
    for (int i = 1; i <= t; i++)
      for (int j = 1, k; j <= n; j++)
        for (f[a[j]] = f[a[j] - 1] + 1, k = a[j] + 1;
             k <= maxb && f[a[j]] > f[k]; k++)
          f[k] = f[a[j]];
    printf("%d\n", f[maxb]);
  }
}
