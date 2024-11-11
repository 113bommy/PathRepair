#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  scanf("%d", &n);
  int ar[101][101];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &ar[i][j]);
    }
  }
  int sum = 0, x;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        sum = sum + ar[i][j];
      }
      if (i + j == n + 1) {
        sum = sum + ar[i][j];
      }
      if (i + j == n - 1 && i == j) {
        x = ar[i][j];
      }
      if (i == (n - 1) / 2 || j == (n - 1) / 2) {
        sum = sum + ar[i][j];
      }
    }
  }
  printf("%d", sum - 2 * x);
}
