#include <bits/stdc++.h>
int main() {
  int k, l, m, n, d, i, damage = 0;
  scanf("%d %d %d %d %d", &k, &l, &m, &n, &d);
  int dragon[d];
  for (i = 0; i < d; i++) dragon[i] = 0;
  for (i = 1; i * k <= d; i++) dragon[i * k - 1] = 1;
  for (i = 1; i * l <= d; i++) dragon[i * l - 1] = 1;
  for (i = 1; i * m < d; i++) dragon[i * m - 1] = 1;
  for (i = 1; i * n <= d; i++) dragon[i * n - 1] = 1;
  for (i = 0; i < d; i++) {
    if (dragon[i] == 1) damage++;
  }
  printf("%d\n", damage);
}
