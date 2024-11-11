#include <bits/stdc++.h>
int main() {
  int i, n, ok;
  scanf("%d", &n);
  int c[n], t[n];
  for (i = 0; i < n; i++) {
    scanf("%d %d", &c[i], &t[i]);
  }
  for (i = 0; i < n - 1; i++) {
    if (c[i] != t[i]) {
      printf("rated");
      return 0;
    }
  }
  for (i = 0; i < n - 1; i++) {
    if (c[i] < c[i + 1]) {
      printf("unrated");
      return 0;
    }
  }
  printf("maybe");
}
