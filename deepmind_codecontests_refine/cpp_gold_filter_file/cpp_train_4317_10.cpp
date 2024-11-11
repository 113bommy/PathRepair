#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int a[n + 1], i, j;
  a[0] = 0;
  int p[1000001];
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    for (j = a[i - 1] + 1; j <= a[i] + a[i - 1]; j++) p[j] = i;
    a[i] += a[i - 1];
  }
  int m;
  scanf("%d", &m);
  int q;
  for (i = 0; i < m; i++) {
    scanf("%d", &q);
    printf("%d\n", p[q]);
  }
  return 0;
}
