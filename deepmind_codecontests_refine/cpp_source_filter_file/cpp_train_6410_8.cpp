#include <bits/stdc++.h>
using namespace std;
long long arr[1000009];
long long dp[1000][1000];
int main() {
  long long n, m, k, x, y;
  cin >> n >> m >> k >> x >> y;
  long long val = 0;
  if (n == 1)
    val = m;
  else
    val = (2 * (n - 1)) * m;
  long long res = k / val;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] += res;
      if (i != n && i != 1) dp[i][j] += res;
    }
  }
  k = k % val;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (k) {
        k--;
        dp[i][j]++;
      }
    }
  }
  for (int i = n - 1; i > 1; i--) {
    for (int j = 1; j < m; j++) {
      if (k) {
        k--;
        dp[i][j]++;
      }
    }
  }
  int l = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      arr[l] = dp[i][j];
      l++;
    }
  }
  sort(arr, arr + l);
  cout << arr[l - 1] << " " << arr[0] << " " << dp[x][y] << endl;
  return 0;
}
