#include <bits/stdc++.h>
using namespace std;
int dp[100000];
char a[100000 + 1];
int main() {
  ios::sync_with_stdio(false);
  gets(a);
  int i, j, n;
  dp[0] = 1;
  n = strlen(a);
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (i = 1; i < n;) {
    if (a[i] == '0') {
      for (j = i + 1; a[j] == '0'; j++)
        ;
      if (i == 1)
        dp[j - 1] = 1;
      else if (j - i + 1 < i - 1)
        dp[j - 1] = dp[i - 2] + 1;
      else if (j - i + 1 > i - 1)
        dp[j - 1] = 1;
      else if (strncmp(a, a + i - 1, i - 1) >= 0)
        dp[j - 1] = dp[i - 2] + 1;
      else
        dp[j - 1] = 1;
      i = j;
    } else {
      if (i > 1 || a[0] >= a[1])
        dp[i] = dp[i - 1] + 1;
      else
        dp[i] = 1;
      i++;
    }
  }
  cout << dp[n - 1] << endl;
  return 0;
}
