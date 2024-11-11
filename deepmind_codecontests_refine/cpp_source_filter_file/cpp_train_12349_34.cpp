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
long double dp[52][5200];
int n, f[52], s[52], r;
long double p[52];
bool check(long double x) {
  for (int i = n; i; i--)
    for (int j = 0; j <= r; j++) {
      if (j + f[i] <= r)
        dp[i][j] =
            min(x, p[i] * (f[i] + dp[i + 1][j + f[i]]) +
                       (1 - p[i]) *
                           (s[i] + (j + s[i] <= r ? dp[i + 1][j + s[i]] : x)));
      else
        dp[i][j] = x;
    }
  return dp[1][0] < x;
}
int main() {
  init();
  n = readint(), r = readint();
  for (int i = 1; i <= n; i++)
    f[i] = readint(), s[i] = readint(), p[i] = readint() / 100.0;
  long double l = 0, r = 100000;
  for (int o = 0; o < 100; o++) {
    long double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10Lf", (l + r) / 2);
}
