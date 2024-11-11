#include <bits/stdc++.h>
using namespace std;
int g[160][160][160];
int F[160];
int a[160];
char s[160];
int n;
int f(int x, int y, int h) {
  if (g[x][y][h] == -1) {
    int &gt = g[x][y][h];
    if (x > y) {
      if (h == 0) return gt = 0;
      if (a[h] == -1) return -10000000;
      return a[h];
    }
    gt = -10000000;
    if (x == y) {
      if (h == 0) return gt = (a[1] == -1 ? -10000000 : a[1]);
      if (a[h] > -1 && a[1] > -1) gt = max(gt, a[h] + a[1]);
      if (a[h + 1] > -1) gt = max(gt, a[h + 1]);
      return gt;
    }
    if (a[h + 1] > -1) {
      gt = max(gt, f(x + 1, y, 0) + a[h + 1]);
      gt = max(gt, f(x, y - 1, 0) + a[h + 1]);
    }
    for (int i = x; i < y; i++) {
      gt = max(gt, f(x, i, 0) + f(i + 1, y, h));
      gt = max(gt, f(x, i, h) + f(i + 1, y, 0));
      if (h && a[h] > -1) gt = max(gt, f(x, i, 0) + f(i + 1, y, 0) + a[h]);
    }
    if (s[x] == s[y]) {
      if (a[h + 2] > -1) gt = max(gt, f(x + 1, y - 1, 0) + a[h + 2]);
      gt = max(gt, f(x + 1, y - 1, h + 2));
    }
  }
  return g[x][y][h];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  scanf("%s", s);
  memset(g, -1, sizeof(g));
  for (int i = 0; i < n; i++) {
    F[i] = 0;
    for (int j = i; j >= 0; j--) {
      int tmp = (j == 0 ? 0 : F[j - 1]);
      F[i] = max(F[i], tmp + f(j, i, 0));
    }
    if (i) F[i] = max(F[i], F[i - 1]);
  }
  printf("%d\n", F[n - 1]);
  return 0;
}
