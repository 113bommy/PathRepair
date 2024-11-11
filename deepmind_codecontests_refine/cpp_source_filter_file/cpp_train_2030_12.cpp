#include <bits/stdc++.h>
using namespace std;
bool dp[1007][1007];
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> kol(1000, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    kol[x % m]++;
  }
  if (kol[0] != 0) {
    cout << "YES";
    return 0;
  }
  vector<pair<int, int> > x;
  int mxk = 0;
  for (int i = 1; i < m; i++) {
    if (kol[i] >= m && kol[i] % m == 0) {
      cout << "YES";
      return 0;
    }
    if (kol[i]) {
      x.push_back({i, kol[i]});
      mxk = i;
    }
  }
  n = x.size();
  for (int i = 0; i <= n; i++) dp[i][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m * mxk; j++) {
      dp[i][j] = dp[i - 1][j];
      for (int z = 1; z <= min(x[i - 1].second, j / x[i - 1].first); z++)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - z * x[i - 1].first]);
    }
  for (int i = 1; i <= mxk; i++)
    if (dp[n][m * i]) {
      cout << "YES";
      return 0;
    }
  cout << "NO";
}
