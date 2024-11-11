#include <bits/stdc++.h>
using namespace std;
int main() {
  string w;
  cin >> w;
  int len = w.length();
  int n, k;
  cin >> k;
  cin >> n;
  int pf[30][30];
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) pf[i][j] = 0;
  }
  for (int i = 0; i < n; i++) {
    char c, d;
    int pr;
    cin >> c >> d >> pr;
    pf[(int)c - (int)'a'][(int)d - (int)'a'] = pr;
  }
  int dp[30][k + 5];
  int minn = -1000000000;
  for (int i = 0; i < 26; i++) {
    for (int ch = 0; ch <= k; ch++) dp[i][ch] = minn;
  }
  dp[(int)w[0] - (int)'a'][0] = 0;
  for (int i = 0; i < 26; i++) {
    if (char(97 + i) != w[0]) dp[i][1] = 0;
  }
  for (int i = 1; i < len; i++) {
    int tdp[30][k + 5];
    for (int j = 0; j < 26; j++) {
      for (int ch = 0; ch <= k; ch++) tdp[j][ch] = minn;
    }
    for (int j = 0; j < 26; j++) {
      for (int pre = 0; pre < 26; pre++) {
        if (w[i] != char(97 + j)) {
          for (int ch = 0; ch <= min(k - 1, i); ch++) {
            tdp[j][ch + 1] = max(tdp[j][ch + 1], dp[pre][ch] + pf[pre][j]);
          }
        } else {
          for (int ch = 0; ch <= min(i, k); ch++) {
            tdp[j][ch] = max(tdp[j][ch], dp[pre][ch] + pf[pre][j]);
          }
        }
      }
    }
    for (int j = 0; j < 26; j++) {
      for (int ch = 0; ch <= k; ch++) dp[j][ch] = tdp[j][ch];
    }
  }
  int mx = INT_MIN;
  for (int i = 0; i < 26; i++) {
    for (int ch = 0; ch <= k; ch++) mx = max(mx, dp[i][ch]);
  }
  cout << mx << endl;
}
