#include <bits/stdc++.h>
using namespace std;
long long int n, m, k, dp[1100][1100];
long long int solve(int left, int kleft) {
  if (kleft == 0 and left > 0)
    return 1;
  else if (left <= 0)
    return 0;
  if (dp[left][kleft] != -1) return dp[left][kleft];
  dp[left][kleft] = 0;
  long long int curr = 1;
  for (int j = left - 2; j >= 1; j--) {
    dp[left][kleft] += (curr * solve(j, kleft - 1)) % 1000000007;
    dp[left][kleft] %= 1000000007;
    curr++;
  }
  return dp[left][kleft];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  if (k > 2 * n or 2 * m) {
    cout << 0 << "\n";
    return 0;
  }
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) dp[i][j] = -1;
  }
  solve(n, k);
  solve(m, k);
  long long int ans = (dp[n][k] * dp[m][k]) % 1000000007;
  cout << ans << "\n";
}
