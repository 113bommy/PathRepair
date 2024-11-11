#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e3 + 100;
int n, m, dp[4][nmax][nmax], a[nmax][nmax], marked[2][nmax][nmax];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> m >> n;
  char c;
  for (int i = (int)1; i <= (int)m; i++)
    for (int j = (int)1; j <= (int)n; j++) {
      cin >> c;
      a[i][j] = (c == '*');
    }
  for (int i = (int)1; i <= (int)m; i++)
    for (int j = (int)1; j <= (int)n; j++)
      if (a[i][j])
        dp[0][i][j] = dp[0][i - 1][j] + a[i][j],
        dp[1][i][j] = dp[1][i][j - 1] + a[i][j];
  for (int i = (int)m; i >= (int)1; i--)
    for (int j = (int)n; j >= (int)1; j--)
      if (a[i][j])
        dp[2][i][j] = dp[2][i + 1][j] + a[i][j],
        dp[3][i][j] = dp[3][i][j + 1] + a[i][j];
  vector<pair<int, pair<int, int> > > res(0);
  for (int i = (int)1; i <= (int)m; i++)
    for (int j = (int)1; j <= (int)n; j++)
      if (a[i][j]) {
        int k =
            min(dp[0][i - 1][j],
                min(dp[1][i][j - 1], min(dp[2][i + 1][j], dp[3][i][j + 1])));
        if (!k) continue;
        marked[0][i - k][j]++, marked[0][i + k + 1][j]--;
        marked[1][i][j - k]++, marked[1][i][j + k + 1]--;
        res.push_back(make_pair(i, make_pair(j, k)));
      }
  for (int i = (int)1; i <= (int)m; i++)
    for (int j = (int)1; j <= (int)n; j++) {
      marked[0][i][j] += marked[0][i - 1][j],
          marked[1][i][j] += marked[1][i][j - 1];
      if (a[i][j] && !marked[0][i][j] && !marked[1][i][j]) {
        cout << -1;
        return 0;
      }
    }
  cout << res.size() << "\n";
  for (int i = (int)0; i <= (int)res.size() - 1; i++)
    cout << res[i].first << " " << res[i].second.first << " "
         << res[i].second.second << "\n";
}
