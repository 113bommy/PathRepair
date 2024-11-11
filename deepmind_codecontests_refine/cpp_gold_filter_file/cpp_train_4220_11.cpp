#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[100005][6], b[100005][6], dp[2][32];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < m; i++)
    for (int j = 1; j <= n; j++) scanf("%I64d", &a[i][j]);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) scanf("%I64d", &b[i][j]);
  memset(dp[n & 1], 0x3f, sizeof(dp[n & 1]));
  dp[n & 1][(1 << n) - 1] = 0;
  for (int l = n; l < n * m; l++) {
    int c = (l - 1) / n + 1, r = (l - 1) % n + 1;
    int now = l & 1, nxt = l + 1 & 1;
    memset(dp[nxt], 0x3f, sizeof(dp[nxt]));
    long long tmp;
    if (r == n) {
      for (int i = 0; i < 1 << n; i++) {
        if (i & 1) {
          dp[nxt][i - 1] = min(dp[nxt][i - 1], dp[now][i] + a[c][1]);
          dp[nxt][i] = min(dp[nxt][i], dp[now][i]);
        } else {
          dp[nxt][i] = min(dp[nxt][i], dp[now][i]);
          dp[nxt][i + 1] = min(dp[nxt][i + 1], dp[now][i] + a[c][1]);
        }
      }
    } else {
      for (int i = 0; i < 1 << n; i++) {
        tmp = 0;
        if (!((1 << r) & i)) tmp += a[c - 1][r + 1];
        if (!((1 << r - 1) & i)) tmp += b[c][r];
        if (r == n - 1 && !(i & 1)) tmp += b[c][n];
        dp[nxt][i | (1 << r)] = min(dp[nxt][i | (1 << r)], dp[now][i] + tmp);
        tmp = 0;
        if (((1 << r) & i)) tmp += a[c - 1][r + 1];
        if (((1 << r - 1) & i)) tmp += b[c][r];
        if (r == n - 1 && (i & 1)) tmp += b[c][n];
        dp[nxt][(i | (1 << r)) - (1 << r)] =
            min(dp[nxt][(i | (1 << r)) - (1 << r)], dp[now][i] + tmp);
      }
    }
  }
  cout << dp[n * m & 1][0] << endl;
}
