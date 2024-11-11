#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int digit[15];
int dp[10][10];
int a[10];
int b[10];
int get_digit(int m) {
  int len = 0;
  while (m) {
    digit[len++] = m % 10;
    m /= 10;
  }
  return len;
}
int solve(int len, int sum, int flag) {
  if (len == -1) return sum == 0;
  if (!flag && dp[len][sum] != -1) return dp[len][sum];
  int ans = 0;
  int maxp = flag ? digit[len] : 9;
  for (int i = 0; i <= maxp; i++) {
    int nowsum = sum;
    if (i == 4 || i == 7) nowsum--;
    if (nowsum < 0) continue;
    ans += solve(len - 1, nowsum, flag && i == maxp);
    ans %= mod;
  }
  if (!flag) dp[len][sum] = ans;
  return ans;
}
int dfs(int pos, int len, int sum) {
  if (pos == 0) {
    long long ans = 1;
    for (int i = 0; i <= len; i++) {
      for (int j = 0; j < b[i]; j++) ans = ans * (a[i] - j) % mod;
    }
    return (int)ans;
  }
  int ss = 0;
  for (int i = 0; i <= len; i++) {
    if (i > sum) break;
    if (b[i] == a[i]) continue;
    b[i]++;
    ss = (ss + dfs(pos - 1, len, sum - i)) % mod;
    b[i]--;
  }
  return ss;
}
int fun(int len) {
  memset(dp, -1, sizeof dp);
  for (int i = 0; i <= len; i++) a[i] = solve(len - 1, i, 1);
  a[0]--;
  int ans = 0;
  memset(b, 0, sizeof b);
  for (int i = 1; i <= len; i++) {
    if (a[i]) {
      b[i]++;
      ans = (ans + dfs(6, len, i - 1)) % mod;
      b[i]--;
    }
  }
  return ans;
}
int main() {
  int m;
  while (~scanf("%d", &m)) {
    int len = get_digit(m);
    printf("%d\n", fun(len));
  }
  return 0;
}
