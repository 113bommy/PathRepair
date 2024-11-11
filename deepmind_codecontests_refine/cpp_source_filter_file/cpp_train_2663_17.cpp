#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, MOD = 1e9 + 7;
long long int n, m, dp[N], cost[30], mc = 1e9, answer = 1;
int ml;
char arr[N];
long long int calc(int sn) {
  if (dp[sn] != -1) {
    return dp[sn];
  } else {
    int mcost = 1e9, ans = 0;
    for (int i = sn, len = 1; i < n; i++, len++) {
      if (cost[(int)arr[i] - 'a'] < mcost) {
        mcost = cost[(int)arr[i] - 'a'];
      }
      if (len > mcost) {
        return dp[sn] = ans % MOD;
      } else {
        ml = max(len, ml);
        if (sn + len < n) {
          ans += (calc(sn + len));
          ans %= MOD;
        }
      }
    }
    return dp[sn] = (ans + 1) % MOD;
  }
}
int main() {
  scanf("%lld", &n);
  scanf(" %s", &arr);
  memset(dp, -1, sizeof(dp));
  dp[n - 1] = 1;
  for (int i = 0; i < 26; i++) {
    scanf("%lld", &cost[i]);
  }
  printf("%lld\n", (calc(0) % MOD));
  for (int i = 0, l = 1; i < n; i++, l++) {
    if (cost[(int)arr[i] - 'a'] < mc) {
      mc = cost[(int)arr[i] - 'a'];
    }
    if (l > mc) {
      i--;
      mc = 1e9;
      l = 0;
      answer++;
    }
  }
  printf("%d\n%lld", ml, answer);
  return 0;
}
