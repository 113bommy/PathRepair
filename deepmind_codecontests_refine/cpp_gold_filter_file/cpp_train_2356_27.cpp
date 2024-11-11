#include <bits/stdc++.h>
int main() {
  int n, i, total, max, min;
  scanf("%d", &n);
  int nomor[n];
  max = 0;
  min = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &nomor[i]);
  }
  if (n == 2) {
    total = 0;
    printf("%d", total);
  } else {
    for (i = 0; i < n; i++) {
      if (i != 0 && i != n - 1) {
        if (nomor[i] > nomor[i - 1] && nomor[i] > nomor[i + 1]) {
          max = max + 1;
        }
        if (nomor[i] < nomor[i - 1] && nomor[i] < nomor[i + 1]) {
          min = min + 1;
        }
      }
    }
    total = max + min;
    printf("%d \n", total);
  }
  return 0;
}
