#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000;
const int INF = 0x3f3f3f3f;
const int MOD = 1000003;
template <class T>
void Read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = 0;
  while (c < '0' || '9' < c) {
    if (c == '-') flag = 1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (flag) x = -x;
}
int dp[MAXN + 10][MAXN + 10];
int n;
char str[MAXN + 10];
bool sp[MAXN + 10];
int cnt;
inline int adjust(int v) {
  if (v >= MOD)
    return v - MOD;
  else if (v < 0)
    return v + MOD;
  else
    return v;
}
inline bool isop(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '\0';
}
inline bool check() {
  if (isop(str[n])) return false;
  for (int i = 1; i <= n; ++i)
    if ((str[i] == '*' || str[i] == '/') && isop(str[i - 1])) return false;
  return true;
}
int main() {
  scanf("%s", str + 1);
  n = strlen(str + 1);
  if (!check())
    puts("0");
  else {
    cnt = 0;
    for (int i = 1; i <= n; ++i)
      if (isop(str[i])) {
        ++cnt;
        if (isop(str[i - 1])) sp[cnt] = true;
      }
    dp[0][0] = 1;
    for (int i = 1; i <= cnt; ++i) {
      if (sp[i])
        for (int j = 1; j <= cnt; ++j) dp[i][j] = dp[i - 1][j - 1];
      else
        for (int j = 0; j <= cnt; ++j) dp[i][j] = dp[i - 1][j];
      for (int j = 1; j <= cnt; ++j) dp[i][j] = adjust(dp[i][j] + dp[i][j - 1]);
      for (int j = 0; j <= cnt - 1; ++j) dp[i][j] = dp[i][j + 1];
    }
    printf("%d\n", dp[cnt][0]);
  }
}
