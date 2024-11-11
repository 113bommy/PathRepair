#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  bool dp[2000][2000];
  for (int i = 0; i < 2000; i++) {
    for (int j = 1; j < 2000; j++) dp[i][j] = false;
    dp[i][0] = true;
  }
  cin >> s;
  long long st[2000], e[2000];
  for (int i = 0; i < s.length(); i++) st[i] = e[i] = 1;
  for (int i = 0; i < s.length() - 1; i++)
    if (s[i] == s[i + 1]) {
      st[i]++;
      e[i + 1]++;
      dp[i][1] = true;
    }
  for (int i = 2; i < s.length(); i++) {
    for (int j = 0; j < s.length() - i; j++) {
      if (dp[j + 1][i - 2] && s[j] == s[j + i]) {
        dp[j][i] = true;
        st[j]++;
        e[j + i]++;
      }
    }
  }
  long long res = 0;
  for (int i = s.length() - 1; i >= 0; i--) st[i] += st[i + 1];
  long long x = 0;
  for (int i = 0; i < s.length() - 1; i++) {
    res += e[i] * st[i + 1];
  }
  cout << res;
  return 0;
}
