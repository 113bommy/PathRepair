#include <bits/stdc++.h>
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a, too = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    int k1 = 0;
    while (a / 10) {
      if (a % 10 == 4 || a % 10 == 7) k1++;
      a /= 10;
    }
    if (k1 < k) too++;
  }
  printf("%d\n", too);
  return 0;
}
