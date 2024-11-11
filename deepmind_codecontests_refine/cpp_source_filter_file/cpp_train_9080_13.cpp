#include <bits/stdc++.h>
using namespace std;
int add(int x, int y) { return ((x + y) % 998244353 + 998244353) % 998244353; }
char s[3005], pre[3005];
int dp[3005], tmp[3005];
void solve() {
  int n, m;
  scanf("%s ", s);
  scanf("%s ", pre);
  n = strlen(s);
  m = strlen(pre);
  dp[m] = 2;
  int ret = 0;
  for (int i = 0; i < m; ++i) {
    if (pre[i] == s[0]) {
      dp[i] = 2;
    }
  }
  if (m == 1) {
    ret = add(ret, 2);
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      tmp[j] = 0;
      if (pre[j] == s[i]) {
        tmp[j] = dp[j + 1];
      }
    }
    int len = i + 1;
    for (int j = 0; j < m; ++j) {
      if ((j + len - 1 < m && pre[j + len - 1] == s[i]) || j + len - 1 >= m) {
        tmp[j] = add(tmp[j], dp[j]);
      }
    }
    for (int j = 0; j < m; ++j) {
      dp[j] = tmp[j];
    }
    dp[m] = add(dp[m], dp[m]);
    if (len >= m) ret = add(ret, dp[0]);
  }
  printf("%d\n", ret);
}
int main() {
  solve();
  return 0;
}
