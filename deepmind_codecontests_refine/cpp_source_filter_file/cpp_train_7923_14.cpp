#include <bits/stdc++.h>
bool f[20];
long long x, b[20];
int i, j, n, M, q, p[20], a[20][20];
void E() {
  puts("The times have changed");
  exit(0);
}
void Q() {
  for (i = 1; i <= n; ++i) printf("%d ", p[i]);
  exit(0);
}
void dfs(int k) {
  if (k > n) {
    if (!--x) Q();
    return;
  }
  int L = 1, R = n;
  for (i = 1; i < k; ++i) {
    if (a[i][k]) L = p[i] < L ? L : p[i] + 1;
    if (a[k][i]) R = p[i] > R ? R : p[i] - 1;
  }
  for (; L <= R; ++L)
    if (!f[L]) p[k] = L, f[L] = 1, dfs(k + 1), f[L] = 0;
}
int main() {
  scanf("%d%I64d%d", &n, &x, &q);
  for (*b = i = 1; i <= n; ++i) b[i] = i * b[i - 1];
  if ((x -= 2000) > b[n]) E();
  if (!q) {
    for (i = n; i--;)
      for (j = 1; j <= n; ++j)
        if (!f[j])
          if (b[i] < x)
            x -= b[i];
          else
            printf("%d ", j), f[j] = 1, j = n;
    return 0;
  }
  for (x -= 2e3; q--; a[i][j] = 1) scanf("%d%d", &i, &j);
  dfs(1), E();
}
