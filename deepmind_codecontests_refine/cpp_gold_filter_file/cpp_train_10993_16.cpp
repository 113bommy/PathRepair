#include <bits/stdc++.h>
int main() {
  int n, i, j, count, s;
  float c;
  scanf("%d", &n);
  s = 0;
  for (i = 0; s <= n; i++) {
    s = s + (5 * pow(2, i));
  }
  c = (float)((n - s + 5 * pow(2, i - 1)) / pow(2, i - 1));
  if (c > 0 && c <= 1)
    printf("Sheldon\n");
  else if (c > 1 && c <= 2)
    printf("Leonard\n");
  else if (c > 2 && c <= 3)
    printf("Penny\n");
  else if (c > 3 && c <= 4)
    printf("Rajesh\n");
  else if (c == 0 || c > 4)
    printf("Howard\n");
  return 0;
}
