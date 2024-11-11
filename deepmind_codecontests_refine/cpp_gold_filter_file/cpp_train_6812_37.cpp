#include <bits/stdc++.h>
using namespace std;
int n, m, l;
string s[110];
int a[110][110];
int dp[110][110][20];
char pnt[110][110][20];
int pntK[110][110][20];
vector<char> v;
int main() {
  int i, j, k;
  cin >> n >> m >> l;
  l++;
  for (i = 0; i < n; i++) cin >> s[i];
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) a[i + 1][j + 1] = s[i][j] - '0';
  for (i = 0; i <= n + 1; i++)
    for (j = 0; j <= m + 1; j++)
      for (k = 0; k <= l; k++) dp[i][j][k] = -1;
  for (j = 1; j <= m; j++) dp[n][j][a[n][j] % l] = (a[n][j]);
  for (i = n - 1; i > 0; i--)
    for (j = 1; j <= m; j++)
      for (k = 0; k < l; k++) {
        if (dp[i + 1][j - 1][k] >= 0 &&
            (dp[i][j][(a[i][j] + k) % l] < a[i][j] + dp[i + 1][j - 1][k])) {
          dp[i][j][(a[i][j] + k) % l] = a[i][j] + dp[i + 1][j - 1][k];
          pnt[i][j][(a[i][j] + k) % l] = 'L';
          pntK[i][j][(a[i][j] + k) % l] = k;
        }
        if (dp[i + 1][j + 1][k] >= 0 &&
            (dp[i][j][(a[i][j] + k) % l] < a[i][j] + dp[i + 1][j + 1][k])) {
          dp[i][j][(a[i][j] + k) % l] = a[i][j] + dp[i + 1][j + 1][k];
          pnt[i][j][(a[i][j] + k) % l] = 'R';
          pntK[i][j][(a[i][j] + k) % l] = k;
        }
      }
  int ans = -100;
  int idx = 0;
  for (j = 1; j <= m; j++) {
    if (ans < dp[1][j][0]) {
      idx = j;
      ans = dp[1][j][0];
    }
  }
  if (ans < 0) {
    cout << -1 << endl;
    return 0;
  }
  int d = 1;
  k = 0;
  while (d < n) {
    if (pnt[d][idx][k] == 'L') {
      v.push_back('R');
      k = pntK[d][idx][k];
      idx--;
      d++;
    } else {
      v.push_back('L');
      k = pntK[d][idx][k];
      idx++;
      d++;
    }
  }
  cout << ans << endl;
  cout << idx << endl;
  for (i = v.size() - 1; i >= 0; i--) cout << v[i];
}
