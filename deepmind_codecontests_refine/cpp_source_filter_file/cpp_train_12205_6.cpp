#include <bits/stdc++.h>
using namespace std;
string s;
int dp[110][55][210][2][2];
int dx[] = {1, -1};
int r(int p, int n, int x, int to, int cur) {
  if (p == s.size()) {
    if (n != 0) return -2000000;
    if (x >= 100)
      return x - 100;
    else
      return 100 - x;
  }
  if (dp[p][n][x][to][cur] != -1) return dp[p][n][x][to][cur];
  int nn = n;
  int res = -2000000;
  if (nn > 0) {
    int v = cur ^ 1;
    int res1 = r(p, n - 1, x, to, v);
    res = ((res < res1) ? (res1) : (res));
  }
  if (cur == 0) {
    int ncur = 0;
    if ((p + 1 < s.size()) && (s[p + 1] == 'T')) ncur = 1;
    int res1 = r(p + 1, n, x + dx[to], to, ncur);
    res = ((res < res1) ? (res1) : (res));
  } else {
    int ncur = 0;
    if ((p + 1 < s.size()) && (s[p + 1] == 'F')) ncur = 1;
    int res1 = r(p + 1, n, x, to ^ 1, ncur);
    res = ((res < res1) ? (res1) : (res));
  }
  return dp[p][n][x][to][cur] = res;
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n;
  cin >> s >> n;
  int cur = 0;
  if (s[0] == 'T') cur = 1;
  int res = r(0, n, 100, 0, cur);
  cout << res << endl;
  return 0;
}
