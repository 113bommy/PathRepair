#include <bits/stdc++.h>
int main() {
  int n, a, b, c, d, x, y;
  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
  x = n * a + 2 * c;
  y = n * b + 2 * d;
  if (x < y)
    printf("First\n");
  else if (x > y)
    printf("Second\n");
  else
    printf("Friendship\n");
}
