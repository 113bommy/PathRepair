#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
const int N = 10 + 10;
ll res;
char a[9][N][N];
ll dp[10][10][10];
ll go(ll idx, ll x, ll y) {
  if (idx == 9) {
    return 1;
  }
  if (a[idx][x][y] == 'S') return 0;
  if (dp[idx][x][y] + 1) return dp[idx][x][y];
  ll xx = 0;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (x + i >= 0 && x + i < 8 && y + j >= 0 && y + j < 8 &&
          a[idx][x + i][y + j] != 'S') {
        xx = xx or go(idx + 1, x + i, y + j);
      }
    }
  }
  return dp[idx][x][y] = xx;
}
void solve() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cin >> a[0][i][j];
    }
  }
  for (int i = 1; i < 9; ++i) {
    for (int j = 1; j < 8; ++j) {
      for (int k = 0; k < 8; ++k) {
        a[i][j][k] = a[i - 1][j - 1][k];
      }
    }
    for (int j = 0; j < 8; ++j) {
      a[i][0][j] = '.';
    }
  }
  memset(dp, -1, sizeof dp);
  go(0, 7, 0) ? cout << "WIN\n" : cout << "LOSE\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  while (t--) {
    solve();
  }
}
