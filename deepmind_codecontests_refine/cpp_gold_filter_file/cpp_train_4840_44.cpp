#include <bits/stdc++.h>
int main() {
  int no_of_cars, i, j, flag, k;
  scanf("%d", &no_of_cars);
  int A[no_of_cars][no_of_cars];
  for (i = 0; i < no_of_cars; i++) {
    for (j = 0; j < no_of_cars; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  int good_cars[no_of_cars];
  k = 0;
  for (i = 0; i < no_of_cars; i++) {
    flag = 1;
    for (j = 0; j < no_of_cars; j++) {
      if (A[i][j] == 1 || A[i][j] == 3) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      good_cars[k] = i + 1;
      k++;
    }
  }
  printf("%d\n", k);
  for (i = 0; i < k; i++) {
    printf("%d ", good_cars[i]);
  }
}
