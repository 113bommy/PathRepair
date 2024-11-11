#include <bits/stdc++.h>
int i, n, k, s = 0, t[100], j;
char a[20][100], b[100];
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
  j = n - s;
  if (j > s) {
    printf("%s", a[0]);
  } else {
    printf("%s", a[k]);
  }
}
