#include <bits/stdc++.h>
using namespace std;
int dp[3009][4];
int a[3009];
int b[3009];
int c[3009];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
  dp[0][0] = a[0];
  dp[0][2] = b[0];
  for (int i = 1; i < n; ++i) {
    dp[i][0] = a[i] + std::max(dp[i - 1][2], dp[i - 1][3]);
    dp[i][1] = b[i] + std::max(dp[i - 1][0], dp[i - 1][1]);
    dp[i][2] = b[i] + std::max(dp[i - 1][2], dp[i - 1][3]);
    dp[i][3] = c[i] + std::max(dp[i - 1][0], dp[i - 1][1]);
  }
  printf("%d\n", std::max(dp[n - 1][0], dp[n - 1][2]));
  return 0;
}
