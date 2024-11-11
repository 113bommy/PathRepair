#include <bits/stdc++.h>
int main() {
  int a, c, b, d, e, f, g, h, m, n, i, j, ckk;
  scanf("%d %d", &n, &m);
  for (i = n + 1; i <= 50; i++) {
    ckk = 0;
    for (j = 2; j <= i; j++) {
      c = i % j;
      if (c == 0) ckk++;
    }
    if (ckk < 2) break;
  }
  if (i == m)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
