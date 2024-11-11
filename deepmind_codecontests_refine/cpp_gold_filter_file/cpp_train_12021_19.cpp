#include <bits/stdc++.h>
using namespace std;
inline void __CIN__() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
char buf;
inline int xint() {
  while (buf = getchar(), buf < '0' || buf > '9')
    ;
  int x = buf - '0';
  for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0')
    ;
  return x;
}
inline long long xll() {
  while (buf = getchar(), buf < '0' || buf > '9')
    ;
  long long x = buf - '0';
  for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0')
    ;
  return x;
}
inline string xstring() {
  while (buf = getchar(), buf == ' ' || buf == '\n')
    ;
  string x = "";
  for (x += buf; buf = getchar(), buf != ' ' && buf != '\n'; x += buf)
    ;
  return x;
}
int n, len;
int x[1005], b[1005];
int pre[1005], ans[1005];
double dp[1005];
int tryDp(double preAns) {
  int i, j;
  for (i = 1; i <= n; ++i) {
    dp[i] = 1e30;
    for (j = 0; j < i; ++j) {
      double tmp = dp[j] + sqrt(1e-9 + abs(x[i] - x[j] - len)) - preAns * b[i];
      if (tmp < dp[i]) {
        dp[i] = tmp;
        pre[i] = j;
      }
    }
  }
  return dp[n] < 0;
}
int main() {
  int i;
  n = xint();
  len = xint();
  for (i = 1; i <= n; ++i) {
    x[i] = xint();
    b[i] = xint();
  }
  double l = 0, r = 1e10, mid;
  while (r - l > 1e-9) {
    mid = (l + r) / 2;
    if (tryDp(mid)) {
      r = mid;
    } else
      l = mid;
  }
  tryDp(l);
  len = 0;
  ans[0] = n;
  while (pre[ans[len]]) {
    ans[len + 1] = pre[ans[len]];
    ++len;
  }
  for (i = len; i >= 0; --i) printf("%d%c", ans[i], " \n"[i == 0]);
  return 0;
}
