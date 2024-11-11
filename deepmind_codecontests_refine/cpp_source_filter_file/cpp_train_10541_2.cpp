#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 505;
int n;
int k;
string str;
int f[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int wdp[MAX_N][MAX_N];
int main() {
  cin >> str;
  cin >> k;
  n = str.size();
  memset(f, 0, sizeof(f));
  for (int sz = 2; sz <= n; ++sz)
    for (int i = 0; i + sz - 1 < n; ++i) {
      int j = i + sz - 1;
      f[i][j] = f[i + 1][j - 1];
      if (str[i] != str[j]) ++f[i][j];
    }
  for (int i = 0; i < n; ++i) {
    dp[i][0] = f[0][i];
    wdp[i][0] = -1;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 1; j <= k; ++j) {
      dp[i][j] = f[0][i];
      wdp[i][j] = -1;
      for (int i2 = 1; i2 <= i; ++i2) {
        int nval = dp[i2 - 1][j - 1] + f[i2][i];
        if (nval < dp[i][j]) {
          dp[i][j] = nval;
          wdp[i][j] = i2 - 1;
        }
      }
    }
  int r = 987654321;
  for (int j = 0; j <= k; ++j) r = min(r, dp[n - 1][j]);
  cout << r << endl;
  int j = 0;
  for (; j <= k; ++j)
    if (dp[n - 1][j] == r) break;
  int a = n - 1;
  int b = j;
  string res = "";
  while (a != -1) {
    int na = wdp[a][b];
    string s = "";
    for (int i = na + 1; i <= a; ++i) s += str[i];
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      if (s[left] != s[right]) s[left] = s[right];
      ++left;
      --right;
    }
    res += s;
    res += '+';
    a = na;
    --b;
  }
  res = res.substr(0, res.size() - 1);
  for (int i = res.size() - 1; i >= 0; --i) cout << res[i];
  cout << endl;
  return 0;
}
