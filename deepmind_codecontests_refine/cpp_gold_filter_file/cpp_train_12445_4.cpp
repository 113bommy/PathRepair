#include <bits/stdc++.h>
using namespace std;
const int N = 5007;
int dp[N][N];
int a[N];
int main() {
  int n, k;
  cin >> n >> k;
  dp[0][0]++;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int x = a[i];
    for (int j = k; j >= 0; j--)
      for (int q = 0; q <= j; q++)
        if (dp[j][q]) {
          dp[j + x][q + x]++;
          dp[j + x][q]++;
        }
  }
  vector<int> ans;
  for (int i = 0; i <= k; i++)
    if (dp[k][i]) ans.push_back(i);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
