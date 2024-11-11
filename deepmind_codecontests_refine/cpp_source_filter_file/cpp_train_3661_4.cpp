#include <bits/stdc++.h>
int *fun1(int n, int *v) {
  int *w, i, j, aux;
  w = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; ++i) w[i] = v[i];
  for (i = 0; i < n - 1; ++i) {
    if (w[0] < w[1]) {
      aux = w[0];
      w[0] = w[1];
    } else
      aux = w[1];
    for (j = 1; j < n - 1; ++j) w[j] = w[j + 1];
    w[n - 1] = aux;
  }
  return w;
}
void fun2(int n, int m, int *v, int sol[2]) {
  int *w, i, j, aux;
  w = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; ++i) w[i] = v[i];
  for (i = 0; i < m - 1; ++i) {
    if (w[0] < w[1]) {
      aux = w[0];
      w[0] = w[1];
    } else
      aux = w[1];
    for (j = 1; j < n - 1; ++j) w[j] = w[j + 1];
    w[n - 1] = aux;
  }
  sol[0] = w[0];
  sol[1] = w[1];
  free(w);
  return;
}
int main(void) {
  int n, q, j = 0, *v, i, *w, sol[2];
  long long int m;
  scanf("%d %d", &n, &q);
  v = (int *)malloc(n * sizeof(int));
  if (v == NULL) exit(1);
  for (i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
  }
  w = fun1(n, v);
  while (j < q) {
    scanf("%l64d", &m);
    if (n > m) {
      fun2(n, m, v, sol);
      printf("%d %d\n", sol[0], sol[1]);
    } else {
      printf("%d %d\n", w[0], w[((m - n) % (n - 1)) + 1]);
    }
    j++;
  }
  free(v);
  free(w);
  return 0;
}
