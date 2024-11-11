#include <bits/stdc++.h>
int main() {
  int n, i, x1, y1, z1, sumx1 = 0, sumy1 = 0, sumz1 = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", &x1, &y1, &z1);
    sumx1 = sumx1 + x1;
    sumy1 = sumy1 + y1;
    sumz1 = sumz1 + z1;
  }
  if (sumx1 == 0 && sumy1 == 0 && sumz1 == 0)
    printf("%YES\n");
  else
    printf("No\n");
  return 0;
}
