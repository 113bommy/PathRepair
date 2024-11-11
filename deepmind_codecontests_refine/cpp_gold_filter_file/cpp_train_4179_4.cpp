#include <bits/stdc++.h>
using namespace std;
const long long inf = 9e18;
int a[100005];
char s[100005];
long long dp[100005][5];
int main() {
  char c[6] = "hard ";
  int n;
  cin >> n;
  scanf(" %s", s + 1);
  for (int i = (1); i <= (n); ++i) {
    scanf("%d", a + i);
  }
  dp[n + 1][4] = inf;
  for (int i = (n); i >= (1); --i) {
    for (int j = (0); j <= (4); ++j) {
      dp[i][j] = inf;
      if (j == 4)
        dp[i][j] = inf;
      else {
        int first = s[i] == c[j] ? j + 1 : j;
        dp[i][j] = min(dp[i + 1][first], dp[i][j]);
        dp[i][j] = min(dp[i][j], dp[i + 1][j] + a[i]);
      }
    }
  }
  cout << dp[1][0];
  return 0;
}
