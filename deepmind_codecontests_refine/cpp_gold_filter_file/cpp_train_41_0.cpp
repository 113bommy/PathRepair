#include <bits/stdc++.h>
using namespace std;
int a[20][20], i, j, k, sk[20], tp;
int main() {
  scanf("%d", &k);
  for (i = 1; i < k; i++) a[i][1] = a[1][i] = i;
  for (i = 2; i < k; i++)
    for (j = 2; j < k; j++) a[i][j] = a[i][1] * a[1][j];
  for (i = 1; i < k; i++) {
    for (j = 1; j < k; j++) {
      tp = 0;
      while (a[i][j] > 0) {
        ++tp;
        sk[tp] = a[i][j] % k;
        a[i][j] /= k;
      }
      while (tp > 0) {
        printf("%d", sk[tp]);
        tp--;
      }
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}
