#include <bits/stdc++.h>
int N = 1e5 + 7;
int MOD = 1e9 + 7;
char s[10001], t[10001];
int f[100007], dp[100007], sum[100007], ssum[100007];
int main() {
  scanf("%s %s", &s, &t);
  int n = strlen(s), m = strlen(t);
  f[1] = 0;
  int k = 0, i;
  for (i = 1; i < m; i++) {
    while (k && t[i] != t[k]) k = f[k];
    if (t[i] == t[k]) k++;
    f[i + 1] = k;
  }
  k = 0;
  for (i = 0; i < n; i++) {
    while (k && s[i] != t[k]) k = f[k];
    if (s[i] == t[k]) k++;
    if (k == m) {
      dp[i + 1] = ssum[i + 1 - m] + (i + 1 - m + 1);
      k = f[k];
    } else
      dp[i + 1] = dp[i];
    sum[i + 1] = (sum[i] + dp[i + 1]) % MOD;
    ssum[i + 1] = (ssum[i] + sum[i + 1]) % MOD;
  }
  printf("%d", sum[n]);
  return 0;
}
