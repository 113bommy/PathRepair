#include <bits/stdc++.h>
using namespace std;
int n, m, mmp[110][110], ans = 100000, now = 0, sum[110][110];
int dfs(int x, int y, int k) {
  if (x + k - 1 > n || y + k - 1 > n) return 1000000;
  int cnt = 0, cur = sum[x + k - 1][y + k - 1] - sum[x - 1][y + k - 1] -
                     sum[x + k - 1][y - 1] + sum[x - 1][y - 1];
  if (cur == now) {
    return k * k - now;
  }
  return 1000000;
}
int main() {
  cin >> n >> m;
  char str[1000];
  for (int i = 1; i <= n; i++) {
    cin >> str;
    for (int j = 0; j < m; j++) {
      if (str[j] == 'B')
        mmp[i][j + 1] = 1, now++;
      else
        mmp[i][j + 1] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + mmp[i][j] - sum[i - 1][j - 1];
    }
  }
  for (int k = 1; k <= min(n, m); k++)
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int nn = dfs(i, j, k);
        if (nn != 1000000) {
          cout << nn;
          return 0;
        }
      }
    }
  cout << -1;
  return 0;
}
