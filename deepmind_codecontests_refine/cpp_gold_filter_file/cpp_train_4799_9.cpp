#include <bits/stdc++.h>
using namespace std;
int a[5001];
int ans[2502][5001];
int is[2502][5001];
int min_(int i, int j) { return (i < j) ? i : j; }
int max_(int i, int j) { return (i > j) ? i : j; }
int main() {
  int n, i, j, k;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  a[n] = 0;
  for (i = 0; i < (n + 1) / 2; i++)
    for (j = 0; j < n; j++) is[i][j] = 0;
  ans[0][0] = max_(0, a[1] - a[0] + 1);
  is[0][0] = 1;
  for (i = 0, j = 1; j < n; j++) {
    k = max_(0, a[j + 1] - a[j] + 1) + max_(0, a[j - 1] - a[j] + 1);
    if (k <= ans[i][j - 1]) {
      ans[i][j] = k;
      is[i][j] = 1;
    } else {
      ans[i][j] = ans[i][j - 1];
    }
  }
  for (i = 1; i < (n + 1) / 2; i++) {
    j = 2 * i;
    ans[i][j] = ans[i - 1][j - 2] + max_(0, a[j + 1] - a[j] + 1) +
                max_(0, min_(a[j - 2] - 1, a[j - 1]) - a[j] + 1);
    is[i][j] = 1;
    for (j = 2 * i + 1; j < n; j++) {
      if (is[i - 1][j - 2] == 1) {
        k = ans[i - 1][j - 2] + max_(0, a[j + 1] - a[j] + 1) +
            max_(0, min_(a[j - 2] - 1, a[j - 1]) - a[j] + 1);
      } else {
        k = ans[i - 1][j - 2] + max_(0, a[j + 1] - a[j] + 1) +
            max_(0, a[j - 1] - a[j] + 1);
      }
      if (k <= ans[i][j - 1]) {
        ans[i][j] = k;
        is[i][j] = 1;
      } else {
        ans[i][j] = ans[i][j - 1];
      }
    }
  }
  for (i = 0; i < (n + 1) / 2; i++) printf("%d ", ans[i][n - 1]);
  return 0;
}
