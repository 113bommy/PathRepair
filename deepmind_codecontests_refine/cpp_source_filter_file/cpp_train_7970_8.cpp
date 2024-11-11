#include <bits/stdc++.h>
int main() {
  int n, t, i;
  scanf("%d%d", &n, &t);
  t = 240 - t;
  i = 0;
  while (t > 0) {
    t = t - 5 * i;
    i++;
    if (t < 5 * i) break;
  }
  i = i - 1;
  if (i > n)
    printf("%d\n", n);
  else
    printf("%d\n", i);
  return 0;
}
