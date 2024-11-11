#include <bits/stdc++.h>
int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
  int i, j, k, medio, sumador1 = 0, sumador2 = 0, contador = 0, val = 0, n;
  scanf("%d", &n);
  int vec[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &j);
    medio = j / 2;
    for (k = 0; k < j; k++) {
      scanf("%d", &val);
      if (k < medio)
        sumador1 += val;
      else if (k == medio && j % 2 != 0) {
        vec[contador++] = val;
      } else
        sumador2 += val;
    }
  }
  qsort(vec, contador, sizeof(int), cmpfunc);
  for (i = 0; i < contador; i++) {
    if (i % 2 != 0)
      sumador2 += vec[i];
    else
      sumador1 += vec[i];
  }
  printf("%d %d", sumador1, sumador2);
}
