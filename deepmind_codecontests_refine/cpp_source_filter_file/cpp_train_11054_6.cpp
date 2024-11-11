#include <bits/stdc++.h>
long long dp[1100005];
int f[25][25];
int a[400005];
int num[25];
int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    num[a[i]]++;
    for (int j = 1; j <= 20; j++) {
      if (a[i] != j) f[a[i]][j] += num[j];
    }
  }
  for (int i = 1; i < (1 << 20); i++) dp[i] = (long long)1 << 60;
  for (int i = 1; i < (1 << 20); i++) {
    for (int j = 1; j <= 20; j++) {
      if (i & (1 << (j - 1))) {
        long long temp = i ^ (1 << (j - 1));
        long long res = 0;
        for (int k = 1; k <= 20; k++) {
          if (temp & (1 << (k - 1))) {
            res += f[j][k];
          }
        }
        dp[i] = std::min(dp[i], dp[temp] + res);
      }
    }
  }
  std::cout << dp[(1 << 20) - 1] << std::endl;
}
