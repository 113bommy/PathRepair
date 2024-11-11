#include <bits/stdc++.h>
using namespace std;
const int MAX = 40 + 5;
int sum[MAX][MAX];
int ans[MAX][MAX][MAX][MAX];
int main() {
  int n, m, q, val;
  string s;
  cin >> n >> m >> q;
  memset(sum, 0, sizeof(sum));
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '0')
        val = 0;
      else
        val = 1;
      sum[i][j + 1] = sum[i - 1][j + 1] + sum[i][j] - sum[i - 1][j] + val;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      for (int x = i; x <= n; x++)
        for (int y = j; y <= m; y++) {
          if (x > i) ans[i][j][x][y] += ans[i][j][x - 1][y];
          if (y > j) ans[i][j][x][y] += ans[i][j][x][y - 1];
          if (x > i && y > j) ans[i][j][x][y] -= ans[i][j][x - 1][y - 1];
          if (sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1] ==
              0)
            ans[i][j][x][y]++;
        }
    }
  while (q--) {
    int a, b, c, d, ret = 0;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for (int i = a; i <= c; i++)
      for (int j = b; j <= d; j++) ret += ans[i][j][c][d];
    printf("%d\n", ret);
  }
  return 0;
}
