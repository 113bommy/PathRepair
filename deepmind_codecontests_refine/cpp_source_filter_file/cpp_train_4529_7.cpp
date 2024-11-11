#include <bits/stdc++.h>
using namespace std;
int a[1000000];
long long dp[5055][5055];
long long sum[1000000];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; ++i) {
    sum[i] = sum[i - 1] + a[i] - a[i - 1];
  }
  int sz = n / k;
  int B = n % k;
  int A = k - B;
  for (int i = 0; i <= 5000; ++i) {
    for (int j = 0; j <= 5000; ++j) {
      dp[i][j] = 1234567890;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i <= A; ++i) {
    for (int j = 0; j <= B; ++j) {
      int x = i * sz + j * (sz + 1);
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + sum[x + sz] - sum[x + 1]);
      dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + sum[x + sz + 1] - sum[x + 1]);
    }
  }
  cout << dp[A][B] << endl;
}
