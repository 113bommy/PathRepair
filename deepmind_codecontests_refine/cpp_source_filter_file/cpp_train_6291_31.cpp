#include <bits/stdc++.h>
using namespace std;
int k[110], m[110][110];
int main(void) {
  int n, min, i, j, sum;
  while (scanf("%d", &n) == 1) {
    for (i = 0; i < n; i++) {
      scanf("%d", &k[i]);
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < k[i]; j++) {
        scanf("%d", &m[i][j]);
      }
    }
    min = 20000;
    for (i = 0; i < n; i++) {
      sum = 0;
      for (j = 0; j < k[i]; j++) {
        sum += m[i][j] * 5;
      }
      sum += k[i] * 15;
      if (sum < min) {
        min = sum;
      }
    }
    printf("%d\n", min);
  }
  return 0;
}
