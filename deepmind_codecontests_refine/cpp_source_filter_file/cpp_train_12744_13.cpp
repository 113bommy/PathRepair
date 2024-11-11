#include <bits/stdc++.h>
using namespace std;
int a[5005][5005], dp[5005][5005];
int main() {
  int t, i, j, n, m, ans, sum;
  char ch, str[5005];
  vector<int> vec;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    scanf("\n");
    gets(str);
    for (j = 1; j <= m; j++) a[i][j] = str[i] - '0';
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++)
      (a[i][j] == 1) ? dp[i][j] = dp[i][j - 1] + 1 : dp[i][j] = 0;
  }
  ans = 0;
  for (j = 1; j <= m; j++) {
    for (i = 1; i <= n; i++) vec.push_back(dp[i][j]);
    sort(vec.begin(), vec.end());
    for (i = 1; i <= n; i++) ans = max(ans, vec[i - 1] * (n - i + 1));
    vec.clear();
  }
  cout << ans;
  return 0;
}
