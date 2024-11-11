#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  string s[2];
  cin >> s[0];
  cin >> s[1];
  long long n = s[0].length(), i, dp[n][3], c = 0;
  for (i = 0; i < n - 1; ++i) {
    if (s[0][i] == 'X' && s[1][i] == '0') {
      if (s[0][i + 1] == '0' && s[1][i + 1] == '0') {
        s[0][i + 1] = 'X';
        s[1][i + 1] = 'X';
        c++;
      }
    }
    if (s[0][i] == '0' && s[1][i] == 'X') {
      if (s[0][i + 1] == '0' && s[1][i + 1] == '0') {
        s[0][i + 1] = 'X';
        s[1][i + 1] = 'X';
        c++;
      }
    }
    if (s[0][i] == '0' && s[1][i] == '0') {
      if (s[0][i + 1] == '0' && s[1][i + 1] == '0') {
        s[0][i + 1] = 'X';
        s[1][i + 1] = '0';
        c++;
      } else if (s[0][i + 1] == 'X' && s[1][i + 1] == '0') {
        s[1][i + 1] = '0';
        c++;
      } else if (s[0][i + 1] == '0' && s[1][i + 1] == 'X') {
        s[1][i + 1] = 'X';
        c++;
      }
    }
  }
  cout << c;
}
