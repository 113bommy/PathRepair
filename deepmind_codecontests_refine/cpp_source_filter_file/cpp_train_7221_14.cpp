#include <bits/stdc++.h>
int main() {
  int a[5][5];
  int count = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j] == 1) count = fabs(i - 3) + fabs(j - 3);
    }
  }
  printf("%d", count);
}
