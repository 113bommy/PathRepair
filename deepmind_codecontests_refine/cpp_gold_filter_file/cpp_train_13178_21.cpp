#include <bits/stdc++.h>
using namespace std;
char s[5000006];
long long rsum[5000006], Pow[5000006], dp[5000006], ans, sum;
int main() {
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  Pow[0] = 1;
  for (int i = len; i >= 1; i--)
    rsum[i] = rsum[i + 1] * 131 + s[i], Pow[len - i + 1] = Pow[len - i] * 131,
    dp[i] = 1;
  for (int i = 1; i <= len; i++) {
    sum = sum * 131 + s[i];
    if (sum == rsum[1] - rsum[i + 1] * Pow[i])
      dp[i * 2] = dp[i * 2 + 1] = dp[i] + 1, ans += dp[i];
  }
  printf("%lld\n", ans);
}
