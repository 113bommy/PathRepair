#include <bits/stdc++.h>
int main(void) {
  int a, i, n, s1 = 0, s2 = 0, s = 0;
  int x[3], y[3];
  for (i = 0; i < 3; ++i) {
    scanf("%d", &x[i]);
    s1 += x[i];
  }
  for (i = 0; i < 3; ++i) {
    scanf("%d", &y[i]);
    s2 += y[i];
  }
  scanf("%d", &n);
  if (s1 % 3 != 0) s++;
  if (s2 % 3 != 0) s++;
  if (s1 / 5 + s2 / 10 + s <= n)
    printf("YES");
  else
    printf("NO");
  return 0;
}
