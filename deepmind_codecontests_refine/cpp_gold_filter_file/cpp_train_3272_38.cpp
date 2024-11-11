#include <bits/stdc++.h>
int t[101], n, b, aux, i;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
  }
  do {
    b = 0;
    for (i = 1; i <= n - 1; i++) {
      if (t[i] > t[i + 1]) {
        aux = t[i];
        t[i] = t[i + 1];
        t[i + 1] = aux;
        b++;
      }
    }
  } while (b != 0);
  for (i = 1; i <= n; i++) {
    printf("%d ", t[i]);
  }
}
