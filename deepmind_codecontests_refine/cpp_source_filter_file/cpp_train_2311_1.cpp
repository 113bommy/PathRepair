#include <bits/stdc++.h>
using i64 = long long;
int main() {
  int b[10][10];
  for (int i = 9; i >= 0; i--)
    for (int j = 0; j < 10; j++) std::cin >> b[i][j];
  double dp[100], dp2[100];
  auto get = [](int n) {
    int r = n / 10;
    if (r % 2)
      return std::make_pair(r, 9 - n % 10);
    else
      return std::make_pair(r, n % 10);
  };
  auto inv = [](int r, int c) {
    if (r % 2)
      return r * 10 + 9 - c;
    else
      return r * 10 + c;
  };
  for (int i = 98; i >= 0; i--) {
    if (i >= 94) {
      dp[i] = dp2[i] = 6;
      continue;
    }
    auto [r, c] = get(i);
    double s = 0;
    for (int j = 1; j <= 6; j++) {
      s += dp[i + j];
    }
    s = s / 6.0 + 1;
    dp2[i] = s;
    if (b[r][c]) {
      int a = b[r][c];
      s = std::min(s, dp2[inv(r + a, c)]);
    }
    dp[i] = s;
  }
  std::cout << std::fixed << std::setprecision(10) << dp[0] << std::endl;
  return 0;
}
