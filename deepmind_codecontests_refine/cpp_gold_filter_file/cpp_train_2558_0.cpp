#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", (4 + 2 * (x2 % 2) + y2 % 2) % 4 + 1);
  }
  return 0;
}
