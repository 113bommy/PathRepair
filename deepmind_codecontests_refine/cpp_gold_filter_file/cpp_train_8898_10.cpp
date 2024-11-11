#include <bits/stdc++.h>
using namespace std;
int dp[105][105][2];
int p[105];
void kmp(string str) {
  p[0] = -1;
  int pos = -1;
  for (int i = 1; i < str.size(); i++) {
    while (pos != -1 && str[i] != str[pos + 1]) {
      pos = p[pos];
    }
    if (str[i] == str[pos + 1]) {
      pos++;
    }
    p[i] = pos;
  }
}
void DFS(int n, int pos) {
  if (n) {
    DFS(n - 1, dp[n][pos][0]);
    cout << (char)dp[n][pos][1];
  }
}
int main() {
  int n, kk, m;
  string str, str2;
  cin >> n >> kk;
  cin >> str;
  m = str.size();
  str += '$';
  cin >> str2;
  kmp(str);
  memset(dp, -1, sizeof dp);
  dp[0][0][0] = -2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < str.size(); j++) {
      if (dp[i][j][0] == -1) {
        continue;
      }
      for (int k = 'a'; k < 'a' + kk; k++) {
        int pos = j - 1;
        while (pos != -1 && k != str[pos + 1]) {
          pos = p[pos];
        }
        if (k == str[pos + 1]) {
          pos++;
        }
        pos++;
        if (pos == m && str2[i + 1 - m] == '1') {
          dp[i + 1][pos][0] = j;
          dp[i + 1][pos][1] = k;
        } else if (pos != m && (i + 1 - m < 0 || str2[i + 1 - m] == '0')) {
          dp[i + 1][pos][0] = j;
          dp[i + 1][pos][1] = k;
        }
      }
    }
  }
  for (int i = 0; i < str.size(); i++) {
    if (dp[n][i][0] != -1) {
      DFS(n, i);
      cout << endl;
      return 0;
    }
  }
  cout << "No solution\n";
  return 0;
}
