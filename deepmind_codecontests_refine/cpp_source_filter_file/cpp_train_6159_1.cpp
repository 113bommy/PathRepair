#include <bits/stdc++.h>
using namespace std;
int lps[2][101];
void complps(string second, int i) {
  int k = 0, j = 0;
  lps[i][0] = 0;
  for (j = 1; j < second.length(); ++j) {
    while (k > 0 && second[k] != second[j]) k = lps[i][k - 1];
    if (second[k] == second[j]) ++k;
    lps[i][j] = k;
  }
}
string second;
string s2, s3;
int dp[1001][51][51];
int func(int pos, int i, int j) {
  int ans = 0;
  if (dp[pos][i][j] != -1e9) return dp[pos][i][j];
  if (i == s2.length()) {
    ++ans;
  }
  if (j == s3.length()) {
    --ans;
  }
  if (pos == second.length()) return dp[pos][i][j] = ans;
  int xx = i, yy = j;
  if (i == s2.length()) {
    i = lps[0][i - 1];
  }
  if (j == s3.length()) {
    j = lps[1][j - 1];
  }
  if (second[pos] == '*') {
    int ans2 = -1e9, x, y;
    for (char c = 'a'; c <= 'z'; ++c) {
      second[pos] = c;
      x = i, y = j;
      while (i > 0 && second[pos] != s2[i]) {
        i = lps[0][i - 1];
      }
      if (second[pos] == s2[i]) ++i;
      while (j > 0 && second[pos] != s3[j]) {
        j = lps[1][j - 1];
      }
      if (second[pos] == s3[j]) ++j;
      ans2 = max(ans2, func(pos + 1, i, j));
      i = x, j = y;
    }
    second[pos] = '*';
    return dp[pos][xx][yy] = ans + ans2;
  } else {
    while (i > 0 && second[pos] != s2[i]) {
      i = lps[0][i - 1];
    }
    if (second[pos] == s2[i]) ++i;
    while (j > 0 && second[pos] != s3[j]) {
      j = lps[1][j - 1];
    }
    if (second[pos] == s3[j]) ++j;
    return dp[pos][xx][yy] = ans + func(pos + 1, i, j);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int T;
  T = 1;
  while (T--) {
    cin >> second >> s2 >> s3;
    int n, i, j;
    for (i = 0; i <= 1000; ++i) {
      for (j = 0; j <= 50; ++j) {
        for (n = 0; n <= 50; ++n) dp[i][j][n] = -1e9;
      }
    }
    complps(s2, 0);
    complps(s3, 0);
    cout << func(0, 0, 0) << endl;
  }
  return 0;
}
