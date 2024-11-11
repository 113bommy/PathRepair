#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  bool dp[505][505];
  cin >> n >> k;
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    for (int j = k; j >= 0; j--)
      for (int y = k; y >= 0; y--) {
        if (dp[j][y]) {
          if (j + l <= k) dp[j + l][y] = 1;
          if (y + l <= k) dp[j][y + l] = 1;
        }
      }
  }
  vector<int> ans;
  for (int i = 0; i <= k; i++)
    if (dp[i][k - i]) ans.push_back(i);
  cout << int(ans.size()) << "\n";
  for (int i = 0; i < int(ans.size()); i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
