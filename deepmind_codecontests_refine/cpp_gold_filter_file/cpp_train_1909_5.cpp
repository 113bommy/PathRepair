#include <bits/stdc++.h>
using namespace std;
char str1[5005], str2[5005];
long long dp[5005][5005];
int main() {
  scanf("%s %s", str1, str2);
  int dl1 = strlen(str1), dl2 = strlen(str2);
  for (int i = 0; i < dl1; i++) {
    for (int y = 0; y < dl2; y++) {
      dp[i + 1][y + 1] = dp[i + 1][y];
      if (str1[i] == str2[y])
        dp[i + 1][y + 1] = (dp[i + 1][y + 1] + dp[i][y] + 1) % 1000000007;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= dl1; i++) {
    ans = (ans + dp[i][dl2]) % 1000000007;
  }
  printf("%lld\n", ans);
  return 0;
}
