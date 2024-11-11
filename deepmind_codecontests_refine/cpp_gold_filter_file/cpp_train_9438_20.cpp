#include <bits/stdc++.h>
using namespace std;
int n, k;
unsigned long long l[51];
unsigned long long acc[51];
bool dp[51][51];
bool check(unsigned long long a) {
  memset(dp, 0, sizeof dp);
  dp[0][0] = true;
  for (int i = 1; i < k + 1; i++)
    for (int j = 0; j < n; j++)
      if (dp[i - 1][j])
        for (int c = j + 1; c < n + 1; c++) {
          if (n - c < k - i - 1) {
            break;
          }
          if (((acc[c] - acc[j]) & a) >= a) {
            dp[i][c] = true;
          }
        }
  return dp[k][n];
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> l[i];
  acc[0] = 0;
  acc[1] = l[0];
  for (int i = 1; i < n + 1; i++) acc[i] = acc[i - 1] + l[i - 1];
  unsigned long long ans = 0;
  unsigned long long a = 0;
  for (int i = 63; i >= 0; i--) {
    a = (unsigned long long)1 << i;
    if (check(ans | a)) {
      ans |= a;
    }
  }
  cout << ans;
  return 0;
}
