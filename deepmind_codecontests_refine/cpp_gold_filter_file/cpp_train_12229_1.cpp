#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-9;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int n, m;
long long mod;
char board[550][550];
long long dp[1201][1201];
int cnt_col[550][550];
long long memo(long long n2, long long n1) {
  if (n2 + n1 == 1) {
    return 0;
  }
  if (n2 + n1 == 0) {
    return 1;
  }
  if (dp[n2][n1] >= 0) {
    return dp[n2][n1];
  }
  long long res = 0;
  if (n2 >= 2) {
    res += memo(n2 - 2, n1 + 2) % mod * n2 * (n2 - 1) / 2 % mod;
  }
  if (n1 >= 2) {
    res += memo(n2, n1 - 2) % mod * n1 * (n1 - 1) / 2 % mod;
  }
  if (n1 >= 1 and n2 >= 1) {
    res += memo(n2 - 1, n1) % mod * n1 * n2 % mod;
  }
  return dp[n2][n1] = res;
}
int main() {
  cin >> n >> m >> mod;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  memset(cnt_col, 0, sizeof(cnt_col));
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      if (i - 1 >= 0) {
        cnt_col[i][j] += cnt_col[i - 1][j];
      }
      if (board[i][j] == '1') {
        cnt_col[i][j]++;
      }
    }
  }
  int n2, n1;
  n2 = n1 = 0;
  for (int i = 0; i < n; i++) {
    if (cnt_col[m - 1][i] > 2) {
      cout << 0 << endl;
      return 0;
    }
    if (cnt_col[m - 1][i] == 0) {
      n2++;
    }
    if (cnt_col[m - 1][i] == 1) {
      n1++;
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << memo(n2, n1) % mod << endl;
  return 0;
}
