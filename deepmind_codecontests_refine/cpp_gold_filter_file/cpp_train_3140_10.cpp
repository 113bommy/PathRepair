#include <bits/stdc++.h>
using namespace std;
int make_token(char* s) {
  int n = 0;
  if (!isdigit(s[strlen(s) - 1])) return 0;
  for (int i = 0; s[i]; i++) {
    if (!isdigit(s[i])) {
      if (i && isdigit(s[i - 1]))
        s[n++] = 'B';
      else if (s[i] == '*' || s[i] == '/')
        return 0;
      else
        s[n++] = 'U';
    } else if (!isdigit(s[i + 1]))
      s[n++] = '0';
  }
  s[n] = 'E';
  return n;
}
int dp[2005][2005];
char s[2005];
int main() {
  int n = make_token(gets(s));
  if (!n) return puts("0") & 0;
  for (int i = dp[0][0] = 1; i <= n; i++)
    for (int j = n; ~j; j--) {
      if (s[i - 1] == '0')
        dp[i][j] = (dp[i - 1][j] + dp[i][j + 1]) % 1000003;
      else if (j)
        dp[i][j] = dp[i - 1][j - 1];
    }
  printf("%d\n", dp[n][0]);
}
