#include <bits/stdc++.h>
int main() {
  int n, k, a[4] = {2, 3, 4, 5}, x, min = 250;
  scanf("%d %d", &n, &k);
  if (n * 5 == k || n * 3 == k || n * 4 == k) {
    printf("0");
    return 0;
  }
  for (int i = n; i >= 0; i--) {
    x = i * 5;
    if (x > k) continue;
    for (int j = n; j >= 0; j--) {
      x = i * 5 + j * 4;
      if (x > k) continue;
      for (int z = n; z >= 0; z--) {
        x = i * 5 + j * 4 + z * 3;
        if (x > k) continue;
        for (int l = 0; l <= n; l++) {
          x = i * 5 + j * 4 + z * 3 + l * 2;
          if (x > k) break;
          if (x == k && l < min && (i + j + z + l == n)) min = l;
        }
      }
    }
  }
  printf("%d", min);
  return 0;
}
