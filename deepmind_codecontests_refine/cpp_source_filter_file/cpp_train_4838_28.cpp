#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, N = 1e5 + 5;
char s[N], t[N];
int nxt[N], pre[N], dp[N], sum[N];
int main() {
  scanf("%s %s", s + 1, t + 1);
  int n = strlen(s + 1), m = strlen(t + 1);
  for (int i = 1, j = 0; t[i]; nxt[++i] = ++j)
    while (j != 0 && t[i] != t[j]) j = nxt[j];
  for (int i = 1, j = 1; s[i]; ++i) {
    while (j != 0 && s[i] != t[j]) j = nxt[j];
    j = j + 1;
    if (!t[j]) pre[i] = i - m + 1, j = nxt[j];
  }
  for (int i = 1; i <= n; ++i) {
    if (!pre[i]) pre[i] = pre[i - 1];
    dp[i] = (dp[i] + dp[i - 1]) % MOD;
    if (pre[i]) dp[i] = (dp[i] + sum[pre[i] - 1] + pre[i]) % MOD;
    sum[i] = (sum[i] + dp[i]) % MOD;
  }
  printf("%d\n", dp[n]);
  return 0;
}
