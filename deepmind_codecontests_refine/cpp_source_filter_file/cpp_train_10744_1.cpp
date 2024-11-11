#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a[3], i;
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    for (i = 1; i < 3; i++) {
      int k = a[i];
      int j = i - 1;
      while (j >= 0 && a[j] > k) {
        a[j + 1] = a[j];
        j = j - 1;
      }
      a[j + 1] = k;
    }
    if (a[0] + a[1] >= a[2]) {
      printf("YES\n");
      continue;
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
