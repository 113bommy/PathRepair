#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long readll() {
  long long f = 1, x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long dp[31][2][2];
long long calc(long long a, long long b) {
  if (a < 0 || b < 0) return 0;
  memset(dp, 0, sizeof(dp));
  dp[31][1][1] = 1;
  for (int i = 31; i > 0; --i) {
    for (int j = 0; j <= 1; ++j) {
      for (int k = 0; k <= 1; ++k) {
        bool x = ((a >> (i - 1)) & 1LL), y = ((b >> (i - 1)) & 1LL);
        dp[i - 1][j && !x][k && !y] += dp[i][j][k];
        if (!j || x) dp[i - 1][j][k && !y] += dp[i][j][k];
        if (!k || y) dp[i - 1][j && !x][k] += dp[i][j][k];
      }
    }
  }
  return dp[0][0][0] + dp[0][0][1] + dp[0][1][0] + dp[0][1][1];
}
int main() {
  int T = read();
  while (T--) {
    int l = read(), r = read();
    cout << calc(r, r) - calc(l - 1, r) - calc(r, l - 1) + calc(l - 1, l - 1)
         << endl;
  }
  return 0;
}
