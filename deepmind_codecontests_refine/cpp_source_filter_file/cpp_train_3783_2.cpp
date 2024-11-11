#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 500;
int n, m;
int rs[maxn + 4][maxn + 4], cs[maxn + 4][maxn + 4], a[maxn + 4][maxn + 4];
int main() {
  std::ios::sync_with_stdio(false);
  while (cin >> n >> m) {
    for (int(i) = 1; (i) <= (n); (i)++)
      for (int(j) = 1; (j) <= (m); (j)++) cin >> a[i][j];
    for (int(i) = 1; (i) <= (n); (i)++) {
      rs[i][0] = 0;
      for (int(j) = 1; (j) <= (m); (j)++) {
        rs[i][j] = rs[i][j - 1] + a[i][j];
      }
    }
    for (int(j) = 1; (j) <= (m); (j)++) {
      cs[j][0] = 0;
      for (int(i) = 1; (i) <= (n); (i)++) {
        cs[j][i] = cs[j][i - 1] + a[i][j];
      }
    }
    int ans = -INF;
    for (int(i) = 1; (i) <= (n); (i)++)
      for (int(j) = 1; (j) <= (m); (j)++) {
        int x1 = i, y1 = j;
        int x2 = x1 + 2, y2 = y1 + 2;
        if (x2 <= n && y2 <= m) {
          int ret = rs[x1][y2] - rs[x1][y1 - 1] + cs[y2][x2] - cs[y2][x1] +
                    rs[x2][y2 - 1] - rs[x2][y1 - 1];
          ans = max(ret, ans);
          while (x1 - 2 >= 1 && y1 - 2 >= 1 && x2 + 2 <= n && y2 + 2 <= m) {
            x1 -= 2, y1 -= 2, x2 += 2, y2 += 2;
            ret += rs[x1][y2] - rs[x1][y1 - 1] + cs[y2][x2] - cs[y2][x1] -
                   rs[x2][y2 - 1] - rs[x2][y1 - 1];
            ret += cs[y1][x2 - 1] - cs[y1][x1 + 1] + a[x1 + 2][y1 + 1];
            ans = max(ans, ret);
          }
        }
        x1 = i, y1 = j;
        x2 = x1 + 4, y2 = y1 + 4;
        if (x2 <= n && y2 <= m) {
          int ret = rs[x1][y2] - rs[x1][y1 - 1] + cs[y2][x2] - cs[y2][x1] +
                    rs[x2][y2 - 1] - rs[x2][y1 - 1];
          ret += cs[y1][x2 - 1] - cs[y1][x1 + 1] + a[x1 + 2][y1 + 1] +
                 a[x1 + 2][y1 + 2];
          ans = max(ret, ans);
          while (x1 - 2 >= 1 && y1 - 2 >= 1 && x2 + 2 <= n && y2 + 2 <= m) {
            x1 -= 2, y1 -= 2, x2 += 2, y2 += 2;
            ret += rs[x1][y2] - rs[x1][y1 - 1] + cs[y2][x2] - cs[y2][x1] -
                   rs[x2][y2 - 1] - rs[x2][y1 - 1];
            ret += cs[y1][x2 - 1] - cs[y1][x1 + 1] + a[x1 + 2][y1 + 1];
            ans = max(ans, ret);
          }
        }
      }
    cout << ans << endl;
  }
  return 0;
}
