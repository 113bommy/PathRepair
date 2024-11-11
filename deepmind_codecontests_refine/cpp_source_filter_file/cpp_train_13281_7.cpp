#include <bits/stdc++.h>
using namespace std;
const long long p = 239;
const int ma = 16 * 1024;
int n, dp[76][76][76][3];
vector<int> pos[3];
string s;
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'V')
      pos[0].push_back(i);
    else if (s[i] == 'K')
      pos[1].push_back(i);
    else
      pos[2].push_back(i);
  }
  for (int i = 0; i < (int)pos[0].size() + 1; i++) {
    for (int j = 0; j < (int)pos[1].size() + 1; j++) {
      for (int k = 0; k < (int)pos[2].size() + 1; k++) {
        if (i + j + k == 0) continue;
        int cnti = i - 1, cntj = j - 1, cntk = k - 1;
        for (int p = 0; p < j; p++) {
          if (i && pos[1][p] < pos[0][i - 1]) cnti++;
          if (k && pos[1][p] < pos[2][k - 1]) cntk++;
        }
        for (int p = 0; p < i; p++) {
          if (j && pos[0][p] < pos[1][j - 1]) cntj++;
          if (k && pos[0][p] < pos[2][k - 1]) cntk++;
        }
        for (int p = 0; p < k; p++) {
          if (i && pos[2][p] < pos[0][i - 1]) cnti++;
          if (j && pos[2][p] < pos[1][j - 1]) cntj++;
        }
        for (int q = 0; q < 3; q++) dp[i][j][k][q] = int(1e9);
        if (i)
          dp[i][j][k][0] = min(dp[i - 1][j][k][0],
                               min(dp[i - 1][j][k][1], dp[i - 1][j][k][2])) +
                           max(pos[0][i - 1] - cnti, 0);
        if (j)
          dp[i][j][k][1] = min(dp[i][j - 1][k][1], dp[i][j - 1][k][2]) +
                           max(pos[1][j - 1] - cntj, 0);
        if (k)
          dp[i][j][k][2] = min(dp[i][j][k - 1][0],
                               min(dp[i][j][k - 1][1], dp[i][j][k - 1][2])) +
                           max(pos[2][k - 1] - cntk, 0);
      }
    }
  }
  cout << min(min(dp[(int)pos[0].size()][(int)pos[1].size()][(int)pos[2].size()]
                    [0],
                  dp[(int)pos[0].size()][(int)pos[1].size()][(int)pos[2].size()]
                    [1]),
              dp[(int)pos[0].size()][(int)pos[1].size()][(int)pos[2].size()][0])
       << "\n";
}
