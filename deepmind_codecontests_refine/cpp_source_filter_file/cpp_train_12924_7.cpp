#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 10000020;
int bufpos;
char buf[MAXSIZE];
void init() {
  buf[fread(buf, 1, MAXSIZE, stdin)] = '\0';
  bufpos = 0;
}
int readint() {
  int val = 0;
  for (; !isdigit(buf[bufpos]); bufpos++)
    ;
  for (; isdigit(buf[bufpos]); bufpos++) val = val * 10 + buf[bufpos] - '0';
  return val;
}
char readchar() {
  for (; isspace(buf[bufpos]); bufpos++)
    ;
  return buf[bufpos++];
}
int readstr(char* s) {
  int cur = 0;
  for (; isspace(buf[bufpos]); bufpos++)
    ;
  for (; !isspace(buf[bufpos]); bufpos++) s[cur++] = buf[bufpos];
  s[cur] = '\0';
  return cur;
}
int dp[100002][11][11], sum[11];
char s[100002];
int a[100002];
int main() {
  init();
  int n = readstr(s + 1);
  for (int i = 1; i < 11; i++) sum[i] = (sum[i - 1] + i) % 11;
  for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
  long long ans = 0;
  for (int i = n; i; i--) {
    for (int j = 0; j < 11; j++)
      for (int k = 0; k < 11; k++)
        if (a[i] < (j + k) % 11) {
          dp[i][j][k] = dp[i + 1][(sum[j] + 9) % 11]
                          [(sum[(k + 10) % 11] + a[i] + 1) % 11] +
                        1;
        }
    if (a[i]) {
      ans += dp[i + 1][0][a[i]] + 1;
    }
  }
  printf("%lld", ans);
}
