#include <bits/stdc++.h>
using namespace std;
int A[105][105] = {-1};
int arr[105];
int res[105];
int main() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) arr[i] = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) scanf("%d", &A[i][j]);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      if (i == j) continue;
      if (A[i][j] == 3) {
        arr[i] = 2;
        arr[j] = 2;
      }
      if (i == j || A[i][j] == -1 || (arr[i] == 2 || arr[j] == 2)) continue;
      if (A[i][j] == 1) {
        arr[i] = 1;
        A[j][i] = -1;
      }
      if (A[i][j] == 2) {
        arr[j] = 1;
        A[i][j] = -1;
      }
    }
  int k = 0;
  for (i = 0; i < n; i++)
    if (arr[i] == 0) res[k++] = i + 1;
  sort(res, res + k);
  printf("%d\n", k);
  for (i = 0; i < k; i++) {
    printf("%d", res[i]);
    if (i < k - 1) printf(" ");
  }
  return 0;
}
