#include <bits/stdc++.h>
using namespace std;
int n, dp[8005], nxt[8005], lg[8005];
void init(char *s, int len) {
  nxt[0] = nxt[1] = 0;
  for (int i = 1; i < len; i++) {
    int j = nxt[i];
    while (j && s[i] != s[j]) j = nxt[j];
    if (s[i] == s[j]) j++;
    nxt[i + 1] = j;
  }
}
char s[8005];
int main() {
  for (int i = 1; i < 8005; i++) lg[i] = lg[i / 10] + 1;
  scanf("%s", s);
  n = strlen(s);
  for (int i = 1; i <= n; i++) dp[i] = i + 1;
  for (int i = 0; i < n; i++) {
    init(s + i, n - i);
    for (int j = 1; i + j <= n; j++) {
      int l = j - nxt[j];
      if (j % l == 0)
        dp[i + j] = min(dp[i + j], dp[i] + lg[j / l] + l);
      else
        dp[i + j] = min(dp[i + j], dp[i] + j + 1);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
