#include <bits/stdc++.h>
const int MAXN = 100 + 10;
int a[MAXN];
int main() {
  int n, w, p;
  int i, j, sum = 0;
  scanf("%d %d", &n, &w);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  p = 1;
  for (i = 2; i <= n; i++)
    if (a[i] < a[p]) p = i;
  if (n == 1) {
    if (w == a[1]) {
      printf("Yes\n");
      for (i = 1; i <= w; i++) printf("1 ");
      putchar('\n');
    } else
      printf("No\n");
    return 0;
  }
  if (w <= 0 or w > sum or (w == 1 and a[p] > 1)) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  if (a[p] > w) {
    j = (p == 1) ? 2 : 1;
    printf("%d ", j);
    for (i = 1; i < a[p]; i++) printf("%d %d ", p, p);
    printf("%d ", j);
    a[j]--;
    a[p] = 1;
    w--;
  }
  for (i = 1; i <= a[p] - 1; i++) printf("%d %d ", p);
  w -= a[p] - 1;
  a[p] = 0;
  for (i = 1; i <= n and w > 1; i++) {
    while (w > 1 and a[i]) {
      w--;
      a[i]--;
      printf("%d %d ", i, i);
    }
  }
  printf("%d ", p);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= a[i]; j++) printf("%d %d ", i, i);
  printf("%d\n", p);
  return 0;
}
