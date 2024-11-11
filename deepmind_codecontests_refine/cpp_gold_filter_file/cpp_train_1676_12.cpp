#include <bits/stdc++.h>
using namespace std;
int dp[2][20005];
int x[20005];
int y[20005];
int DP[105][105];
int row[205][20005];
int col[20005][205];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  for (int i = 1; i <= n; ++i) cin >> x[i];
  for (int i = 1; i <= m; ++i) cin >> y[i];
  int pred = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int t = (x[i] + y[j]) % p;
      dp[(pred + 1) % 2][j] =
          max(dp[(pred + 1) % 2][j],
              max(dp[pred][j], dp[(pred + 1) % 2][j - 1]) + t);
      if (j % 100 == 0) col[i][j / 100] = dp[(pred + 1) % 2][j];
    }
    pred = (pred + 1) % 2;
    if (i % 100 == 0)
      for (int j = 1; j <= m; ++j) row[i / 100][j] = dp[pred][j];
  }
  cout << dp[pred][m] << '\n';
  int i = n, j = m;
  string answ = "";
  int test = (n + m - 2);
  while (test--) {
    for (int i = 0; i <= 100; ++i)
      for (int j = 0; j <= 100; ++j) DP[i][j] = 0;
    int posi = (i - 1) / 100, posj = (j - 1) / 100;
    for (int j1 = posj * 100; j1 <= min(m, (posj + 1) * 100); ++j1)
      DP[0][j1 - posj * 100] = row[posi][j1];
    for (int i1 = posi * 100; i1 <= min(n, (posi + 1) * 100); ++i1)
      DP[i1 - posi * 100][0] = col[i1][posj];
    for (int i1 = 1; i1 <= 100; ++i1) {
      for (int j1 = 1; j1 <= 100; ++j1)
        DP[i1][j1] = max(DP[i1][j1 - 1], DP[i1 - 1][j1]) +
                     (x[i1 + posi * 100] + y[j1 + posj * 100]) % p;
    }
    int xc = i - posi * 100, yc = j - posj * 100;
    if (j > 1 && DP[xc][yc] == DP[xc][yc - 1] + (x[i] + y[j]) % p)
      answ += "S", --j;
    else {
      answ += "C", --i;
    }
  }
  for (int i = (int)answ.size() - 1; i >= 0; --i) cout << answ[i];
  return 0;
}
