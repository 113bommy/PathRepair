#include <bits/stdc++.h>
int main() {
  int n, i, t = 0;
  int p[101], q[101];
  scanf("%d", &n);
  for (i = 0; i <= n - 1; i++) {
    scanf("%d %d", &p[i], &q[i]);
    if (q[i] > p[i] && q[i] - p[i] >= 2) t++;
  }
  printf("%d", t);
  return 0;
}
