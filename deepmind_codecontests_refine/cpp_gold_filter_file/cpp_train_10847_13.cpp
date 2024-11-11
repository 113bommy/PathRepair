#include <bits/stdc++.h>
using namespace std;
long long dp[35][2][2];
long long a, b;
long long dfs(int pos, int la, int lb) {
  if (pos < 0) return 1;
  if (dp[pos][la][lb] != -1) return dp[pos][la][lb];
  int upa = la ? ((a >> pos) & 1) : 1;
  int upb = lb ? ((b >> pos) & 1) : 1;
  long long ans = 0;
  for (int i = 0; i <= upa; ++i) {
    for (int j = 0; j <= upb; ++j) {
      if (i + j == 2) continue;
      ans += dfs(pos - 1, la && i == upa, lb && j == upb);
    }
  }
  dp[pos][la][lb] = ans;
  return ans;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long l, r;
    cin >> l >> r;
    if (l == 0) {
      memset(dp, -1, sizeof dp);
      a = b = r;
      printf("%I64d\n", dfs(32, 1, 1));
      continue;
    }
    long long ans = 0;
    a = b = r;
    memset(dp, -1, sizeof dp);
    ans += dfs(32, 1, 1);
    a = r;
    b = l - 1;
    memset(dp, -1, sizeof dp);
    ans -= dfs(32, 1, 1) * 2;
    a = b = l - 1;
    memset(dp, -1, sizeof dp);
    ans += dfs(32, 1, 1);
    printf("%I64d\n", ans);
  }
}
