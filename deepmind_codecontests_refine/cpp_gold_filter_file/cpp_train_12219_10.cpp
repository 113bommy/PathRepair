#include <bits/stdc++.h>
int main() {
  int x;
  scanf("%d", &x);
  int a[x];
  for (int i = 1; i <= x; i++) {
    scanf("%d", &a[i]);
  }
  int n = 0, t = 0, l = 0;
  int r = 1, j = 2, k = 3;
  while (r <= x) {
    n += a[r];
    r += 3;
  }
  while (j <= x) {
    t += a[j];
    j += 3;
  }
  while (k <= x) {
    l += a[k];
    k += 3;
  }
  if (n > t && n > l) {
    printf("chest");
  } else if (t > n && t > l) {
    printf("biceps");
  } else if (l > t && l > n) {
    printf("back");
  }
  return 0;
}
