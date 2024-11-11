#include <bits/stdc++.h>
int N;
long long M;
long long ar[100005];
long long dp[2][100005];
int main() {
  std::cin >> N >> M;
  ar[0] = 0;
  for (int i = 1; i <= N; ++i) std::cin >> ar[i];
  ar[N + 1] = M;
  dp[0][0] = 0;
  for (int i = 1; i <= N + 1; ++i) {
    dp[0][i] = dp[0][i - 1];
    if (i % 2 == 1) dp[0][i] += ar[i] - ar[i - 1];
  }
  dp[1][N + 1] = 0;
  for (int i = N; i >= 0; --i) {
    dp[1][i] = dp[1][i + 1];
    if (i % 2 == 1) dp[1][i] += ar[i + 1] - ar[i];
  }
  long long ans = dp[0][N + 1], here;
  for (int i = 0; i <= N; ++i) {
    if (ar[i + 1] - ar[i] < 2) continue;
    here = dp[0][i] + (ar[i + 1] - ar[i] - 1) + dp[1][i + 1];
    ans = std::max(ans, here);
  }
  std::cout << ans << "\n";
  return 0;
}
