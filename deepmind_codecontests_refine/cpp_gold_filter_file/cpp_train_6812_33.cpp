#include <bits/stdc++.h>
using namespace std;
bool dp[101][101][1000];
int arr[101][101];
int M;
void printPath(int n, int m, int s) {
  if (n == 0) {
    cout << M - m << endl;
    return;
  }
  if (m > 0 && dp[n - 1][m - 1][s - arr[n][m]]) {
    printPath(n - 1, m - 1, s - arr[n][m]);
    cout << "L";
  } else {
    printPath(n - 1, m + 1, s - arr[n][m]);
    cout << "R";
  }
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  M = m;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    for (int j = 0; j < m; j++) arr[n - 1 - i][m - 1 - j] = t[j] - '0';
  }
  for (int i = 0; i < m; i++) dp[0][i][arr[0][i]] = true;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int s = 0; s < 1000; s++)
        dp[i][j][s] =
            ((j > 0 && s - arr[i][j] >= 0 ? dp[i - 1][j - 1][s - arr[i][j]]
                                          : false) ||
             (j < m - 1 && s - arr[i][j] >= 0 ? dp[i - 1][j + 1][s - arr[i][j]]
                                              : false));
  int pos = -1, ans = 0;
  for (int i = 0; i < m; i++)
    for (int s = 0; s < 1000; s += (k + 1))
      if (dp[n - 1][i][s] && ans <= s) {
        ans = s;
        pos = i;
      }
  if (pos != -1) {
    cout << ans << endl;
    printPath(n - 1, pos, ans);
  } else
    cout << -1;
  return 0;
}
