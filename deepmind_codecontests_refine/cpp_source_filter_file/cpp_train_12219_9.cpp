#include <bits/stdc++.h>
int main() {
  int x;
  scanf("%d", &x);
  int a[x];
  for (int i = 1; i <= x; i++) {
    scanf("%d", &a[x]);
  }
  int n = 0, t = 0, l = 0;
  int i = 1, j = 2, k = 3;
  while (i <= x) {
    n += a[i];
    i += 3;
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
  } else if (l > n && l > t) {
    printf("back");
  }
  return 0;
}
