#include <bits/stdc++.h>
using namespace std;
const int MAX_S = 2005;
int nxt[MAX_S], dp[MAX_S][MAX_S];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, p;
  cin >> s >> p;
  memset(nxt, -1, sizeof(nxt));
  for (int i = 0; i < s.size(); i++) {
    int indInS = i, indInP = 0;
    while (indInS < s.size() && indInP < p.size()) {
      if (s[indInS] == p[indInP]) {
        indInS++;
        indInP++;
      } else {
        indInS++;
      }
    }
    if (indInP == p.size()) {
      nxt[i + 1] = indInS + 1;
    }
  }
  memset(dp, -1, sizeof(dp));
  dp[s.size() + 1][0] = 0;
  for (int i = s.size(); i >= 0; i--) {
    for (int j = 0; j <= s.size() - i + 1; j++) {
      dp[i][j] = max(dp[i][j], dp[i + 1][j]);
      if (j > 0 && i != 0) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j - 1]);
      }
      if (nxt[i] != -1) {
        int aux = nxt[i] - i - p.size();
        if (j >= aux && dp[nxt[i]][j - aux] != -1) {
          dp[i][j] = max(dp[i][j], dp[nxt[i]][j - aux] + 1);
        }
      }
    }
  }
  for (int i = 0; i <= s.size() - 1; i++) {
    cout << dp[0][i] << " ";
  }
  cout << 0 << '\n';
  return 0;
}
