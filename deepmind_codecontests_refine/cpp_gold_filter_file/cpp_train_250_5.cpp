#include <bits/stdc++.h>
using namespace std;
int n, kk, ans = -1000 * 210, a[310], b[310], c[310];
int min(int a, int b) { return (a < b) ? a : b; }
int cmp(int a, int b) {
  if (a > b) return true;
  return false;
}
int main() {
  int i, j, k, tot1, tot2;
  scanf("%d%d", &n, &kk);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (n == 1) {
    printf("%d", a[1]);
    return 0;
  }
  for (i = 1; i <= n; i++)
    for (j = i; j <= n; j++) {
      for (k = i, tot1 = 0; k <= j; k++) b[++tot1] = a[k];
      for (k = 1, tot2 = 0; k < i; k++) c[++tot2] = a[k];
      for (k = j + 1; k < n; k++) c[++tot2] = a[k];
      sort(b + 1, b + tot1 + 1);
      sort(c + 1, c + tot2 + 1, cmp);
      for (k = 1; k <= min(kk, j - i + 1); k++)
        if (b[k] < c[k]) {
          int t = b[k];
          b[k] = c[k];
          c[k] = t;
        } else
          break;
      int sum = 0;
      for (k = 1; k <= tot1; k++) sum += b[k];
      if (sum > ans) ans = sum;
    }
  printf("%d", ans);
  return 0;
}
