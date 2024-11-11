#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int a[1005];
long long dp[1005][1005][5];
int k;
long long dfs(int pos, int pre, int sta, bool limit) {
  if (pos < 0) return sta;
  if (!limit && dp[pos][pre][sta] != -1) return dp[pos][pre][sta];
  int up = limit ? a[pos] : 9;
  long long tmp = 0;
  for (int i = 0; i <= up; i++) {
    if (i == 4 || i == 7)
      tmp = (tmp + dfs(pos - 1, pos, sta || (pre != -1 && abs(pre - pos) <= k),
                       limit && i == up)) %
            MOD;
    else
      tmp = (tmp + dfs(pos - 1, pre, sta, limit && i == up)) % MOD;
  }
  if (!limit) dp[pos][pre][sta] = tmp;
  return tmp;
}
long long DP(char *s) {
  int l = strlen(s);
  for (int i = 0; i <= l - 1; i++) a[l - i - 1] = s[i] - '0';
  return dfs(l - 1, -1, 0, true);
}
char le[1005], ri[1005];
void solve() {
  memset(dp, -1, sizeof(dp));
  int t;
  scanf("%d%d", &t, &k);
  while (t--) {
    scanf("%s%s", le, ri);
    int p = 0;
    int l = strlen(le);
    int q = -1;
    for (int i = 0; i <= l - 1; i++) {
      if (le[i] == '4' || le[i] == '7') {
        if (q == -1 || abs(i - q) > k)
          q = i;
        else {
          p = 1;
          break;
        }
      }
    }
    printf("%lld\n", ((DP(ri) - DP(le) + p) % MOD + MOD) % MOD);
  }
}
int main() {
  solve();
  return 0;
}
