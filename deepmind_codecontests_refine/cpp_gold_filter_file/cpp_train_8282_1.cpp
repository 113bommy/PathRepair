#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  char c;
  int dp1[n], dp2[n], dp3[n];
  for (int i = 0; i < n; i++) {
    dp1[i] = dp2[i] = dp3[i] = 5000;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int pos = min(j, (m - 1 - j) + 1);
      c = s[i][j];
      int k = c - '0';
      if (c == '*' || c == '#' || c == '&') {
        dp2[i] = min(dp2[i], pos);
      } else if (0 <= k && k <= 9) {
        dp3[i] = min(dp3[i], pos);
      } else if ('a' <= c && c <= 'z') {
        dp1[i] = min(dp1[i], pos);
      }
    }
  }
  int ans = 5000;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        for (int k = 0; k < n; k++) {
          if (k != j && k != i) {
            ans = min(ans, dp1[i] + dp2[j] + dp3[k]);
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
