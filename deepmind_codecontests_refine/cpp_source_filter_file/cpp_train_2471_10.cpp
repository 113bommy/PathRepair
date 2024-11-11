#include <bits/stdc++.h>
int main(void) {
  int n, j;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    j = 0;
    while (j < i) {
      if (a[i] < a[j]) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
      j++;
    }
  }
  printf("%d", a[n / 2]);
}
