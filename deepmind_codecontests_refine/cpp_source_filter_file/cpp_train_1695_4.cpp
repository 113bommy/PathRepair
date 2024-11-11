#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int read() {
  char ch = getchar();
  int x = 0, f = 1;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch - '0');
  return x * f;
}
int a[10100];
struct eto {
  int y, nxt;
} e[100100];
int head[10100];
int tot = 0;
bool bo[10100];
int dp[2010][8010][2], f[2010][8010][2];
void add(int x, int y) {
  e[++tot].y = y;
  e[tot].nxt = head[x];
  head[x] = tot;
}
int dfs(int x) {
  bo[x] = 1;
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].y;
    if (!bo[y]) return dfs(y) + 1;
  }
  return 1;
}
int qaq = 2000;
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read();
    add(x, y);
    add(y, x);
  }
  bo[1] = 1;
  int top = 0;
  for (int i = head[1]; i; i = e[i].nxt)
    if (!bo[e[i].y]) a[++top] = dfs(e[i].y) + 1;
  dp[0][qaq][0] = f[0][qaq][0] = 1;
  int num = 0;
  for (int i = 1; i <= top; i++) {
    for (int j = -num; j <= num; j++) {
      dp[i][j + a[i] + qaq][0] =
          (dp[i][j + a[i] + qaq][0] + dp[i - 1][j + qaq][0]) % 1000000007;
      dp[i][j - a[i] + qaq][0] =
          (dp[i][j - a[i] + qaq][0] + dp[i - 1][j + qaq][0]) % 1000000007;
      dp[i][j + qaq][0] =
          (dp[i][j + qaq][0] + dp[i - 1][j + qaq][0]) % 1000000007;
      dp[i][j + a[i] + qaq][1] =
          (dp[i][j + a[i] + qaq][1] + dp[i - 1][j + qaq][1]) % 1000000007;
      dp[i][j - a[i] + qaq][1] =
          (dp[i][j - a[i] + qaq][1] + dp[i - 1][j + qaq][1]) % 1000000007;
      dp[i][j + qaq][1] =
          (dp[i][j + qaq][1] + dp[i - 1][j + qaq][1]) % 1000000007;
      f[i][j + a[i] + qaq][0] =
          (f[i][j + a[i] + qaq][0] + f[i - 1][j + qaq][0]) % 1000000007;
      f[i][j - a[i] + qaq][0] =
          (f[i][j - a[i] + qaq][0] + f[i - 1][j + qaq][0]) % 1000000007;
      f[i][j + a[i] + qaq][0] =
          (f[i][j + a[i] + qaq][1] + f[i - 1][j + qaq][1]) % 1000000007;
      f[i][j - a[i] + qaq][0] =
          (f[i][j - a[i] + qaq][1] + f[i - 1][j + qaq][1]) % 1000000007;
      for (int x = 1; x < a[i]; x++) {
        int y = a[i] - x;
        dp[i][j + x - y + qaq][1] = (dp[i][j + x - y + qaq][1] +
                                     2ll * dp[i - 1][j + qaq][0] % 1000000007) %
                                    1000000007;
      }
      for (int x = 1; x < a[i] - 1; x++) {
        int y = (a[i] - 1) - x;
        dp[i][j + x - y + qaq][1] = (dp[i][j + x - y + qaq][1] +
                                     2ll * dp[i - 1][j + qaq][0] % 1000000007) %
                                    1000000007;
      }
      f[i][j + (a[i] - 1) + qaq][1] =
          (f[i][j + (a[i] - 1) + qaq][1] +
           2ll * f[i - 1][j + qaq][0] % 1000000007) %
          1000000007;
      f[i][j - (a[i] - 1) + qaq][1] =
          (f[i][j - (a[i] - 1) + qaq][1] +
           2ll * f[i - 1][j + qaq][0] % 1000000007) %
          1000000007;
    }
    num += a[i];
  }
  int ans = 0;
  ans = (ans + dp[top][qaq][1]) % 1000000007;
  ans = (ans + f[top][qaq][0]) % 1000000007;
  ans = (ans + f[top][qaq][1]) % 1000000007;
  printf("%d\n", ans);
  return 0;
}
