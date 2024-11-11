#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int n = s.size();
  bool dp[n][n], prvs[n][n], pal[n][n];
  vector<long long> cnt(15, 0);
  bool fp;
  long mx[n][n];
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      dp[i][j] = false;
      prvs[i][j] = false;
      mx[i][j] = 0;
      pal[i][j] = false;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j > i; j--) {
      if (s[i] == s[j]) {
        if (j < n - 1)
          mx[i][j] = 1 + mx[i + 1][j + 1];
        else
          mx[i][j] = 1;
      }
    }
  }
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i < n; i++) {
      if (i + len - 1 >= n) break;
      if (s[i] == s[i + len - 1]) {
        if (len <= 2)
          pal[i][i + len - 1] = true;
        else if (len > 2)
          pal[i][i + len - 1] = (true && pal[i + 1][i + len - 2]);
      }
    }
  }
  for (int k = 1; k < 15; k++) {
    for (int i = 0; i < n; i++) {
      for (int len = 1 << (k - 1); len <= n; len++) {
        if (i + len - 1 >= n) break;
        if (k == 1) {
          if (pal[i][i + len - 1]) dp[i][i + len - 1] = true;
        } else if (prvs[i][i + len / 2 - 1] &&
                   prvs[i + len - len / 2][i + len - 1]) {
          if (mx[i][i + len - len / 2] >= len / 2) dp[i][i + len - 1] = true;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        prvs[i][j] = dp[i][j];
        if (dp[i][j]) cnt[k]++;
        dp[i][j] = false;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i < 15)
      cout << cnt[i] << " ";
    else
      cout << 0 << " ";
  }
  cout << endl;
}
