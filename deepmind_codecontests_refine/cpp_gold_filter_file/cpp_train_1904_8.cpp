#include <bits/stdc++.h>
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int i, m, x, n, j;
    scanf("%d %d", &n, &m);
    int a[n];
    x = 0;
    for (j = 0; j < n; j++) {
      scanf("%d ", &a[j]);
      x += a[j];
    }
    if (x == m)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
