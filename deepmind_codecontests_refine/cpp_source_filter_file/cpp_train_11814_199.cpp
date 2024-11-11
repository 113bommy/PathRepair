#include <bits/stdc++.h>
int main() {
  int n, m, x;
  scanf("%d", &m);
  scanf("%d", &n);
  x = m * n;
  if (x % 2 == 0)
    printf("%d", x / 2);
  else
    printf("%d", (x / 2) + 1);
}
