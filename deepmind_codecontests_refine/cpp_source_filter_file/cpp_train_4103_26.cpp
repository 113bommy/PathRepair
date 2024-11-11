#include <bits/stdc++.h>
using namespace std;
int row[1005];
int cmp(const void *aa, const void *bb) {
  int *a = (int *)aa;
  int *b = (int *)bb;
  return *b - *a;
}
int main() {
  int max = 0, n, m, k, k1 = 0, a, b, sum = 0;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < 1000; i++) {
    row[i] = 1000000;
  }
  while (k1 < n) {
    scanf("%d%d", &a, &b);
    if (row[a] > b) row[a - 1] = b;
    k1++;
  }
  qsort(row, m, sizeof(row[0]), cmp);
  a = 0;
  while (a < m && k > 0) {
    if (row[a] < k) {
      sum += row[a];
      k -= row[a];
      a++;
    } else {
      sum += k;
      break;
    }
  }
  printf("%d\n", sum);
  return 0;
}
