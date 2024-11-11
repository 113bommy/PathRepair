#include <bits/stdc++.h>
int p[100005];
int main(void) {
  int n, m, i, x;
  scanf("%d%d", &m, &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    x %= m;
    if (p[x] == 0)
      p[x] = 1;
    else {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0 * printf("-1\n");
}
