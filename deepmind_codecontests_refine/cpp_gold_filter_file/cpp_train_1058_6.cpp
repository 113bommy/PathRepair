#include <bits/stdc++.h>
using namespace std;
const int N = 51;
int pref[N][N], dp[N][N][N][N];
int get(int x, int y, int xx, int yy) {
  return pref[xx][yy] - pref[x - 1][yy] - pref[xx][y - 1] + pref[x - 1][y - 1];
}
int calc(int x, int y, int xx, int yy) {
  if (x > xx || y > yy || get(x, y, xx, yy) == 0) {
    return dp[x][y][xx][yy] = 0;
  }
  if (dp[x][y][xx][yy] != -1) {
    return dp[x][y][xx][yy];
  }
  int &res = dp[x][y][xx][yy];
  res = max(xx - x + 1, yy - y + 1);
  for (int i = x; i < xx; i++) {
    res = min(res, calc(x, y, i, yy) + calc(i + 1, y, xx, yy));
  }
  for (int i = y; i < yy; i++) {
    res = min(res, calc(x, y, xx, i) + calc(x, i + 1, xx, yy));
  }
  return res;
}
int main() {
  memset(dp, -1, sizeof dp);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      pref[i][j] = pref[i][j - 1] + (c == '#');
    }
    for (int j = 1; j <= n; j++) {
      pref[i][j] += pref[i - 1][j];
    }
  }
  cout << calc(1, 1, n, n) << endl;
}
