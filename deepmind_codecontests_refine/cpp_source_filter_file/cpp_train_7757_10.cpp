#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int rec(int i, int d) {
  if (d >= 2000 || d < 0) return 0;
  if (i == 0) {
    if (d == 0)
      return 1;
    else
      return 0;
  }
  int &ret = dp[i][d];
  if (ret != -1) return ret;
  return ret = (rec(i - 1, d - 1) + rec(i - 1, d + 1)) % 1000000007;
}
char st[100005];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", st);
  int sum = 0, mini = INT_MAX;
  for (int i = 0; i < m; i++) {
    if (st[i] == '(')
      sum++;
    else
      sum--;
    mini = min(mini, sum);
  }
  mini = max(0, -mini);
  memset(dp, -1, sizeof dp);
  long long ans = 0;
  for (int i = 0; i <= n - m; i++) {
    for (int d = mini; d < 2000; d++) {
      long long lft = rec(i, d);
      int nowd = d + sum;
      if (nowd < 2000) {
        long long rght = rec(n - m - i, nowd);
        ans = (ans + lft * rght) % 1000000007;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
