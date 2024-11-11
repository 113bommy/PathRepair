#include <bits/stdc++.h>
int main() {
  int i, j, n;
  float p, l = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &j);
    l = l + j / 100;
  }
  p = (l / n) * 100;
  printf("%f", 2 * p);
  return 0;
}
