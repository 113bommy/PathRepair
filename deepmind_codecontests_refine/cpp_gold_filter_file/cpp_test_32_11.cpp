#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 1e5 + 10;
const int inf = 1e9 + 7;
int T, n;
int a[N];
long long sum[N];
int dp[N][500];
int main() {
  T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; ++i) {
      a[i] = read();
      sum[i] = sum[i - 1] + a[i];
    }
    int k = 0;
    while (k * (k + 1) / 2 <= n) k++;
    for (int j = 0; j < k; ++j) dp[n + 1][j] = -inf;
    dp[n + 1][0] = inf;
    for (int i = n; i >= 1; --i) {
      for (int j = 0; j < k; ++j) {
        dp[i][j] = dp[i + 1][j];
        if (j && i + j - 1 <= n &&
            sum[i + j - 1] - sum[i - 1] < dp[i + j][j - 1]) {
          dp[i][j] = max(dp[i][j], (int)(sum[i + j - 1] - sum[i - 1]));
        }
      }
    }
    int ans = 0;
    for (int j = 0; j < k; ++j) {
      if (dp[1][j] > 0) ans = j;
    }
    printf("%d\n", ans);
  }
  return 0;
}
