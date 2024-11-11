#include <bits/stdc++.h>
int checkzero;
int su[100002];
int n;
int main() {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &su[i]);
    checkzero += su[i];
  }
  if (n == 1) {
    if (su[0]) {
      printf("NO");
    } else {
      printf("YES\n0");
    }
  } else if (su[n - 1] == 1) {
    printf("NO");
  } else if (su[n - 2] == 0 && su[n - 1] == 0 && checkzero == 2) {
    printf("NO");
  } else {
    printf("YES\n");
    for (i = 0; i < n - 2; i++) {
      printf("(%d->", su[i]);
    }
    printf("%d", su[n - 2]);
    for (i = 0; i < n - 2; i++) {
      printf(")");
    }
    printf("->%d", su[n - 1]);
  }
}
