#include <bits/stdc++.h>
int i, n, k, s = 0, t[100], j;
char a[101][101], b[100];
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", &a[i]);
  }
  for (i = 1; i < n; i++) {
    if (strcmp(a[0], a[i]) == 0) {
      s++;
    } else {
      k = i;
    }
  }
  j = n - s - 1;
  if (j > s) {
    printf("%s", a[k]);
  } else {
    printf("%s", a[0]);
  }
}
