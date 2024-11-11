#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
bool dp[MAX_N][2 * MAX_N];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  dp[0][k] = true;
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = (int)(1); j < (int)(2 * k); ++j) {
      if (!dp[i][j]) {
        continue;
      }
      if (s[i] == 'W') {
        if (i != n - 1 && j == 2 * k - 1) {
          dp[i + 1][j + 1] = false;
        } else {
          dp[i + 1][j + 1] = true;
        }
      } else if (s[i] == 'D') {
        dp[i + 1][j] = true;
      } else if (s[i] == 'L') {
        if (i != n - 1 && j == 1) {
          dp[i + 1][j - 1] = false;
        } else {
          dp[i + 1][j - 1] = true;
        }
      } else {
        if (i != n - 1 && j == 2 * k - 1) {
          dp[i + 1][j + 1] = false;
        } else {
          dp[i + 1][j + 1] = true;
        }
        dp[i + 1][j] = true;
        if (i != n - 1 && j == 1) {
          dp[i + 1][j - 1] = false;
        } else {
          dp[i + 1][j - 1] = true;
        }
      }
    }
  }
  if (dp[n][2 * k]) {
    int nw = 2 * k;
    string res;
    for (int i = 0; i < (int)(n); ++i) {
      res += '0';
    }
    for (int i = (int)(n)-1; i >= 0; --i) {
      if (s[i] == 'W') {
        --nw;
        res[i] = 'W';
      } else if (s[i] == 'D') {
        res[i] = 'D';
      } else if (s[i] == 'L') {
        ++nw;
        res[i] = 'L';
      } else {
        if (nw >= 1 && dp[i][nw - 1]) {
          --nw;
          res[i] = 'W';
        } else if (dp[i][nw]) {
          res[i] = 'D';
        } else {
          ++nw;
          res[i] = 'L';
        }
      }
    }
    cout << res << "\n";
    return 0;
  }
  if (dp[n][0]) {
    int nw = 0;
    string res;
    for (int i = 0; i < (int)(n); ++i) {
      res += '0';
    }
    for (int i = (int)(n)-1; i >= 0; --i) {
      if (s[i] == 'W') {
        --nw;
        res[i] = 'W';
      } else if (s[i] == 'D') {
        res[i] = 'D';
      } else if (s[i] == 'L') {
        ++nw;
        res[i] = 'L';
      } else {
        if (dp[i][nw + 1]) {
          ++nw;
          res[i] = 'L';
        } else if (dp[i][nw]) {
          res[i] = 'D';
        } else {
          --nw;
          res[i] = 'W';
        }
      }
    }
    cout << res << "\n";
    return 0;
  }
  cout << "NO\n";
  return 0;
}
