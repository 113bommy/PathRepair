#include <bits/stdc++.h>
int main() {
  int n, c;
  scanf("%d %d", &n, &c);
  if (c % 2)
    printf("%d", (c + 1) / 2);
  else
    printf("%d", ((n - c) / 2) + 1);
  return 0;
}
