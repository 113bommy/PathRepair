#include <bits/stdc++.h>
using namespace std;
int n, kk, a, b;
double dp[1123][111][111];
int arr[111];
void solve() {
  scanf("%d", &n);
  ;
  scanf("%d", &kk);
  ;
  kk = min(kk, 1000);
  double dd = n * (n + 1) / 2;
  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    ;
    for (int j = i + 1; j < n; j++) {
      dp[0][i][j] = 1.0;
    }
  }
  for (int k = 1; k <= kk; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        dp[k][i][j] +=
            dp[k - 1][i][j] * ((i * (i + 1)) / 2 + ((n - 1 - j) * (n - j)) / 2 +
                               ((j - i - 1) * (j - i)) / 2);
        for (int sum = j; sum <= i + (n - 1); sum++) {
          a = (sum - n + 1 > 0 ? sum - n + 1 : 0);
          b = (i < sum - j ? i : sum - j);
          dp[k][i][j] += (1.0 - dp[k - 1][sum - j][sum - i]) * (b - a + 1);
        }
        for (int sum = i; sum <= i + (j - 1); sum++) {
          a = (sum - j + 1 > 0 ? sum - j + 1 : 0);
          b = (i < sum - i ? i : sum - i);
          dp[k][i][j] += dp[k - 1][sum - i][j] * (b - a + 1);
        }
        for (int sum = (i + 1) + j; sum <= j + (n - 1); sum++) {
          a = (i + 1 > sum - n + 1 ? i + 1 : sum - n + 1);
          b = (j < sum - j ? j : sum - j);
          dp[k][i][j] += dp[k - 1][i][sum - j] * (b - a + 1);
        }
        dp[k][i][j] /= dd;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        ans += dp[kk][i][j];
      } else {
        ans += 1 - dp[kk][i][j];
      }
    }
  }
  printf("%.11f\n", ans);
}
int main() {
  solve();
  return 0;
}
