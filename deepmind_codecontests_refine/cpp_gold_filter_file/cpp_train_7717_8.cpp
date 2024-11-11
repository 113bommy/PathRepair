#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[5005][5005][2];
map<int, int> mp;
int main() {
  int n;
  cin >> n;
  v.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) dp[i][i][0] = dp[i][i][1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j >= 1; j--) {
      for (int col = 0; col < 2; col++) {
        int it = (col ? v[i] : v[j]);
        if (j >= 2) {
          dp[j - 1][i][0] =
              min(dp[j - 1][i][0], dp[j][i][col] + (v[j - 1] != it));
        }
        if (i < n) {
          dp[j][i + 1][1] =
              min(dp[j][i + 1][1], dp[j][i][col] + (it != v[i + 1]));
        }
      }
    }
  }
  cout << min(dp[1][n][0], dp[1][n][1]) << endl;
  return 0;
}
