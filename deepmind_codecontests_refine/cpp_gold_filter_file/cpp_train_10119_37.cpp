#include <bits/stdc++.h>
using namespace std;
long i, j, arr[9], k, n, mejor, masmejor, p[9];
char per[9][9], tem[9][9];
int main() {
  masmejor = 999999999;
  scanf("%ld%ld", &n, &k);
  for (i = 0; i < k; i++) p[i] = i + 1;
  for (i = 0; i < n; i++) scanf("%s", &per[i]);
  do {
    for (i = 0; i < n; i++) {
      for (j = 0; j < k; j++) {
        tem[i][j] = per[i][p[j] - 1];
      }
      arr[i] = atol(tem[i]);
    }
    sort(arr, arr + n);
    mejor = arr[n - 1] - arr[0];
    if (mejor < masmejor) masmejor = mejor;
  } while (next_permutation(p, p + k));
  printf("%ld\n", masmejor);
}
