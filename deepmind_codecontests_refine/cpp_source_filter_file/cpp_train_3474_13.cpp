#include <bits/stdc++.h>
using namespace std;
int m, n, k;
long long int arr[1005][1005];
long long int sum[1005][1005];
long long int dp[1005][1005];
int main() {
  cin >> m >> n >> k;
  for (long long int i = 1; i <= m; i++)
    for (long long int j = 1; j <= n; j++) {
      int x;
      scanf("%d", &x);
      arr[i][j] = x;
      sum[i][j] = sum[i][j - 1] + x;
    }
  int x, y;
  long long int r, res = -1;
  for (long long int j = k; j <= n - k + 1; j++) {
    for (long long int i = 1; i <= n; i++) {
      dp[i][0] = arr[i][j];
      for (long long int l = 1; l <= k - 1; l++)
        dp[i][l] = dp[i][l - 1] + sum[i][j + l] - sum[i][max(j - l - 1, 0LL)];
    }
    for (long long int i = k; i <= m - k + 1; i++) {
      r = 0;
      for (long long int l = i - k + 1; l <= i + k - 1; l++)
        r += dp[l][k - 1 - abs(i - l)];
      if (r > res) {
        res = r;
        x = i;
        y = j;
      }
    }
  }
  cout << x << " " << y << endl;
}
