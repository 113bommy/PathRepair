#include <bits/stdc++.h>
using namespace std;
vector<int> kmp_auto_mata(string p) {
  vector<int> pma(p.length() + 1, 0);
  int j = pma[0] = -1;
  for (int i = 1; i <= p.length(); i++) {
    while (j >= 0 && p[i - 1] != p[j]) j = pma[j];
    pma[i] = ++j;
  }
  return pma;
}
vector<int> prv[111][111][111];
int main(int argc, char *argv[]) {
  string s, ss, virus;
  cin >> s >> ss >> virus;
  vector<int> pma = kmp_auto_mata(virus);
  int n = s.length(), m = ss.length(), v = virus.length();
  int dp[n + 1][m + 1][v + 1];
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k < v; k++) {
        if (dp[i][j][k] < 0) continue;
        vector<int> cur = {i, j, k};
        if (i < n && j < m && s[i] == ss[j]) {
          int nxtk = k;
          while (nxtk >= 0 && s[i] != virus[nxtk]) nxtk = pma[nxtk];
          nxtk++;
          if (dp[i + 1][j + 1][nxtk] < dp[i][j][k] + 1) {
            dp[i + 1][j + 1][nxtk] = dp[i][j][k] + 1;
            prv[i + 1][j + 1][nxtk] = cur;
          }
        }
        if (i < n && dp[i + 1][j][k] < dp[i][j][k]) {
          dp[i + 1][j][k] = dp[i][j][k];
          prv[i + 1][j][k] = cur;
        }
        if (j < m && dp[i][j + 1][k] < dp[i][j][k]) {
          dp[i][j + 1][k] = dp[i][j][k];
          prv[i][j + 1][k] = cur;
        }
      }
    }
  }
  int ans = 0, id = 0;
  for (int i = 0; i < v; i++) {
    if (ans < dp[n][m][i]) {
      ans = dp[n][m][i];
      id = i;
    }
  }
  vector<int> cur = {n, m, id};
  string res;
  while (cur[0] != 0 && cur[1] != 0) {
    vector<int> tmp = prv[cur[0]][cur[1]][cur[2]];
    if (tmp[0] + 1 == cur[0] && tmp[1] + 1 == cur[1]) {
      res += s[tmp[0]];
    }
    cur = tmp;
  }
  if (res.length() == 0) {
    std::cout << 0 << std::endl;
  } else {
    reverse(res.begin(), res.end());
    std::cout << res << std::endl;
  }
  return 0;
}
