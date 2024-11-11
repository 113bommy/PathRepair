#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int dp[MAXN * 2][MAXN * 2][MAXN * 2][MAXN * 2];
vector<string> board;
int n, m;
int f(int min_sum, int max_sum, int min_sub, int max_sub, int type) {
  if (min_sum > max_sum || min_sub > max_sub) return 0;
  int &res = dp[min_sum][max_sum][min_sub + MAXN][max_sub + MAXN];
  if (res != -1) return res;
  vector<int> states;
  for (register int i = (0); i < (int)(n); ++i)
    for (register int j = (0); j < (int)(m); ++j)
      if ((i ^ j) % 2 == type && min_sum <= i + j && i + j <= max_sum &&
          min_sub <= i - j && i - j <= max_sub) {
        if (board[i][j] == 'X')
          states.push_back(f(i + j + 2, max_sum, i - j + 2, max_sub, type) ^
                           f(i + j + 2, max_sum, min_sub, i - j - 2, type) ^
                           f(min_sum, i + j - 2, i - j + 2, max_sub, type) ^
                           f(min_sum, i + j - 2, min_sub, i - j - 2, type));
        if (board[i][j] == 'R')
          states.push_back(f(min_sum, max_sum, i - j + 2, max_sub, type) ^
                           f(min_sum, max_sum, min_sub, i - j - 2, type));
        if (board[i][j] == 'L')
          states.push_back(f(i + j + 2, max_sum, min_sub, max_sub, type) ^
                           f(min_sum, i + j - 2, min_sub, max_sub, type));
      }
  sort((states).begin(), (states).end());
  for (int p = 0;; p++)
    if (binary_search((states).begin(), (states).end(), p) == false)
      return res = p;
}
int main() {
  ios::sync_with_stdio(false);
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  board.resize(n);
  for (register int i = (0); i < (int)(n); ++i) cin >> board[i];
  int res = f(0, n + m - 2, 1 - m, n - 1, 0) ^ f(0, n + m - 2, 1 - m, n - 1, 1);
  if (res)
    cout << "WIN"
         << "\n";
  else
    cout << "LOSE"
         << "\n";
  return 0;
}
