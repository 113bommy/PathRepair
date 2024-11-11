#include <bits/stdc++.h>
using namespace std;
int n, k, b[300005], l1, l2, num1, num2;
int dp[5005][5005];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  sort(b + 1, b + n + 1);
  l1 = n / k;
  l2 = l1 + 1;
  num2 = n % k;
  num1 = k - num2;
  for (int i = 0; i <= num1; i++)
    for (int j = 0; j <= num2; j++) {
      if (i + j == 0) continue;
      int t1 = 0x7fffffff, t2 = 0x7fffffff;
      if (j != 0) {
        t1 = dp[i][j - 1] + b[i * l1 + j * l2] - b[i * l1 + j * l2 - l2 + 1];
      }
      if (i != 0) {
        t2 = dp[i - 1][j] + b[i * l1 + j * l2] - b[i * l1 + j * l2 - l1 + 1];
      }
      dp[i][j] = min(t1, t2);
    }
  cout << dp[num1][num2] << endl;
  return 0;
}
