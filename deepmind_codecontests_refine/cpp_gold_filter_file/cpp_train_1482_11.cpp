#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int arr[55][20005];
int sum[55][20005];
int dp[55][20005];
int mat[55][20005];
int max_r[20005];
int max_l[20005];
int main() {
  ios::sync_with_stdio(false);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &arr[i][j]);
      sum[i][j] = arr[i][j];
    }
    for (int j = 1; j < m; j++) sum[i][j] += sum[i][j - 1];
  }
  int temp;
  for (int i = 0; i < n; i++) {
    temp = 0;
    for (int j = 0; j < m; j++) {
      temp += arr[i][j];
      if (j >= k) temp -= arr[i][j - k];
      mat[i][j] = temp;
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = 0; j < m; j++) {
      mat[i][j] += mat[i - 1][j];
    }
  }
  int ans, r;
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 0; j < m; j++) max_r[j] = max_l[j] = mat[i + 1][j];
    for (int j = k; j < m; j++) max_l[j] = max(max_l[j], max_l[j - 1]);
    for (int j = m - 1; j >= k - 1; j--) max_r[j] = max(max_r[j], max_r[j + 1]);
    for (int j = k - 1; j < m; j++) {
      ans = 0;
      if (j - k >= k - 1) ans = max(ans, mat[i][j] + max_l[j - k]);
      if (j + k < m) {
        ans = max(ans, mat[i][j] + max_r[j + k]);
      }
      for (int p = j - k + 1; j < m && p < j + k; p++) {
        if (p < k - 1) continue;
        temp = mat[i][j] + mat[i + 1][p];
        r = min(p, j);
        temp -= sum[i][r];
        r = max(j - k + 1, p - k + 1);
        if (r > 0) temp += sum[i][r - 1];
        ans = max(ans, temp);
      }
      mat[i][j] = ans;
    }
  }
  ans = 0;
  for (int i = k - 1; i < m; i++) ans = max(ans, mat[1][i]);
  cout << ans << endl;
  return 0;
}
