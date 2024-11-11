#include <bits/stdc++.h>
const int NMAX = 2e3;
int a[1 + NMAX];
int dp[1 + NMAX][1 + NMAX];
int main() {
  int tests;
  std::cin >> tests;
  while (tests--) {
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 0; i <= n; ++i) {
      for (int del = 0; del <= k; ++del) dp[i][del] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = dp[i - 1][0] + (a[i] == i);
      for (int del = 1; del <= i; ++del)
        dp[i][del] =
            std::max(dp[i - 1][del - 1], dp[i - 1][del] + (a[i] == i - del));
    }
    bool found = false;
    for (int del = 0; del <= n; ++del) {
      if (dp[n][del] >= k) {
        std::cout << del << '\n';
        found = true;
        break;
      }
    }
    if (!found) std::cout << "-1\n";
  }
  return 0;
}
