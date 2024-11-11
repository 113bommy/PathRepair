#include <bits/stdc++.h>
int minn = 2147483647, maxx = -2147483647;
int a[1001];
int main() {
  int h, o, i, j, k, n, ii, p;
  o = 1;
  scanf("%d %d", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] < minn) minn = a[i];
    if (a[i] > maxx) maxx = a[i];
  }
  if (maxx - minn > k) {
    printf("NO");
    return 0;
  } else
    printf("YES\n");
  p = minn;
  for (i = 1; i <= n; i++) {
    for (j = 0; j < a[i]; j++) printf("%d ", j % k + 1);
    printf("\n");
  }
  return 0;
}
