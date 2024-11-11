#include <bits/stdc++.h>
int main() {
  int n, a, b, c, countx = 0;
  scanf("%d %d %d %d", &n, &a, &b, &c);
  for (int i = 0; i <= c; i++)
    for (int j = 0; j <= a; j++)
      if (2 * (n - 2 * i - j) <= a && 2 * (n - 2 * i - j) >= 0) countx++;
  printf("%d", countx);
}
