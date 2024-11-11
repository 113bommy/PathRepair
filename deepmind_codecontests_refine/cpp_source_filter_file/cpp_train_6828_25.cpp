#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
int n, m, blo, a[maxn], ans[maxn][400];
int main() {
  scanf("%d", &n);
  blo = pow(n, 0.6);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= blo; i++)
    for (int j = n; j >= 1; j--)
      ans[j][i] = (a[j] + i + j > n ? 1 : ans[a[j] + i + j][i] + 1);
  for (scanf("%d", &m); m--;) {
    int p, k;
    scanf("%d%d", &p, &k);
    if (k <= blo)
      printf("%d\n", ans[p][k]);
    else {
      int cnt = 0;
      for (; p <= n; p += a[p] + k) cnt++;
      printf("%d\n", cnt);
    }
  }
  return 0;
}
