#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10 + 10;
int r, c, n, k;
int a[MAXN][MAXN], s[MAXN][MAXN];
int ans;
int main() {
  cin >> r >> c >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    a[x][y] = 1;
  }
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++)
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
  for (int i1 = 1; i1 <= r; i1++)
    for (int j1 = 1; j1 <= c; j1++)
      for (int i2 = i1; i2 <= r; i2++)
        for (int j2 = j1; j2 <= c; j2++) {
          if (s[i2][j2] - s[i1 - 1][j2] - s[i2][j1 - 1] + s[i1 - 1][j1 - 1] >=
              k)
            ans++;
        }
  cout << ans << endl;
  return 0;
}
