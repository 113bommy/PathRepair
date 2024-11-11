#include <bits/stdc++.h>
int main() {
  int m, n, i = 0, l, r, j, respuesta = 0, cpos, cneg, nec;
  scanf("%d", &n);
  scanf("%d", &m);
  int a[n];
  int respuestas[m];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1) {
      cpos = cpos + 1;
    } else {
      cneg = cneg + 1;
    }
  }
  i = 0;
  while (i < m) {
    respuesta = 0;
    scanf("%d%d", &l, &r);
    if ((r - l + 1) % 2 == 0) {
      nec = (r - l + 1) / 2;
      if (cpos >= nec && cneg >= nec) {
        respuesta = 1;
      }
    }
    respuestas[i] = respuesta;
    i++;
  }
  for (i = 0; i < m; i++) {
    printf("%d\n", respuestas[i]);
  }
  return 0;
}
