#include <bits/stdc++.h>
using namespace std;
int n;
int ans[150][150];
int main() {
  scanf("%d", &n);
  int num = 0;
  int k;
  for (int i = 0;; i++) {
    num += i;
    if (num + i + 1 > n) {
      k = i;
      break;
    }
  }
  printf("%d\n", k + 1);
  for (int j = 1; j <= k; j++) ans[0][j] = j;
  for (int i = 1; i < k + 1; i++) {
    int j = 1;
    for (j = 1; j <= i; j++) ans[i][j] = ans[j - 1][i];
    if (j <= k) ans[i][j++] = ans[i - 1][k] + 1;
    for (; j <= k; j++) ans[i][j] = ans[i][j - 1] + 1;
  }
  for (int i = 0; i < k + 1; i++) {
    for (int j = 1; j <= k; j++) printf("%d ", ans[i][j]);
    printf("\n");
  }
  return 0;
}
