#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const int N = 1e5 + 5;
char s[N], t[N];
int nxt[N];
bool f[N] = {};
long long dp[N], sum[N];
void get_next(char *s, int *nxt) {
  int n = strlen(s);
  int j = 0;
  nxt[0] = nxt[1] = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && s[i] != s[j]) j = nxt[j];
    if (s[i] == s[j]) j++;
    nxt[i + 1] = j;
  }
}
void match(char *a, char *b, int *nxt) {
  int j = 0;
  int n = strlen(a), m = strlen(b);
  for (int i = 0; i < n; i++) {
    while (j > 0 && a[i] != b[j]) j = nxt[j];
    if (a[i] == b[j]) j++;
    if (j == m) {
      f[i + 1] = true;
      j = nxt[j];
    }
  }
}
int main() {
  scanf("%s%s", s, t);
  get_next(s, nxt);
  match(s, t, nxt);
  int n = strlen(s), m = strlen(t);
  sum[0] = dp[0] = 0;
  int last = -1;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    if (f[i]) last = i - m;
    if (last != -1) dp[i] += sum[last] + last + 1, dp[i] %= mod;
    sum[i] = (sum[i - 1] + dp[i]) % mod;
  }
  printf("%lld\n", dp[n]);
  return 0;
}
