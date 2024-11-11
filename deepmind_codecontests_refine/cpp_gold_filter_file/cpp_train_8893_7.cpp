#include <bits/stdc++.h>
long long MOD = 1e9 + 7;
int N, K, D;
long long dp[101][2];
long long solve(long long w, int s) {
  if (dp[w][s] != -1)
    return dp[w][s];
  else if (w > N)
    return 0;
  else if (w == N and s)
    return 1;
  long long ans = 0;
  for (int k = 1; k <= K and w + k <= N; ++k)
    ans = (ans + solve(w + k, s || (k >= D))) % MOD;
  return dp[w][s] = ans;
}
int main() {
  std::cin >> N >> K >> D;
  memset(dp, -1, sizeof(dp));
  long long ans = 0;
  for (int k = 1; k <= K; ++k) ans = (ans + solve(k, k >= D)) % MOD;
  std::cout << ans << "\n";
  return 0;
}
