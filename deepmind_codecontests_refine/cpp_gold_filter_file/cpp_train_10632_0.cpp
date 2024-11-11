#include <bits/stdc++.h>
int aa[200010];
char bb[200010];
int cc[200010];
int compare(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int main() {
  int n, k, i, ii;
  long long sum;
  while (scanf("%d%d", &n, &k) != EOF) {
    sum = 0;
    for (i = 0; i <= (n - 1); i++) {
      if (i == (n - 1)) {
        scanf("%d\n", &aa[i]);
      } else {
        scanf("%d", &aa[i]);
      }
    }
    scanf("%s", bb);
    for (i = 0; i <= (n - 1); i++) {
      if (i == 0) {
        cc[i] = 1;
      } else if (i > 0) {
        if (bb[i] == bb[i - 1]) {
          cc[i] = cc[i - 1] + 1;
        } else {
          cc[i] = 1;
          if (cc[i - 1] <= k) {
            for (ii = (i - cc[i - 1]); ii <= (i - 1); ii++) {
              sum += aa[ii];
            }
          } else if (cc[i - 1] > k) {
            qsort(&aa[i - cc[i - 1]], cc[i - 1], sizeof(int), compare);
            for (ii = (i - cc[i - 1]); ii <= (i - cc[i - 1] + k - 1); ii++) {
              sum += aa[ii];
            }
          }
        }
      }
      if (i == (n - 1)) {
        if (cc[i] <= k) {
          for (ii = (i - cc[i] + 1); ii <= i; ii++) {
            sum += aa[ii];
          }
        } else if (cc[i] > k) {
          qsort(&aa[i - cc[i] + 1], cc[i], sizeof(int), compare);
          for (ii = (i - cc[i] + 1); ii <= (i - cc[i] + k); ii++) {
            sum += aa[ii];
          }
        }
      }
    }
    printf("%I64d\n", sum);
  }
  return 0;
}
