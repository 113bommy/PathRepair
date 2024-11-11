#include <bits/stdc++.h>
using namespace std;
const int LEN = 550;
string ar[LEN];
int n, k, use[LEN][LEN], dp[LEN * LEN], cnt, res, sum, use1[LEN * LEN];
void dfs(int x, int y, int cnt) {
  use[x][y] = cnt;
  dp[cnt]++;
  x--;
  if (x >= 0 && x < n && y >= 0 && y < n && !use[x][y] && ar[x][y] == '.')
    dfs(x, y, cnt);
  x++;
  x++;
  if (x >= 0 && x < n && y >= 0 && y < n && !use[x][y] && ar[x][y] == '.')
    dfs(x, y, cnt);
  x--;
  y--;
  if (x >= 0 && x < n && y >= 0 && y < n && !use[x][y] && ar[x][y] == '.')
    dfs(x, y, cnt);
  y++;
  y++;
  if (x >= 0 && x < n && y >= 0 && y < n && !use[x][y] && ar[x][y] == '.')
    dfs(x, y, cnt);
  y--;
}
int get(int x, int y) {
  int res = k * k;
  for (int j = y; j < y + k; j++) {
    if (x - 1 >= 0 && use[x - 1][j] > 0 && !use1[use[x - 1][j]])
      res += dp[use[x - 1][j]], use1[use[x - 1][j]] = 1;
    if (x + k < n && use[x + k][j] > 0 && !use1[use[x + k][j]])
      res += dp[use[x + k][j]], use1[use[x + k][j]] = 1;
  }
  for (int i = x; i < x + k; i++) {
    if (y - 1 >= 0 && use[i][y - 1] > 0 && !use1[use[i][y - 1]])
      res += dp[use[i][y - 1]], use1[use[i][y - 1]] = 1;
    if (y + k < n && use[i][y + k] > 0 && !use1[use[i][y + k]])
      res += dp[use[i][y + k]], use1[use[i][y + k]] = 1;
  }
  for (int j = y; j < y + k; j++) {
    if (x - 1 >= 0) use1[use[x - 1][j]] = 0;
    if (x + k < n) use1[use[x + k][j]] = 0;
  }
  for (int i = x; i < x + k; i++) {
    if (y - 1 >= 0) use1[use[i][y - 1]] = 0;
    if (y + k < n) use1[use[i][y + k]] = 0;
  }
  return res;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> ar[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!use[i][j] && ar[i][j] == '.') {
        cnt++;
        dfs(i, j, cnt);
      }
  cnt++;
  for (int i = 1; i < cnt; i++) res = max(res, dp[i]);
  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++) dp[use[i][j]]--;
  for (int i = 0; i + k - 1 < n; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j + k - 1 < n; j++) {
        res = max(res, get(i, j));
        if (j + k < n)
          for (int z = i; z < i + k; z++) {
            dp[use[z][j]]++;
            dp[use[z][j + k]]--;
          }
      }
    } else {
      for (int j = n - 1; j - k + 1 >= 0; j--) {
        res = max(res, get(i, j - k + 1));
        if (j - k >= 0)
          for (int z = i; z < i + k; z++) {
            dp[use[z][j]]++;
            dp[use[z][j - k]]--;
          }
      }
    }
    if (i + k < n) {
      if (i % 2 == 0) {
        for (int j = n - 1; j >= n - k; j--) {
          dp[use[i][j]]++;
          dp[use[i + k][j]]--;
        }
      } else {
        for (int j = 0; j < k; j++) {
          dp[use[i][j]]++;
          dp[use[i + k][j]]--;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
