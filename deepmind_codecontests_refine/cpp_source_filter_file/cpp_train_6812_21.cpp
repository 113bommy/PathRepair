#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int arr[n + 1][m + 1];
  for (int i = 1; i < n + 1; i++) {
    string s;
    cin >> s;
    for (int j = 1; j < m + 1; j++) {
      arr[i][j] = ((int)s[j - 1]) - 48;
    }
  }
  int mod = k + 1;
  int dp[n + 1][m + 1][mod];
  int p[n + 1][m + 1][mod];
  int q[n + 1][m + 1][mod];
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= m; i++) {
    dp[n][i][arr[n][i] % mod] = arr[n][i];
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      for (int z = 0; z < mod; z++) {
        if (j == 1 && dp[i + 1][j + 1][z] >= 0) {
          int t = dp[i + 1][j + 1][z] + arr[i][j];
          if (dp[i][j][t % mod] < t) {
            p[i][j][t % mod] = -1;
            dp[i][j][t % mod] = t;
            q[i][j][t % mod] = z;
          }
        } else if (j == m && dp[i + 1][j - 1][z] >= 0) {
          int t = dp[i + 1][j - 1][z] + arr[i][j];
          if (dp[i][j][t % mod] < t) {
            dp[i][j][t % mod] = t;
            p[i][j][t % mod] = 1;
            q[i][j][t % mod] = z;
          }
        } else if (j != 1 && j != m) {
          if (dp[i + 1][j + 1][z] >= 0) {
            int t = dp[i + 1][j + 1][z] + arr[i][j];
            if (dp[i][j][t % mod] < t) {
              p[i][j][t % mod] = -1;
              dp[i][j][t % mod] = t;
              q[i][j][t % mod] = z;
            }
          }
          if (dp[i + 1][j - 1][z] >= 0) {
            int t = dp[i + 1][j - 1][z] + arr[i][j];
            if (dp[i][j][t % mod] < t) {
              p[i][j][t % mod] = 1;
              dp[i][j][t % mod] = t;
              q[i][j][t % mod] = z;
            }
          }
        }
      }
    }
  }
  int ans = 0;
  int in = -1;
  for (int i = 1; i <= m; i++) {
    if (dp[1][i][0] >= ans) {
      ans = dp[1][i][0];
      in = i;
    }
  }
  if (ans != 0)
    cout << ans << endl;
  else {
    cout << -1 << endl;
    return 0;
  }
  vector<int> path;
  int i = 1, j = in, z = 0;
  while (i < n) {
    path.push_back(p[i][j][z]);
    int tz = q[i][j][z];
    int jz = p[i][j][z];
    z = tz;
    j -= jz;
    i++;
  }
  cout << j << endl;
  for (i = path.size() - 1; i >= 0; i--) {
    if (path[i] == 1)
      cout << "R";
    else
      cout << "L";
  }
  cout << endl;
}
