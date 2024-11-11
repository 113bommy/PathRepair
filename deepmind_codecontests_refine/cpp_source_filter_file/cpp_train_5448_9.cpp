#include <bits/stdc++.h>
int n, m, a[2 * 1100000], bi[1100000];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  memset(bi, -1, sizeof(bi));
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    bi[x] = i;
  }
  for (int i = 0; i < n; i++) {
    a[i] = a[i + n] = bi[a[i]];
  }
  int lm = 0;
  int i = 0, j = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) continue;
    if (i > j) j = i;
    if (a[i] <= a[j]) {
      while (a[j + 1] >= a[j]) ++j;
      if (a[j + 1] >= 0 && a[j + 1] < a[i]) ++j;
      while (a[j + 1] >= a[j] && a[j + 1] < a[i]) ++j;
    } else {
      while (a[j + 1] >= a[j] && a[j + 1] < a[i]) ++j;
    }
    if (j - i + 1 > lm) lm = j - i + 1;
  }
  printf("%d\n", lm);
  return 0;
}
