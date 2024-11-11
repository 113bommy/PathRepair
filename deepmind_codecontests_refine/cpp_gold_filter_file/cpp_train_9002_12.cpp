#include <bits/stdc++.h>
int main() {
  int n, i, x1, x2, y1, y2;
  long long int num = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    num = num + (y2 - y1 + 1) * (x2 - x1 + 1);
  }
  printf("%I64d\n", num);
}
