#include <bits/stdc++.h>
using namespace std;
const int N = 8e3 + 10;
int dp[N];
int p[N];
char s[N];
void PrefixFunction(char *s) {
  int j = 0;
  for (int i = 1; i < s[i]; i++) {
    while (j > 0 && s[j] != s[i]) j = p[j - 1];
    if (s[j] == s[i]) j++;
    p[i] = j;
  }
}
int val[N];
void precalc() {
  int prev = 1;
  int ans = 1;
  for (int i = 1; i <= 8000; i++) {
    if (i == prev * 10) prev *= 10, ans++;
    val[i] = ans;
  }
}
int main() {
  precalc();
  scanf("%s", s);
  int n = strlen(s);
  for (int i = n - 1; i >= 0; i--) {
    PrefixFunction(s + i);
    dp[i] = 1 << 20;
    for (int j = 0; j + i < n; j++) {
      int idx = j + i;
      int cur = p[j];
      int len = j + 1;
      if (cur >= (len + 1) / 2) {
        if (len % (len - cur) == 0) len = len - cur;
      }
      int cnt = (j + 1) / len;
      dp[i] = min(dp[i], dp[idx + 1] + val[cnt] + len);
    }
  }
  int ans = dp[0];
  printf("%d\n", ans);
}
