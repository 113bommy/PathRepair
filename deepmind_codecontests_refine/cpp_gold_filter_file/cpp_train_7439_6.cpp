#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& num) {
  char CH;
  bool F = false;
  for (CH = getchar(); CH < '0' || CH > '9'; F = CH == '-', CH = getchar())
    ;
  for (num = 0; CH >= '0' && CH <= '9';
       num = num * 10 + CH - '0', CH = getchar())
    ;
  F && (num = -num);
}
int stk[70], tp;
template <class T>
inline void print(T p) {
  if (!p) {
    puts("0");
    return;
  }
  while (p) stk[++tp] = p % 10, p /= 10;
  while (tp) putchar(stk[tp--] + '0');
  putchar('\n');
}
const long long mod = 1e9 + 7;
const double PI = acos(-1.0);
const int inf = 1e9;
const int N = 1e6 + 20;
const int maxn = 1e6 + 220;
const double eps = 1e-12;
int n, a[N];
long long dp[N][2];
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  dp[0][0] = dp[0][1] = 0;
  dp[1][0] = dp[1][1] = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] > a[i - 1]) {
      dp[i][1] = max(dp[i][1], dp[i - 1][1] + a[i] - a[i - 1]);
      dp[i][1] = max(dp[i][1], dp[i - 2][0] + a[i] - a[i - 1]);
    } else {
      dp[i][0] = max(dp[i][0], dp[i - 1][0] + a[i - 1] - a[i]);
      dp[i][0] = max(dp[i][0], dp[i - 2][1] + a[i - 1] - a[i]);
    }
    dp[i][0] = max(dp[i][0], dp[i - 1][0]);
    dp[i][1] = max(dp[i][1], dp[i - 1][1]);
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
  return 0;
}
