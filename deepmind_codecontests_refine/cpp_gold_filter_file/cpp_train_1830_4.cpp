#include <bits/stdc++.h>
int f[4000001];
int getf(int now) {
  if (f[now] == now) return now;
  return f[now] = getf(f[now]);
}
int main() {
  int i, n, m, s = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= 2 * n + 2 * m; i++) f[i] = i;
  for (i = 1; i <= n; i++)
    if (i <= m)
      f[getf(i)] = getf(2 * n + i);
    else
      f[getf(i)] = getf(n + i - m + 1);
  for (i = 1; i <= m; i++)
    if (m - i + 1 <= n)
      f[getf(2 * n + i)] = getf(n + m - i + 1);
    else
      f[getf(2 * n + i)] = getf(3 * n + m + i - 1);
  for (i = 1; i <= n; i++) {
    if (n - i + 1 <= m) f[getf(n + i)] = getf(n + 2 * m + i);
    if (i >= m) f[getf(n + i)] = getf(i - m + 1);
  }
  for (i = 1; i <= m; i++) {
    if (i <= n) f[getf(2 * n + m + i)] = getf(n - i + 1);
    if (i + n - 1 <= m) f[getf(2 * n + m + i)] = getf(3 * n + i - 1);
  }
  for (i = 1; i <= 2 * n + 2 * m; i++) s += (f[i] == i);
  printf("%d\n", s);
  return 0;
}
