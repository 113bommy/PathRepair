#include <bits/stdc++.h>
using namespace std;
int n, dp[5005], ans;
char s[5005], t[5005];
int main() {
  scanf("%s %s", s + 1, t + 1);
  while (t[n + 1]) n++;
  for (int i = 1; t[i]; i++)
    for (int j = (n); j >= (1); j--)
      if (t[i] == s[j]) {
        ans = (ans + dp[j - 1] + 1) % 1000000007;
        dp[j] = (dp[j] + dp[j - 1] + 1) % 1000000007;
      }
  printf("%d\n", ans);
}
