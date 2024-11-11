#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int dp[27][maxn / 10];
char s[maxn];
int n, m, k;
int T;
int cnt[50];
long long sum[50];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", s);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < k; i++) {
      cnt[s[i] - 'A' + 1]++;
    }
    for (int i = 1; i <= 26; i++) {
      sum[i] = sum[i - 1] + cnt[i];
    }
    long long mx = (long long)maxn * maxn;
    for (int i = 1; i <= 26; i++) {
      for (int ii = 0; ii <= 26; ii++) {
        for (int jj = 0; jj <= n; jj++) {
          dp[ii][jj] = -1;
        }
      }
      dp[0][0] = 0;
      for (int j = 1; j <= 26; j++) {
        for (int k = 0; k <= n; k++) {
          if (dp[j - 1][k] == -1) continue;
          if (i == j) {
            dp[j][k] = max(dp[j][k], dp[j - 1][k]);
            continue;
          }
          dp[j][min(n, k + cnt[j])] =
              max(dp[j][min(n, k + cnt[j])], dp[j - 1][k]);
          dp[j][min(n, k + cnt[j])] = min(dp[j][min(n, k + cnt[j])], m);
          dp[j][k] = max(dp[j][k], dp[j - 1][k] + cnt[j]);
          dp[j][k] = min(m, dp[j][k]);
        }
      }
      for (int j = 1; j <= 26; j++) {
        if (i == j) continue;
        for (int k = 0; k <= n; k++) {
          if (dp[j][k] == -1) continue;
          long long t1 = n - k;
          long long t2 = max(0, m - dp[j][k]);
          if (t1 + t2 <= cnt[i]) {
            mx = min(mx, t1 * t2);
          }
        }
      }
    }
    printf("%lld\n", mx);
  }
}
