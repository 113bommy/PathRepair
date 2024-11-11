#include <bits/stdc++.h>
using namespace std;
int n, m;
double dp[2001][2001];
bool g[2001][2001];
double solve(int ur, int uc) {
  if (ur == 0 && uc == 0) return 0;
  if (dp[ur][uc] >= 0) return dp[ur][uc];
  int c1, c2, c3, rem;
  c1 = ur * uc;
  c2 = ur * (n - uc);
  c3 = uc * (n - ur);
  rem = n * n - (c1 + c2 + c3);
  dp[ur][uc] = 0;
  double ex = 0;
  if (ur > 0 && uc > 0)
    ex += (double)c1 / (c1 + c2 + c3) * (1 + solve(ur - 1, uc - 1));
  if (ur > 0) ex += (double)c2 / (c1 + c2 + c3) * (1 + solve(ur - 1, uc));
  if (uc > 0) ex += (double)c3 / (c1 + c2 + c3) * (1 + solve(ur, uc - 1));
  dp[ur][uc] = (double)rem / (n * n - rem) + ex;
  return dp[ur][uc];
}
int main() {
  for (int i = 0; i < 2001; i++)
    for (int j = 0; j < 2001; j++) dp[i][j] = -1;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a][b] = true;
  }
  int ur = 0, uc = 0;
  for (int i = 1; i <= n; i++) {
    bool isuc = true;
    for (int j = 1; j <= n; j++) {
      if (g[i][j] == true) {
        isuc = false;
        break;
      }
    }
    if (isuc) ur++;
  }
  for (int i = 1; i <= n; i++) {
    bool isuc = true;
    for (int j = 1; j <= n; j++) {
      if (g[j][i] == true) {
        isuc = false;
        break;
      }
    }
    if (isuc) uc++;
  }
  cout << solve(ur, uc);
  return 0;
}
