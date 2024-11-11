#include <bits/stdc++.h>
using namespace std;
const int maxN = 550;
int n, k;
int c[maxN];
bool dp[maxN][maxN][maxN];
vector<int> vec;
int ans;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> c[i];
  dp[0][0][0] = true;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++)
      for (int l = 0; l <= j; l++) {
        if (dp[i - 1][j][l] || (j >= c[i] && dp[i - 1][j - c[i]][l]) ||
            (j >= c[i] && l >= c[i] && dp[i - 1][j - c[i]][l - c[i]]))
          dp[i][j][l] = true;
      }
  for (int i = 0; i <= k; i++)
    if (dp[n][k][i]) {
      ans++;
      vec.push_back(i);
    }
  cout << ans << endl;
  for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
  cout << '\n';
}
