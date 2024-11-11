#include <bits/stdc++.h>
int main() {
  int n, b, a[11] = {0}, m, c[11], i;
  scanf("%d%d", &n, &b);
  for (i = 0; i < n; i++) {
    scanf("%d", &m);
    c[i] = m;
    a[m]++;
  }
  for (i = 0; i < b; i++) {
    scanf("%d", &m);
    a[m]++;
  }
  for (i = 0; i < n; i++)
    if (a[c[i]] > 1) printf("%d ", a[c[i]]);
  printf("\n");
}
