#include <bits/stdc++.h>
int a[110], b[110];
int main() {
  int n;
  scanf("%d", &n);
  for (int j = 0; j <= 100; j++) {
    b[j] = 1;
  }
  while (n--) {
    int r, i, k;
    scanf("%d", &r);
    for (int j = 0; j < 100; j++) {
      a[j] = 0;
    }
    for (i = 0; i < r; i++) {
      scanf("%d", &k);
      a[k] = 1;
    }
    for (i = 0; i <= 100; i++) {
      if (a[i] == 1 && b[i] == 1) {
        b[i] = 1;
      } else
        b[i] = 0;
    }
  }
  for (int i = 0; i <= 100; i++) {
    if (b[i] == 1) printf("%d ", i);
  }
}
