#include <bits/stdc++.h>
using namespace std;
long long int n, m, c0, d0;
long long int dp[1005][1005];
long long int fun(long long int n, long long int i, long long int a[][3]) {
  if (n <= 0 || i == m) {
    return 0;
  }
  if (dp[n][i] != -1) {
    return dp[n][i];
  }
  long long int mx = 0;
  for (long long int j = 0; j <= a[i][0]; j++) {
    if ((n - a[i][1] * j) >= 0) {
      mx = max(mx, j * a[i][2] + fun(n - a[i][1] * j, i + 1, a));
    }
  }
  dp[n][i] = mx;
  return mx;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(dp, -1, sizeof(dp));
  long long int i, x, y;
  cin >> n >> m >> c0 >> d0;
  m++;
  long long int a[m][3];
  a[0][0] = 1005;
  a[0][1] = c0;
  a[0][2] = d0;
  for (i = 1; i < m; i++) {
    cin >> x >> y;
    a[i][0] = x / y;
    cin >> a[i][1] >> a[i][2];
  }
  cout << fun(n, 0, a);
}
