#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m;
  int s[5000 + 5], dp[5000 + 5];
  double x;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i] >> x;
  s[n] = m + 1;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= n; dp[i++]++)
    for (int j = 0; j <= n; j++)
      if (s[i] >= s[j]) dp[i] = max(dp[i], dp[j]);
  cout << n - dp[n - 1] << endl;
  return 0;
}
