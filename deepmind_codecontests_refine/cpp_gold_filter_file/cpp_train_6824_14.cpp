#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long inf = 1e15;
string s[maxn][3];
char a[maxn];
long long n;
long long c[maxn];
long long dp[maxn][3];
int main() {
  scanf("%d", &n);
  for (long long i = 1; i <= n; ++i) {
    scanf("%lld", &c[i]);
  }
  for (long long i = 1; i <= n; ++i) {
    scanf("%s", a);
    s[i][0] = string(a);
    reverse(s[i][0].begin(), s[i][0].end());
    s[i][1] = s[i][0];
    s[i][0] = string(a);
  }
  for (long long i = 0; i <= n; ++i) {
    dp[i][0] = dp[i][1] = inf;
  }
  dp[1][0] = 0;
  dp[1][1] = c[1];
  long long i;
  for (i = 2; i <= n; ++i) {
    if (s[i][0] >= s[i - 1][0]) dp[i][0] = dp[i - 1][0];
    if (s[i][1] >= s[i - 1][0]) dp[i][1] = dp[i - 1][0] + c[i];
    if (s[i][0] >= s[i - 1][1]) dp[i][0] = min(dp[i - 1][1], dp[i][0]);
    if (s[i][1] >= s[i - 1][1]) dp[i][1] = min(dp[i - 1][1] + c[i], dp[i][1]);
    if (dp[i][0] == inf && dp[i][1] == inf) break;
  }
  if (i == n + 1)
    printf("%lld\n", min(dp[n][0], dp[n][1]));
  else
    printf("-1\n");
  return 0;
}
