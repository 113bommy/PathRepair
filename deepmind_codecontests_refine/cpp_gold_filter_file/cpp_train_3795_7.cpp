#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  char matriz[n / 2 + 1][n];
  for (int i = 0; i < n / 2 + 1; i++) {
    for (int j = 0; j < n; j++) {
      matriz[i][j] = '*';
    }
  }
  int inicio = n / 2, fin = n / 2;
  for (int i = 0; i < n / 2 + 1; i++) {
    for (int j = inicio; j <= fin; j++) {
      matriz[i][j] = 'D';
    }
    inicio--;
    fin++;
  }
  for (int i = 0; i < n / 2 + 1; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c", matriz[i][j]);
    }
    printf("\n");
  }
  for (int i = n / 2 - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      printf("%c", matriz[i][j]);
    }
    printf("\n");
  }
}
