#include <bits/stdc++.h>
using namespace std;
long long dp[1012][1012][2];
int k, t, lmax;
char s[1200], in[1200];
long long dfs(int pos, int last, int st, int state) {
  if (pos < 1) {
    return st == 1;
  }
  if (!state && dp[pos][last][st] != -1) return dp[pos][last][st];
  int u = state ? s[pos] - '0' : 9;
  long long ans = 0;
  for (int i = 0; i <= u; i++) {
    if (i == 4 || i == 7) {
      ans += dfs(pos - 1, pos, (pos - last <= k && last) | st, state && i == u);
    } else
      ans += dfs(pos - 1, last, st, state && i == u);
  }
  ans %= 1000000007LL;
  if (state == 0) dp[pos][last][st] = ans;
  return ans;
}
int main() {
  scanf("%d%d", &t, &k);
  memset(dp, -1, sizeof(dp));
  int q;
  while (t--) {
    scanf("%s", in);
    lmax = strlen(in);
    q = 1;
    for (int i = lmax - 1; i >= 0; i--) s[q++] = in[i];
    long long s1 = dfs(lmax, 0, 0, 1);
    long long ans = 0;
    int p = -3000;
    for (int i = 0; i < lmax; i++) {
      if (in[i] == '4' || in[i] == '7') {
        if (i - p <= k) {
          ans = 1;
          break;
        } else
          p = i;
      }
    }
    scanf("%s", in);
    lmax = strlen(in);
    q = 1;
    for (int i = lmax - 1; i >= 0; i--) s[q++] = in[i];
    long long s2 = dfs(lmax, 0, 0, 1);
    long long q = s2 - s1 - ans;
    if (q < 0) q += 1000000007;
    printf("%lld\n", q);
  }
}
