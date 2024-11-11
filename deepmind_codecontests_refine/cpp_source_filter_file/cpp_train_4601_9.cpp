#include <bits/stdc++.h>
using namespace std;
int n, sum;
const int N = 5e5 + 5;
const long long mod = 1e9 + 7;
long long a[N], b[N];
long long dp[N][10];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 2; j++) {
        dp[i][j] = 1e18 + 10;
      }
    }
    a[0] = 1e18 + 10;
    a[n + 1] = 1e18 + 10;
    int minn = 1e9;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 2; j++) {
        for (int k = 0; k <= 2; k++) {
          if (a[i] + j != a[i - 1] + k)
            dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * b[i]);
        }
      }
    }
    ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
    printf("%d\n", ans);
  }
  return 0;
}
