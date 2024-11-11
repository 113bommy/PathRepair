#include <bits/stdc++.h>
void ordQuicksort(int a[], int ini, int fin);
int main() {
  int n;
  scanf("%d", &n);
  int vec[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &vec[i]);
  }
  int penalizacion = 0;
  int limite = 900;
  int actual = 370;
  ordQuicksort(vec, 0, n - 1);
  int con = 0;
  while (actual + vec[con] <= 720) {
    actual = actual + vec[con];
    con++;
  }
  while (actual + vec[con] <= 1080) {
    actual = actual + vec[con];
    penalizacion = penalizacion + (actual - 720);
    con++;
  }
  printf("%d %d", con, penalizacion);
  return 0;
}
void ordQuicksort(int a[], int ini, int fin) {
  int i, j, central, pivote, aux;
  central = (ini + fin) / 2;
  pivote = a[central];
  i = ini;
  j = fin;
  while (i < j) {
    while (a[i] < pivote) i++;
    while (a[j] > pivote) j--;
    if (i <= j) {
      aux = a[i];
      a[i] = a[j];
      a[j] = aux;
      j--;
      i++;
    }
  }
  if (ini < j) ordQuicksort(a, ini, j);
  if (i < fin) ordQuicksort(a, i, fin);
}
