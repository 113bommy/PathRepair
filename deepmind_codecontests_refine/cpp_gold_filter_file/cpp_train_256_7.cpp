#include <bits/stdc++.h>
using namespace std;
inline int Readint() {
  int ret = 0;
  int f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f *= -1;
  } while (ch >= 0 && (ch < '0' || ch > '9'));
  while ('0' <= ch && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * f;
}
void open() {
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
}
void close() {
  fclose(stdin);
  fclose(stdout);
}
const int MAXN = 3E5 + 10;
int n, k;
int a[MAXN] = {0};
long long pre[MAXN] = {0};
long long dp[5005][5005] = {0};
void init() {
  n = Readint(), k = Readint();
  for (int i = 1, _END_ = n; i <= _END_; i++) a[i] = Readint();
  sort(a + 1, a + 1 + n);
  for (int i = 1, _END_ = n; i <= _END_; i++)
    pre[i] = pre[i - 1] + a[i] - a[i - 1];
}
const long long inf = 1LL << 61;
void work() {
  for (int i = 0, _END_ = k; i <= _END_; i++)
    for (int j = 0, _END_ = k; j <= _END_; j++) dp[i][j] = 1LL << 61;
  dp[0][0] = 0;
  int d = n / k, dd = n % k;
  for (int i = 0, _END_ = k - 1; i <= _END_; i++) {
    for (int j = 0, _END_ = min(i, dd); j <= _END_; j++)
      if (dp[i][j] != inf) {
        dp[i + 1][j] = min(
            dp[i + 1][j], dp[i][j] + pre[d * (i + 1) + j] - pre[d * i + 1 + j]);
        if (j < dd)
          dp[i + 1][j + 1] =
              min(dp[i + 1][j + 1],
                  dp[i][j] + pre[d * (i + 1) + j + 1] - pre[d * i + 1 + j]);
      }
  }
  printf("%I64d\n", dp[k][dd]);
}
int main() {
  int _ = 0;
  init();
  work();
  close();
  return 0;
}
