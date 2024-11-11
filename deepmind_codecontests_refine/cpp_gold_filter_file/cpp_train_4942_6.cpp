#include <bits/stdc++.h>
using namespace std;
char s[123456], t[123456];
int dp[123456], sum[123456], f[123456];
void init() {
  scanf("%s", s);
  scanf("%s", t);
}
void getfail() {
  int m = strlen(t);
  f[0] = 0;
  f[1] = 0;
  for (int i = 1; i < m; i++) {
    int j = f[i];
    while (j && t[i] != t[j]) j = f[j];
    f[i + 1] = (t[i] == t[j] ? j + 1 : 0);
  }
}
void solve() {
  getfail();
  int j = 0, maxj = 0, n = strlen(s), m = strlen(t);
  dp[0] = 1;
  sum[0] = 1;
  for (int i = 0; i < n; i++) {
    while (j && s[i] != t[j]) j = f[j];
    if (s[i] == t[j]) j++;
    if (j == m) {
      maxj = i - m + 2;
      j = f[j];
    }
    dp[i + 1] += dp[i] + (maxj ? sum[maxj - 1] : 0);
    if (dp[i + 1] > 1000000007) dp[i + 1] -= 1000000007;
    sum[i + 1] = sum[i] + dp[i + 1];
    if (sum[i + 1] > 1000000007) sum[i + 1] -= 1000000007;
  }
  printf("%d\n", ((dp[n] - 1) % 1000000007 + 1000000007) % 1000000007);
}
int main() {
  init();
  solve();
}
