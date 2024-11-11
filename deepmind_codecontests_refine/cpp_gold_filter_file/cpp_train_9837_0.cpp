#include <bits/stdc++.h>
using namespace std;
char a[1001][1001];
int d[1001][1001];
int n, m, ans;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = n; i > 0; i--)
    for (int j = m; j > 0; j--) {
      int cur;
      d[i][j] = d[i + 1][j] + d[i][j + 1] - d[i + 1][j + 1];
      if (a[i][j] == 'W')
        cur = 1;
      else
        cur = -1;
      if (cur != d[i][j]) ans++;
      d[i][j] = cur;
    }
  cout << ans;
}
