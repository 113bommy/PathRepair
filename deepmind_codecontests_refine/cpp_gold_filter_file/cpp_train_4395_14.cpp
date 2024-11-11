#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005, MOD = 998244353;
char ch[MAXN];
long long cnt[MAXN], dp[MAXN][MAXN];
long long KSM(long long a, long long t) {
  long long ans = 1;
  while (t) {
    if (t & 1) ans = ans * a % MOD;
    t >>= 1;
    a = a * a % MOD;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> (ch + 1);
  int n = strlen(ch + 1);
  for (int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + (ch[i] == '?');
  for (int j = 1; j <= n; j++)
    for (int i = j - 1; i; i--) {
      if (ch[i] != ')' && ch[j] != '(')
        dp[i][j] =
            (dp[i][j] + dp[i + 1][j - 1] + KSM(2, cnt[j - 1] - cnt[i])) % MOD;
      if (ch[i] != '(') dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
      if (ch[j] != ')') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
      if (ch[i] != '(' && ch[j] != ')')
        dp[i][j] = (dp[i][j] - dp[i + 1][j - 1] + MOD) % MOD;
    }
  cout << dp[1][n];
}
