#include <bits/stdc++.h>
int main() {
  int i, l = 0, j, k, n, b, a, f, arr[10] = {1, 2, 3, 4, 6, 12};
  char st[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", st);
    a = 12;
    f = 0;
    int m = 0, t = 0, arr1[10][5];
    for (j = 0; j < a; j++) {
      l = 0;
      m = 0;
      for (k = 0; k < arr[f]; k++) {
        if (st[j + (a * k)] == 'X') {
          l++;
        } else
          break;
      }
      if (l == arr[f]) {
        arr1[t][0] = arr[f];
        arr1[t][1] = a;
        t++;
        m = 1;
      }
      if (a == 1) break;
      if (j == a - 1 || m == 1) {
        f++;
        a = 12;
        a = a / arr[f];
        m = 0;
        j = -1;
      }
    }
    printf("%d ", t);
    for (j = 0; j < t; j++) printf("%dX%d ", arr1[j][0], arr1[j][1]);
    printf("\n");
  }
}
