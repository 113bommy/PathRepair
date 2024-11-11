#include <bits/stdc++.h>
struct xxx {
  int a, b, num, num2;
} x[111111];
int ans[111111], pp = 0;
int comp1(const void *m, const void *n) {
  return (*(struct xxx *)n).b - (*(struct xxx *)m).b;
}
int comp2(const void *m, const void *n) {
  return (*(struct xxx *)n).a - (*(struct xxx *)m).a;
}
int comp3(const void *m, const void *n) {
  return (*(struct xxx *)m).a - (*(struct xxx *)n).a;
}
int comp4(const void *m, const void *n) {
  return (*(struct xxx *)m).num2 - (*(struct xxx *)n).num2;
}
int main() {
  int n, p, k;
  pp = 0;
  scanf("%d%d%d", &n, &p, &k);
  for (int i = 0; i < n; i++) scanf("%d%d", &x[i].a, &x[i].b), x[i].num = i + 1;
  qsort(x, n, sizeof(x[0]), comp1);
  for (int i = 0; i < n; i++) {
    int j;
    for (j = i + 1; x[j].b == x[i].b; j++)
      ;
    qsort(x + i, j - i, sizeof(x[0]), comp3);
    i = j - 1;
  }
  for (int i = 0; i < n; i++) x[i].num2 = i + 1;
  qsort(x, n - (p - k), sizeof(x[0]), comp2);
  int i, j, max = 0;
  for (i = k; i < n && x[i].a == x[i - 1].a; i++)
    ;
  for (j = k - 2; j >= 0 && x[j].a == x[j + 1].a; j--)
    ;
  qsort(x + j + 1, i - j - 1, sizeof(x[0]), comp4);
  for (int i = 0; i < k; i++) {
    ans[pp++] = x[i].num;
    if (x[i].num2 > max) max = x[i].num2;
  }
  for (int i = k; i < n; i++)
    if (x[i].num2 > max && x[i].num2 <= max + p - k) ans[pp++] = x[i].num;
  for (int i = 0; i < pp; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
