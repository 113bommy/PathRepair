#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int dp[1001][101][2];
int pows[1010];
int DP(int pos, int val, int flag) {
  if (pos == n + 1) return flag;
  if (dp[pos][val][flag] != -1) return dp[pos][val][flag];
  int minn = (pos == n) ? 1 : 0;
  int ans = 0;
  for (int i = minn; i <= 9; ++i) {
    ans += DP(pos + 1, (val + i * pows[pos]) % k,
              flag | (((val + i * pows[pos]) % k == 0) && (val || i)));
    ans %= m;
  }
  return dp[pos][val][flag] = ans;
}
int main() {
  cin >> n >> k >> m;
  pows[1] = 1;
  memset(dp, -1, sizeof(dp));
  for (int i = 2; i <= n; ++i) {
    pows[i] = (pows[i - 1] * 10) % k;
  }
  cout << DP(1, 0, 0);
  return 0;
}
