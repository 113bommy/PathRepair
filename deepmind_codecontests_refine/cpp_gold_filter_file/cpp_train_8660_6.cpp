#include <bits/stdc++.h>
using namespace std;
const int N = 2005, M = 1e9 + 7;
int n, m;
string grid[N];
long long row[N][N], col[N][N];
long long dp[N][N][2];
long long rowdpsum[N][N][2];
long long coldpsum[N][N][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> grid[i];
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      row[i][j] = (grid[i][j] != 'R') + row[i][j + 1];
      col[i][j] = (grid[i][j] != 'R') + col[i + 1][j];
    }
  }
  if (grid[n - 1][m - 1] == 'R') {
    cout << 0 << endl;
    return 0;
  }
  if (n == 1 && m == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int j = m - 1; j >= 0; j--) {
    if (grid[n - 1][j] == 'R') break;
    coldpsum[n - 1][j][0] = dp[n - 1][j][0] = 1;
    coldpsum[n - 1][j][1] = dp[n - 1][j][1] = 1;
  }
  for (int j = m - 1; j >= 0; j--) {
    rowdpsum[n - 1][j][0] = dp[n - 1][j][0] + rowdpsum[n - 1][j + 1][0];
    rowdpsum[n - 1][j][1] = dp[n - 1][j][1] + rowdpsum[n - 1][j + 1][1];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (grid[i][m - 1] == 'R') break;
    rowdpsum[i][m - 1][1] = dp[i][m - 1][1] = 1;
    rowdpsum[i][m - 1][0] = dp[i][m - 1][0] = 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    coldpsum[i][m - 1][1] = dp[i][m - 1][1] + coldpsum[i + 1][m - 1][1];
    coldpsum[i][m - 1][0] = dp[i][m - 1][0] + coldpsum[i + 1][m - 1][0];
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = m - 2; j >= 0; j--) {
      for (int b = 0; b < 2; b++) {
        int nic = col[i + 1][j];
        int dan = row[i][j + 1];
        if (b && grid[i][j] == 'R') dan--;
        if (!b && grid[i][j] == 'R') nic--;
        dp[i][j][b] +=
            rowdpsum[i + 1][j + 1][0] + M - rowdpsum[i + 1][j + dan + 1][0];
        dp[i][j][b] +=
            coldpsum[i + 1][j + 1][1] + M - coldpsum[i + nic + 1][j + 1][1];
        dp[i][j][b] %= M;
        rowdpsum[i][j][b] = (dp[i][j][b] + rowdpsum[i][j + 1][b]) % M;
        coldpsum[i][j][b] = (dp[i][j][b] + coldpsum[i + 1][j][b]) % M;
      }
    }
  }
  cout << (dp[0][1][1] + dp[1][0][0]) % M << endl;
}
