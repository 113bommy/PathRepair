#include <bits/stdc++.h>
using namespace std;
string s[100];
string ans[2 * 100 - 1];
int n;
int dp[110][110];
int check(int dx, int dy) {
  if (dp[dx + 55][dy + 55] != -1) return dp[dx + 55][dy + 55];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == 'o') {
        if (i + dx >= n || j + dy >= n) continue;
        if (i + dx < 0 || j + dy < 0) continue;
        if (s[i + dx][j + dy] == '.') {
          return dp[i + 55][j + 55] = 0;
        }
      }
    }
  }
  return dp[dx + 55][dy + 55] = 1;
}
int main() {
  int cnt = 0;
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 0; i < 2 * n - 1; ++i) {
    for (int j = 0; j < 2 * n - 1; ++j) {
      ans[i] += '.';
    }
  }
  ans[n - 1][n - 1] = 'o';
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == 'o') {
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < n; ++l) {
            if (s[k][l] == 'x' && check((k - i), (l - j))) {
              ans[n - 1 + (k - i)][n - 1 + (l - j)] = 'x';
              s[k][l] = 'z';
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == 'x') {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < 2 * n - 1; ++i) {
    cout << ans[i] << endl;
  }
}
