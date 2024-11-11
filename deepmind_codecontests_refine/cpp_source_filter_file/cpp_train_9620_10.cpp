#include <bits/stdc++.h>
using namespace std;
int tot, dp[1000005], n;
char str[1000005];
int main() {
  scanf("%s", str + 1);
  n = strlen(str + 1);
  dp[0] = -1;
  for (int i = 1; i <= n; i++) {
    if (str[i] == 'F') {
      tot++;
      if (i == tot)
        dp[tot] = 0;
      else
        dp[tot] = max(i - tot, dp[tot - 1] + 1);
    }
  }
  cout << dp[tot];
  return 0;
}
