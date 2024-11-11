#include <bits/stdc++.h>
using namespace std;
bool flag[11][11];
int main() {
  int r, c, n, k, ans = 0;
  memset(flag, 0, sizeof flag);
  cin >> r >> c >> n >> k;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    flag[x][y] = 1;
  }
  for (int x1 = 1; x1 <= r; ++x1)
    for (int x2 = x1; x2 <= r; ++x2)
      for (int y1 = 1; y1 <= c; ++y1)
        for (int y2 = y1; y2 <= c; ++y2) {
          int tot = 0;
          for (int i = x1; i <= x2; ++i)
            for (int j = y1; j <= y2; ++j)
              if (flag[i][j]) tot++;
          if (tot >= k) ans++;
        }
  cout << ans << endl;
  return 0;
}
