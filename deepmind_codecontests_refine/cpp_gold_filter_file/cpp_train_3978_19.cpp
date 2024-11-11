#include <bits/stdc++.h>
int combinacion(int t1, int t2, int v[], int n);
int main() {
  int n, i;
  int b;
  scanf("%d", &n);
  int v[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  if (n == 2) {
    printf("%d\n%d", v[0], v[1]);
  } else {
    i = 0;
    b = 0;
    while (i < 3 && b == 0) {
      if (i == 0) {
        b = combinacion(v[0], v[1], v, n);
      } else if (i == 1) {
        b = combinacion(v[1], v[2], v, n);
      } else if (i == 2) {
        b = combinacion(v[0], v[2], v, n);
      }
      i++;
    }
  }
  if (b == 0) {
    printf("No solution");
  }
  return 0;
}
int combinacion(int t1, int t2, int v[], int n) {
  int valido = 0;
  int r = t2 - t1;
  int div1[n];
  int div2[n];
  int cont1, cont2;
  int i;
  int termino = t1;
  int cont;
  cont1 = 0, cont2 = -1;
  for (i = 0; i < n; i++) {
    if (termino == v[i]) {
      div1[cont1] = v[i];
      cont1++;
      termino = termino + r;
    } else {
      cont2++;
      div2[cont2] = v[i];
    }
  }
  if (cont2 == -1) {
    valido = 1;
    for (i = 0; i < cont1 - 1; i++) {
      printf("%d ", div1[i]);
    }
    printf("\n%d", div1[i]);
  } else if (cont2 <= 1) {
    valido = 1;
    for (i = 0; i < cont1; i++) {
      printf("%d ", div1[i]);
    }
    printf("\n");
    for (i = 0; i <= cont2; i++) {
      printf("%d ", div2[i]);
    }
  } else {
    int b = -1;
    int invalido = 0;
    if (div2[1] - div2[0] == div2[2] - div2[1]) {
      r = div2[1] - div2[0];
    } else if (div1[cont1 - 1] - div2[0] == div2[1] - div1[cont1 - 1]) {
      r = div1[cont1 - 1] - div2[0];
    } else {
      r = div2[1] - div2[0];
    }
    termino = div2[0];
    for (i = 0; i <= cont2; i++) {
      if (termino == div2[i]) {
        termino = termino + r;
      } else {
        if (div1[cont1 - 1] == termino) {
          termino = termino + r;
          b = i;
          cont1--;
          i--;
        } else {
          invalido = 1;
          break;
        }
      }
    }
    if (invalido != 1) {
      valido = 1;
      for (i = 0; i < cont1; i++) {
        printf("%d ", div1[i]);
      }
      printf("\n");
      for (i = 0; i <= cont2; i++) {
        if (i == b) {
          printf("%d ", div1[cont1]);
          printf("%d ", div2[i]);
        } else
          printf("%d ", div2[i]);
      }
    }
  }
  return valido;
}
