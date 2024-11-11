#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int maxn = 1e5;
char s[maxn + 5], t[maxn + 5];
int dp[maxn + 5], sum[maxn + 5];
int main() {
  scanf("%s%s", s, t);
  static int f[maxn + 5];
  int lt = strlen(t);
  f[0] = 0, f[1] = 0;
  for (int i = (1), _end_ = (lt); i != _end_; ++i) {
    int j = f[i];
    while (j && t[i] != t[j]) j = f[j];
    f[i + 1] = t[i] == t[j] ? j + 1 : 0;
  }
  int lst = -1;
  dp[0] = 1;
  sum[0] = dp[0];
  int ans = 0;
  int sum0 = 1;
  int cur = 0;
  for (int i = 0; s[i]; ++i) {
    while (cur && t[cur] != s[i]) cur = f[cur];
    cur += t[cur] == s[i];
    if (cur == lt) lst = i - lt + 1, cur = f[cur];
    if (lst != -1) dp[i + 1] = sum[lst];
    (ans += dp[i + 1]) %= Mod;
    sum[i + 1] = (sum[i] + (sum0 += dp[i + 1])) % Mod;
  }
  printf("%d\n", ans);
  return 0;
}
