#include <bits/stdc++.h>
long long list[500];
long long dp[50000][100];
long long calc(long long n, int k) {
  if (k == 0) return n;
  if (n < 50000)
    return dp[n][k] == -1
               ? dp[n][k] = calc(n, k - 1) - calc(n / list[k - 1], k - 1)
               : dp[n][k];
  return calc(n, k - 1) - calc(n / list[k - 1], k - 1);
}
int main() {
  memset(dp, 0xff, sizeof(dp));
  long long n;
  int k;
  std::cin >> n >> k;
  for (int i = 0; i < k; ++i) std::cin >> list[i];
  std::sort(list, list + k);
  std::cout << calc(n, k) << "\n";
}
