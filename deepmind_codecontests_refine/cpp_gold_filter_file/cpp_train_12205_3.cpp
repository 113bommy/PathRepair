#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[1000];
int dp[2][101][101];
int rec(int dir, int num, int pos) {
  int res = -1000000000;
  if (pos == n) {
    if (num == 0) {
      return 0;
    } else {
      return -1000000000;
    }
  }
  if (dp[dir][num][pos] >= 0) return dp[dir][num][pos];
  if (s[pos] == 'F') {
    if (dir == 0) {
      for (int i = 0; i <= num; i += 2) {
        res = max(res, rec(0, num - i, pos + 1) + 1);
      }
      for (int i = 1; i <= num; i += 2) {
        res = max(res, rec(1, num - i, pos + 1));
      }
    } else {
      for (int i = 0; i <= num; i += 2) {
        res = max(res, rec(1, num - i, pos + 1) - 1);
      }
      for (int i = 1; i <= num; i += 2) {
        res = max(res, rec(0, num - i, pos + 1));
      }
    }
  } else {
    if (dir == 0) {
      for (int i = 0; i <= num; i += 2) {
        res = max(res, rec(1, num - i, pos + 1));
      }
      for (int i = 1; i <= num; i += 2) {
        res = max(res, rec(0, num - i, pos + 1) + 1);
      }
    } else {
      for (int i = 0; i <= num; i += 2) {
        res = max(res, rec(0, num - i, pos + 1));
      }
      for (int i = 1; i <= num; i += 2) {
        res = max(res, rec(1, num - i, pos + 1) - 1);
      }
    }
  }
  dp[dir][num][pos] = res;
  return dp[dir][num][pos];
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  scanf("%d", &m);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= n; k++) {
        dp[i][j][k] = -1000000000;
      }
    }
  }
  int ans = 0;
  ans = max(rec(0, m, 0), rec(1, m, 0));
  printf("%d\n", ans);
}
