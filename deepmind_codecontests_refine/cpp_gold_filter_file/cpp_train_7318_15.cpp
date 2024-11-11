#include <bits/stdc++.h>
using namespace std;
int arr[111][111] = {0};
int sum[111];
int sr[111][111];
int ans[111][11111];
int main() {
  int n, m, i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 0; i < 111; i++)
    for (j = 0; j < 111; j++) sr[i][j] = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i][0]);
    for (j = 1; j < arr[i][0] + 1; j += 1) scanf("%d", &arr[i][j]);
    sum[0] = 0;
    for (j = 1; j < arr[i][0] + 1; j += 1) sum[j] = sum[j - 1] + arr[i][j];
    for (j = 0; j < arr[i][0] + 1; j++) {
      for (k = 0; k < arr[i][0] + 1; k++) {
        if (j + k > arr[i][0]) break;
        sr[i][j + k] =
            max(sr[i][j + k], sum[k] + sum[arr[i][0]] - sum[arr[i][0] - (j)]);
      }
    }
  }
  for (i = 0; i < 100; i++)
    for (j = 0; j < 11111; j++) ans[i][j] = 0;
  ans[0][0] = 0;
  for (i = 0; i < arr[0][0]; i++) ans[0][i + 1] = sr[0][i + 1];
  for (i = 1; i < n; i += 1) {
    for (j = 0; j < arr[i][0] + 1; j++) {
      for (k = 0; k < m + 1; k++) {
        if (j + k > m) break;
        ans[i][j + k] = max(ans[i][j + k], sr[i][j] + ans[i - 1][k]);
      }
    }
  }
  int as = 0;
  for (i = 0; i < m + 1; i++) as = max(as, ans[n - 1][i]);
  printf("%d", as);
  return 0;
}
