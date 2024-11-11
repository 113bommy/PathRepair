#include <bits/stdc++.h>
using namespace std;
long long n, m, dp[5][5][5][55];
string str[100];
long long rec(bool digit, bool alpha, bool chr, long long pos) {
  if (pos >= n) {
    if (digit && alpha && chr)
      return 0;
    else
      return 1000000007;
  }
  if (dp[digit][alpha][chr][pos] != -1) return dp[digit][alpha][chr][pos];
  long long ans = 1000000007;
  for (int i = 0; i < m; i++) {
    bool tmp1 = digit, tmp2 = alpha, tmp3 = chr;
    if (str[pos][i] >= '1' && str[pos][i] <= '9')
      tmp1 = true;
    else if (str[pos][i] >= 'a' && str[pos][i] <= 'z')
      tmp2 = true;
    else
      tmp3 = true;
    ans = min(ans, (min((long long)i, m - i) + rec(tmp1, tmp2, tmp3, pos + 1)));
  }
  return dp[digit][alpha][chr][pos] = ans;
}
int main() {
  scanf("%lld %lld", &n, &m);
  for (int i = 0; i < n; i++) cin >> str[i];
  memset(dp, -1, sizeof dp);
  printf("%lld\n", rec(false, false, false, 0));
  return 0;
}
