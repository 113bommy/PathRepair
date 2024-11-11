#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
char s[maxn];
int dp[1 << 20];
int main() {
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  for (int i = 1; i <= len; i++) {
    int mask = 0;
    for (int j = i; j <= len; j++) {
      int v = s[j] - 'a';
      if (mask & (1 << v)) break;
      mask = mask ^ (1 << v);
      dp[mask] = j - i + 1;
    }
  }
  for (int p = 0; p < 20; p++)
    for (int mask = 0; mask < (1 << 20); mask++)
      if (mask & (1 << p) == 0)
        dp[mask ^ (1 << p)] = max(dp[mask ^ (1 << p)], dp[mask]);
  int ans = 0;
  for (int i = 0; i < (1 << 20); i++)
    ans = max(ans, dp[i] + dp[(1 << 20) - 1 - i]);
  printf("%d\n", ans);
  return 0;
}
