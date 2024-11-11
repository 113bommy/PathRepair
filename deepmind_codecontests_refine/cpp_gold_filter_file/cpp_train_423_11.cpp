#include <bits/stdc++.h>
using namespace std;
long long dp[505][505] = {0};
void initial(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 1; k <= (n - i); k++) {
        dp[i + k][max(k, j)] = (dp[i + k][max(k, j)] + dp[i][j]) % 998244353;
      }
    }
  }
}
long long cal(int n, int k) {
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i * j < k) ans += dp[n][i] * dp[n][j] % 998244353, ans %= 998244353;
    }
  }
  return ans;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  ;
  dp[0][0] = 1;
  int n;
  int k;
  cin >> n >> k;
  initial(n);
  cout << 2 * cal(n, k) % 998244353 << "\n";
  return 0;
}
