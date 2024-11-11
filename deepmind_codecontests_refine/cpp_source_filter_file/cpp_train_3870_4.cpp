#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
long long dp[102][102];
int FSM[102][26];
char str[102];
int main() {
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  scanf("%s", str + 1);
  int sl = strlen(str + 1);
  for (int i = 0; i <= sl; i++) {
    for (int j = 0; j < 26; j++) {
      FSM[i][j] = -1;
    }
  }
  for (int i = 0; i < sl; i++) {
    for (int j = sl; j > i; j--) {
      FSM[i][str[j] - 'a'] = j;
    }
  }
  dp[0][0] = 1;
  for (int i = 0; i < sl; i++) {
    for (int len = 0; len <= sl; len++) {
      if (!dp[i][len]) continue;
      for (int j = 0; j < 26; j++) {
        if (FSM[i][j] == -1) continue;
        long long &nxt = dp[FSM[i][j]][len + 1];
        nxt += dp[i][len];
        nxt = min(INF, nxt);
      }
    }
  }
  long long ans = 0;
  for (int len = sl; len >= 0 && k; len--) {
    for (int j = 0; j < 26; j++) {
      if (dp[j][len] < k) {
        ans += dp[j][len] * (n - len);
        k -= dp[j][len];
      } else {
        ans += k * (n - len);
        k = 0;
        break;
      }
    }
  }
  if (k) {
    puts("-1");
    return 0;
  }
  printf("%lld", ans);
  return 0;
}
