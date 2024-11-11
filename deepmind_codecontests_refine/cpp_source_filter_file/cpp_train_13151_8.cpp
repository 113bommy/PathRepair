#include <bits/stdc++.h>
int main(void) {
  int n, a, d;
  int *t, *v;
  double *ans;
  int i, j;
  double x, doc;
  scanf("%d %d %d", &n, &a, &d);
  t = (int *)calloc(n, sizeof(int));
  v = (int *)calloc(n, sizeof(int));
  ans = (double *)calloc(n, sizeof(double));
  for (i = 0; i < n; i++) {
    scanf("%d %d", (t + i), (v + i));
  }
  for (i = 0; i < n; i++) {
    if ((double)v[i] * v[i] / (2 * a) + t[i] > d) {
      *(ans + i) = sqrt(2 * (double)d / a) + t[i];
    } else {
      *(ans + i) = (d + (double)v[i] * v[i] / (2 * a)) / v[i] + t[i];
    }
  }
  for (i = 1; i < n; i++) {
    if (*(ans + i) < *(ans + i - 1)) {
      *(ans + i) = *(ans + i - 1);
    }
  }
  for (i = 0; i < n; i++) {
    printf("%.10f\n", *(ans + i));
  }
  free(t);
  free(v);
  free(ans);
  return 0;
}
