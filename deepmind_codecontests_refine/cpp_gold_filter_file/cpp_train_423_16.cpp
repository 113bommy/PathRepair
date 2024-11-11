#include <bits/stdc++.h>
using namespace std;
inline long long getnum() {
  char c = getchar();
  long long num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
int dp[504][504];
long long ddp[504];
int add(int x, int y) {
  int ans = x + y;
  if (ans >= 998244353) ans -= 998244353;
  return ans;
}
int main() {
  int n = getnum(), tot = getnum();
  for (int i = 0; i <= n; i++) dp[0][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      for (int k = 1; k <= n; k++) {
        if (k < j && i != j)
          dp[i][j] = add(dp[i][j], dp[i - j][k]);
        else if (i - j >= 1 || (i == j && k == j))
          dp[i][k] = add(dp[i][k], dp[i - j][k]);
      }
    }
  }
  for (int i = 1; i <= n; i++) ddp[i] = dp[n][i];
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      if (i * j < tot) ans = (ans + ddp[i] * ddp[j] * 2) % 998244353;
  }
  cout << ans << endl;
}
