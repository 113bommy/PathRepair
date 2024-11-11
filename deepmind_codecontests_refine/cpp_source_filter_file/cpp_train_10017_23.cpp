#include <bits/stdc++.h>
int main() {
  int n, a, i, e = 0, o = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (a % 2 == 0)
      ++e;
    else
      ++o;
  }
  if (o % 2 == 0)
    printf("%d", e);
  else
    printf("1");
  return 0;
}
