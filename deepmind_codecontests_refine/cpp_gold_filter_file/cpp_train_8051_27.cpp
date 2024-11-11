#include <bits/stdc++.h>
int main() {
  int i, j, n;
  float p, l = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &j);
    l = l + j / 100.0;
  }
  p = (l / n) * 100.0;
  printf("%f", p);
  return 0;
}
