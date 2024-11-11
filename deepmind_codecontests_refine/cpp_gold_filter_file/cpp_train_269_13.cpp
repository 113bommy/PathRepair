#include <bits/stdc++.h>
const long double inf = 1e13;
const long double max_x = 5e8;
const long double eps = 1e-9;
int n, r;
std::vector<long double> prob;
std::vector<int> fast, slow;
std::vector<std::vector<int> > used;
std::vector<std::vector<long double> > dp;
long double get_dp(int i, int j) {
  if (j < 0) return dp[0][r];
  if (used[i][j] == 1) {
    return dp[i][j];
  } else {
    if (i != n) {
      dp[i][j] =
          std::min(dp[0][r], prob[i] * (fast[i] + get_dp(i + 1, j - fast[i])) +
                                 (1.0 - prob[i]) *
                                     (slow[i] + get_dp(i + 1, j - slow[i])));
    } else {
      dp[i][j] = 0;
    }
    used[i][j] = 1;
    return dp[i][j];
  }
}
int main() {
  std::cin >> n >> r;
  fast.resize(n);
  slow.resize(n);
  prob.resize(n);
  for (size_t i = 0; i < n; ++i) {
    int temp_p;
    std::cin >> fast[i] >> slow[i] >> temp_p;
    prob[i] = 0.01 * temp_p;
  }
  long double lx = 0, rx = max_x, mx;
  while (rx - lx > eps) {
    mx = (lx + rx) / 2.0;
    dp.assign(n + 1, std::vector<long double>(r + 1, -1));
    used.assign(n + 1, std::vector<int>(r + 1, 0));
    used[0][r] = 1;
    dp[0][r] = mx;
    long double calc = prob[0] * (fast[0] + get_dp(1, r - fast[0])) +
                       (1.0 - prob[0]) * (slow[0] + get_dp(1, r - slow[0]));
    if (calc < mx) {
      rx = mx;
    } else {
      lx = mx;
    }
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(14) << lx << std::endl;
  return 0;
}
