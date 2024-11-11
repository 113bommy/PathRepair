#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MAXN = 300000 + 4;
int data[MAXN], n, k;
long long sum[MAXN];
bool cmp(int a, int b) { return a < b; }
long long dp[5000 + 5][5000 + 5];
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &data[i]);
    sort(data + 1, data + n + 1, cmp);
    sum[0] = 0;
    data[0] = data[1];
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + data[i] - data[i - 1];
    }
    for (int i = 0; i <= k; i++)
      for (int j = 0; j <= k; j++) dp[i][j] = -1;
    int up1, up2;
    up1 = k - n % k;
    up2 = n % k;
    int len = n / k;
    dp[0][0] = 0;
    for (int i = 0; i <= up1; i++) {
      for (int j = 0; j <= up2; j++) {
        if (i == 0 && j == 0) continue;
        if (i > 0) {
          if (dp[i][j] == -1)
            dp[i][j] = dp[i - 1][j] + sum[len * i + (len + 1) * j] -
                       sum[len * (i - 1) + (len + 1) * j + 1];
          else
            dp[i][j] =
                ((dp[i][j]) < (dp[i - 1][j] + sum[len * i + (len + 1) * j] -
                               sum[len * (i - 1) + (len + 1) * j + 1])
                     ? (dp[i][j])
                     : (dp[i - 1][j] + sum[len * i + (len + 1) * j] -
                        sum[len * (i - 1) + (len + 1) * j + 1]));
        }
        if (j > 0) {
          if (dp[i][j] == -1)
            dp[i][j] = dp[i][j - 1] + sum[len * i + (len + 1) * j] -
                       sum[len * i + (len + 1) * (j - 1) + 1];
          else
            dp[i][j] =
                ((dp[i][j]) < (dp[i][j - 1] + sum[len * i + (len + 1) * j] -
                               sum[len * i + (len + 1) * (j - 1) + 1])
                     ? (dp[i][j])
                     : (dp[i][j - 1] + sum[len * i + (len + 1) * j] -
                        sum[len * i + (len + 1) * (j - 1) + 1]));
        }
      }
    }
    printf("%I64d\n", dp[up1][up2]);
  }
  return 0;
}
