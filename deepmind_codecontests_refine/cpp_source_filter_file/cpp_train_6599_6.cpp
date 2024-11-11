#include <bits/stdc++.h>
const int N = 100010;
int n;
unsigned int dp[N << 1];
int main() {
  scanf("%d\n", &n);
  if (n & 1) {
    printf("0");
    return 0;
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    char ch;
    scanf("%c", &ch);
    if (ch == '?') {
      for (int j = i / 2; j >= 1; j--) dp[j] = dp[j] * 25 + dp[j - 1];
      dp[0] *= 25;
    }
  }
  printf("%d", dp[n / 2]);
  return 0;
}
