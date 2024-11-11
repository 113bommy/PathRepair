#include <bits/stdc++.h>
int main() {
  int i, j, k, t, m = 0, n, max = 0;
  int a[200];
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d", &a[i]);
    if (a[i] > max) max = a[i];
  }
  for (i = 0; i < t; i++) {
    m = max - a[i] + m;
  }
  printf("%d\n", m);
  return 0;
}
