#include <bits/stdc++.h>
using namespace std;
string a, b;
int main() {
  cin >> a >> b;
  int n = a.size(), m = b.size();
  int dp[222][222];
  int c[155], c2[222];
  for (int i = 0; i < n; i++) c[a[i] - 'a']++;
  for (int i = 0; i < m; i++) c2[b[i] - 'a']++;
  for (int i = 0; i < 26; i++)
    if (c[i] < c2[i]) {
      cout << "need tree\n";
      return 0;
    }
  bool aa = 0;
  for (int i = 0; i < 26; i++) {
    if (c[i] > c2[i]) aa = 1;
  }
  if (aa == 0) {
    cout << "array\n";
    return 0;
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
      if (a[i] == b[j]) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      }
    }
  }
  if (dp[n][m] == m)
    cout << "automaton\n";
  else
    cout << "both\n";
}
