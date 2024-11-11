#include <bits/stdc++.h>
using namespace std;
map<char, string> m;
void populate() {
  m['0'] = "0000";
  m['1'] = "0001";
  m['2'] = "0010";
  m['3'] = "0011";
  m['4'] = "0100";
  m['5'] = "0101";
  m['6'] = "0110";
  m['7'] = "0111";
  m['8'] = "1000";
  m['9'] = "1001";
  m['A'] = "1010";
  m['B'] = "1011";
  m['C'] = "1100";
  m['D'] = "1101";
  m['E'] = "1110";
  m['F'] = "1111";
}
int main() {
  populate();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int d[n][n];
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    int l = 0;
    for (int j = 0; j < s.length(); j++) {
      string p = m[s[j]];
      for (int k = 0; k < 4; k++) {
        d[i][l++] = p[k] - '0';
      }
    }
  }
  int dp[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 1;
      else {
        if (d[i][j] == d[i - 1][j - 1] && d[i][j] == d[i - 1][j] &&
            d[i][j] == d[i][j - 1]) {
          dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        } else {
          dp[i][j] = 1;
        }
      }
    }
  }
  int ans = 1;
  for (int i = n; i > 1; i--) {
    if (n % i == 0) {
      bool poss = true;
      for (int j = i - 1; j < n; j += i) {
        for (int k = i - 1; k < n; k += i) {
          if (dp[j][k] < i) {
            poss = false;
            break;
          }
        }
        if (!poss) break;
      }
      if (poss) {
        ans = i;
        break;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
