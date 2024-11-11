#include <bits/stdc++.h>
using namespace std;
const int K = 5005, M = 998244353;
int dp[K][K];
long long power(long long a, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * a) % M;
    a = (a * a) % M;
    p >>= 1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  dp[0][0] = 1;
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < i; j++) {
      dp[i][j] += 1LL * dp[i - 1][j] * j;
      dp[i][j + 1] += 1LL * dp[i - 1][j] * (n - j);
    }
    for (int j = 0; j <= i; j++) dp[i][j] %= M;
  }
  int pr = 1, b = power(m, M - 2), ans = 0;
  for (int i = 1; i <= k; i++) {
    pr = (1LL * pr * b) % M;
    ans = (ans + pr * dp[k][i]) % M;
  }
  cout << ans << endl;
}
