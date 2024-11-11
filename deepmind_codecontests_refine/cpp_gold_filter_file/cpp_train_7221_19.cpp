#include <bits/stdc++.h>
int main() {
  int arr[5][5];
  int i, j, n = 5, r, c;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      scanf("%d", &arr[i][j]);
      if (arr[i][j] == 1) {
        r = abs(i - 2);
        c = abs(j - 2);
      }
    }
  }
  printf("%d", r + c);
  return 0;
}
