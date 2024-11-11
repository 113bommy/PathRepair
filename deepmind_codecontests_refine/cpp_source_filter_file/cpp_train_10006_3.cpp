#include <bits/stdc++.h>
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    if (i % 3 == 1)
      printf("%d %d\n", (i + 3) / 4, 0);
    else if (i % 3 == 2)
      printf("%d %d\n", 0, (i + 3) / 4);
    else if (i % 3 == 3)
      printf("%d %d\n", -(i + 3) / 4, 0);
    else
      printf("%d %d\n", 0, -(i + 3) / 4);
  return 0;
}
