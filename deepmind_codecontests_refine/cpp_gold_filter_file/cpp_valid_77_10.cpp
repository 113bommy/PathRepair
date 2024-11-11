#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + (ch - '0'), ch = getchar();
  return x * f;
}
int dp[4000010];
int main() {
  int n = read(), m = read();
  dp[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] += dp[i + 1];
    for (int j = 2 * i; j <= n; j += i)
      dp[i] = (dp[i] + ((dp[j] - dp[min(j + j / i, n + 1)]) % m + m) % m) % m;
    dp[i] = (dp[i] + dp[i + 1]) % m;
  }
  printf("%d\n", ((dp[1] - dp[2]) % m + m) % m);
  return 0;
}
