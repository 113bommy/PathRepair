#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, cons = 0, i, j;
  int a[205][205];
  scanf("%d", &k);
  if (k % 2 == 0) {
    printf("NO\n");
  } else {
    printf("YES\n");
    if (k == 1)
      printf("2 1\n1 2\n");
    else {
      printf("%d %d\n", (2 * (k + 2)), ((k * k) + (3 * k)) - 3);
      for (i = 0; i < 205; ++i) {
        for (j = 0; j < 205; ++j) a[i][j] = 0;
      }
      for (i = 1; i < k; ++i) {
        a[0][i] = 1;
      }
      for (i = 1; i < k; ++i) {
        for (j = i + 1; j < k; ++j) {
          a[i][j] = 1;
        }
      }
      for (i = 1; i < k; i = i + 2) a[i][i + 1] = 0;
      for (i = 1; i < k; ++i) {
        a[i][k] = 1;
        a[i][k + 1] = 1;
      }
      a[k][k + 1] = 1;
      cons = k + 2;
      for (i = 0; i <= k + 1; ++i) {
        for (j = 0; j <= k + 1; ++j) {
          if (a[i][j] == 1) printf("%d %d\n", i + 1, j + 1);
        }
      }
      printf("1 %d\n", k + 3);
      for (i = 0; i <= k + 1; ++i) {
        for (j = 0; j <= k + 1; ++j) {
          if (a[i][j] == 1) printf("%d %d\n", (i + 1 + cons), (j + 1 + cons));
        }
      }
    }
  }
  return 0;
}
