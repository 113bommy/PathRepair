#include <bits/stdc++.h>
using namespace std;
const int maxn = 2016;
int n, m;
string s;
int dp[maxn][maxn];
int& DP(int i, int j) { return dp[i][j + maxn / 2]; }
void SolveW(int i, int j) {
  if (j > -m && j < m && DP(i - 1, j) != -1) {
    DP(i, j + 1) = 'W';
  }
}
void SolveL(int i, int j) {
  if (j > -m && j < m && DP(i - 1, j) != -1) {
    DP(i, j - 1) = 'L';
  }
}
void SolveD(int i, int j) {
  if (j > -m && j < m && DP(i - 1, j) != -1) {
    DP(i, j) = 'D';
  }
}
void Trace(int i, int j) {
  if (i == 0) return;
  if (DP(i, j) == 'W') {
    Trace(i - 1, j - 1);
    cout << "W";
  } else if (DP(i, j) == 'L') {
    Trace(i - 1, j + 1);
    cout << "L";
  } else {
    Trace(i - 1, j);
    cout << "D";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> s;
  s = ' ' + s;
  fill_n(&dp[0][0], maxn * maxn, -1);
  DP(0, 0) = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = -m; j <= m; j++) {
      if (s[i] == 'W')
        SolveW(i, j - 1);
      else if (s[i] == 'L')
        SolveL(i, j + 1);
      else if (s[i] == 'D')
        SolveD(i, j);
      else {
        SolveW(i, j - 1);
        SolveL(i, j + 1);
        SolveD(i, j);
      }
    }
  }
  if (DP(n, m) == -1 && DP(n, -m) == -1) return cout << "NO", 0;
  if (DP(n, m) != -1)
    Trace(n, m);
  else
    Trace(n, -m);
}
