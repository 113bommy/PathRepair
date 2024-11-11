#include <bits/stdc++.h>
using namespace std;
int cntl[1005][1005], cntd[1005][1005], n, m;
int down, up, lft, rght;
char ch[1005][1005];
int ans;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> ch[i][j];
      if (ch[i][j] == '*')
        cntl[i][j] = cntl[i][j - 1] + 1, cntd[i][j] = cntd[i - 1][j] + 1;
      else
        cntl[i][j] = cntl[i][j - 1], cntd[i][j] = cntd[i - 1][j];
    }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (ch[i][j] == '.') continue;
      down = cntd[n][j] - cntd[i][j];
      up = cntd[i - 1][j];
      lft = cntl[i][j - 1];
      rght = cntl[i][m] - cntl[i][j];
      ans = ans + down * lft + down * rght + up * lft + up * rght;
    }
  }
  cout << ans << '\n';
  return 0;
}
