#include <bits/stdc++.h>
using namespace std;
long long fib[100];
void init() {
  fib[1] = 1;
  fib[2] = 2;
  for (int i = 3; i <= 88; i++) fib[i] = fib[i - 1] + fib[i - 2];
}
int f[100];
long long dp[100][2];
int main() {
  init();
  int T;
  scanf("%d", &T);
  long long x;
  while (T--) {
    cin >> x;
    int l = 1;
    long long t = x;
    for (int i = 88; i >= 1; i--) {
      if (t >= fib[i]) {
        t -= fib[i];
        f[l++] = i;
      }
      if (t == 0) break;
    }
    if (t != 0) {
      printf("0\n");
      continue;
    }
    memset(dp, 0, sizeof(dp));
    dp[l - 1][1] = 1;
    dp[l - 1][0] = (f[l - 1] - 1) / 2;
    for (int i = l - 2; i >= 1; i--) {
      dp[i][1] = dp[i + 1][1] + dp[i + 1][0];
      dp[i][0] += dp[i + 1][1] * ((f[i] - f[i + 1] - 1) / 2);
      dp[i][0] += dp[i + 1][0] * ((f[i] - f[i + 1]) / 2);
    }
    cout << dp[1][0] + dp[1][1] << endl;
  }
  return 0;
}
