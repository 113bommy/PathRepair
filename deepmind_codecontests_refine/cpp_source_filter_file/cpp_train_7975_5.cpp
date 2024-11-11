#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101;
const int MAXT = 2021;
int main() {
  int n;
  cin >> n;
  vector<pair<pair<int, int>, pair<int, int> > > tdp(n);
  for (int i = 0; i < n; ++i) {
    int t, d, p;
    cin >> t >> d >> p;
    tdp[i] = make_pair(make_pair(d, i), make_pair(t, p));
  }
  sort(tdp.begin(), tdp.end());
  int dp[MAXN][MAXT];
  pair<int, int> p[MAXN][MAXT];
  int b[MAXN][MAXT];
  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXT; ++j) {
      dp[i][j] = 0;
      p[i][j] = make_pair(i, j);
      b[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < MAXT; ++j) {
      if (j + tdp[i].second.first < tdp[i].first.first) {
        if (dp[i + 1][j + tdp[i].second.first] <
            dp[i][j] + tdp[i].second.second) {
          p[i + 1][j + tdp[i].second.first] = make_pair(i, j);
          dp[i + 1][j + tdp[i].second.first] = dp[i][j] + tdp[i].second.second;
          b[i + 1][j + tdp[i].second.first] = 1;
        }
      }
      {
        if (dp[i][j] > dp[i + 1][j]) {
          p[i + 1][j] = make_pair(i, j);
          dp[i + 1][j] = dp[i][j];
          b[i + 1][j] = 2;
        }
      }
    }
  }
  int cst_i = 0;
  for (int i = 0; i < MAXT; ++i) {
    if (dp[n][i] > dp[n][cst_i]) cst_i = i;
  }
  vector<int> sel;
  int j1 = cst_i;
  int j2 = 0;
  for (int i = n; i > 0; --i) {
    j2 = p[i][j1].second;
    if (dp[i][j2] + tdp[i - 1].second.second == dp[i][j1])
      sel.push_back(tdp[i - 1].first.second);
    j1 = j2;
  }
  reverse(sel.begin(), sel.end());
  cout << dp[n][cst_i] << endl;
  cout << (int)sel.size() << endl;
  for (int i = 0; i < (int)sel.size(); ++i) cout << sel[i] + 1 << " ";
  cout << endl;
  return 0;
}
