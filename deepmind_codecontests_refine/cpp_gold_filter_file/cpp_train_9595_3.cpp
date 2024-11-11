#include <bits/stdc++.h>
const int MOD = 998244353;
int n, k;
std::vector<int> A;
int binco[1005][1005];
int dp[1005][1005], dp2[1005][1005];
int get(int r) {
  if ((k - 1) * r > 100005) return 0;
  for (int i = 0; i < (n + 1); ++i) {
    for (int j = 0; j < (k + 1); ++j) {
      dp[i][j] = 0;
      dp2[i][j] = 0;
    }
  }
  std::vector<int> next(n);
  int right = 0;
  for (int i = 0; i < (n); ++i) {
    while (right < n && A[right] - A[i] < r) right++;
    next[i] = right;
  }
  int ans = 0;
  dp[n][0] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = (0); j < (k + 1); ++j) {
      dp[i][j] = ((j == 0 ? 0 : dp[next[i]][j - 1]) + dp[i + 1][j]) % MOD;
    }
  }
  return dp[0][k];
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> k;
  A.resize(n);
  for (int i = 0; i < (n); ++i) std::cin >> A[i];
  std::sort(A.begin(), A.end());
  int ans = 0;
  for (int i = (1); i < (100002); ++i) ans = (ans + get(i)) % MOD;
  std::cout << ans;
  return 0;
}
