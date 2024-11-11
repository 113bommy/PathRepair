#include <bits/stdc++.h>
void tri(int* t, int n) {
  int i, j, x = n, aux;
  for (i = 0; i < n; i++) {
    for (j = 0; j < x - 1; j++) {
      if (t[j] > t[j + 1]) {
        aux = t[j];
        t[j] = t[j + 1];
        t[j + 1] = aux;
      }
    }
    x = x - 1;
  }
}
int main() {
  int n, a, i;
  scanf("%d", &n);
  int t[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    t[i] = a;
  }
  tri(t, n);
  printf("%d", t[n / 2]);
}
