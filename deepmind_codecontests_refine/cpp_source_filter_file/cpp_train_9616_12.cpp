#include <bits/stdc++.h>
int main() {
  int N;
  int a[100];
  int i;
  int k;
  int prom;
  scanf("%d\n", &N);
  for (i = 0; i < N; ++i) scanf("%d", &a[i]);
  if (a[1] % 2 == 0) prom = 1;
  if (a[2] % 2 == 0) prom += 1;
  if (a[3] % 2 == 0) prom += 1;
  if ((prom == 0) || (prom == 1)) {
    for (i = 0; i < N; ++i)
      if (a[i] % 2 == 0) k = i;
  }
  if ((prom == 2) || (prom == 3)) {
    for (i = 0; i < N; ++i)
      if (a[i] % 2 != 0) k = i;
  }
  printf("%d", k + 1);
  return 0;
}
