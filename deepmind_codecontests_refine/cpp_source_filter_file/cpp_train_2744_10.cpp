#include <bits/stdc++.h>
int main() {
  int n, i, t, j, g, a[100005][2], b[100005];
  for (i = 0; i < 100005; i++) b[i] = 1;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j <= 1; j++) scanf("%d", &a[i][j]);
  if (n == 1)
    printf("1\n");
  else {
    for (i = 0, g = 0; i < n; i++) {
      if (a[i][0] == a[i + 1][0] && a[i][1] == a[i + 1][1]) {
        b[g]++;
      } else {
        g++;
      }
    }
    t = b[0];
    for (i = 1; i <= g; i++) {
      if (b[i] > t) {
        t = b[i];
      }
    }
    printf("%d\n", t);
  }
  return 0;
}
