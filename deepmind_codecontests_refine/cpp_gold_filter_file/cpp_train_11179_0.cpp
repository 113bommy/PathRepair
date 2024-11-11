#include <bits/stdc++.h>
int main() {
  int k, n, i, j, p;
  scanf("%d %d", &n, &k);
  int mas[n], mas1[n], rab[k][n], z;
  for (i = 0; i < n - 1; i++) {
    mas[i] = 1;
  }
  mas[n] = 0;
  for (i = 0; i < n - 1; i++) {
    mas1[i] = 1;
  }
  mas1[n] = 0;
  for (i = 0; i < k; i++) {
    for (j = 0; j < n; j++) {
      mas[j] = mas1[j];
    }
    for (j = 1; j <= n; j++) {
      p = n - j;
      if (mas[p] < j - 1) {
        for (z = p; z < n; z++) {
          if ((mas[p] + mas[z]) <= j - 1) {
            mas1[p] = mas[p] + mas[z];
            rab[i][p] = z + 1;
            break;
          }
        }
      } else {
        rab[i][p] = n;
      }
    }
  }
  for (i = 0; i < k; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", rab[i][j]);
    }
    printf("\n");
  }
  return 0;
}
