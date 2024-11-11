#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int p, q, c = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p, &q);
    if (p < q) c = c + 1;
  }
  printf("%d", c);
  return 0;
}
