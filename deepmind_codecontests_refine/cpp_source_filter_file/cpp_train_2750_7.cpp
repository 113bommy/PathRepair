#include <bits/stdc++.h>
int main() {
  int n, i, j, mh = 1, count = 1, flag = 0;
  scanf("%d", &n);
  int a[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j)
        continue;
      else {
        if (a[i] == a[j] && a[j] != 0) {
          a[j] = 0;
          flag++;
          count++;
        }
      }
      if (count > mh) mh = count;
    }
    count = 0;
  }
  printf("%d %d", mh, n - flag);
  return 0;
}
