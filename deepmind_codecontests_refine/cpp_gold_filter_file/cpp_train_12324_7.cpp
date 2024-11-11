#include <bits/stdc++.h>
int main() {
  int x = 0;
  int n;
  scanf("%d", &n);
  int j;
  for (j = 0; j < n; j++) {
    char ar[3];
    int i;
    for (i = 0; i < 3; i++) {
      scanf(" %c", &ar[i]);
    }
    if (ar[1] == '+') {
      x = x + 1;
    } else {
      x = x - 1;
    }
  }
  printf("%d", x);
  return 0;
}
