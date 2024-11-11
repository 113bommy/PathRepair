#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, m, k;
int f[2][1005][55][55];
int main() {
  ios_base::sync_with_stdio(0);
  while (scanf("%d%d%d", &n, &m, &k) == 3) {
    vector<int> q(n + 1, 1);
    vector<int> a(n + 1, 0), b(n + 1, 0);
    int aCnt;
    scanf("%d", &aCnt);
    while (aCnt--) {
      int x;
      scanf("%d", &x);
      a[x] = 1;
    }
    int bCnt;
    scanf("%d", &bCnt);
    while (bCnt--) {
      int x;
      scanf("%d", &x);
      b[x] = 1;
    }
    int p = 0;
    memset(f[p], 0xc0, sizeof f[p]);
    f[p][0][0][0] = 0;
    auto getMax = [](int& x, int y) {
      if (x < y) x = y;
    };
    m = min(m, 2 * (n + k - 1) / k);
    for (int i = 1; i <= n; ++i) {
      memset(f[!p], 0xc0, sizeof f[!p]);
      for (int j = 0; j <= m; ++j) {
        for (int x = 0; x <= k; ++x) {
          for (int y = 0; y <= k; ++y) {
            int nj, nx, ny, val;
            nj = j, nx = max(0, x - 1), ny = max(0, y - 1),
            val = (nx && a[i]) || (ny && b[i]);
            getMax(f[!p][nj][nx][ny], f[p][j][x][y] + val);
            nj = j + 1, nx = k, ny = (0, y - 1),
            val = (nx && a[i]) || (ny && b[i]);
            getMax(f[!p][nj][nx][ny], f[p][j][x][y] + val);
            nj = j + 1, nx = max(0, x - 1), ny = k,
            val = (nx && a[i]) || (ny && b[i]);
            getMax(f[!p][nj][nx][ny], f[p][j][x][y] + val);
            nj = j + 2, nx = k, ny = k, val = (nx && a[i]) || (ny && b[i]);
            getMax(f[!p][nj][nx][ny], f[p][j][x][y] + val);
          }
        }
      }
      p = !p;
    }
    int ans = 0;
    for (int j = 0; j <= m; ++j) {
      for (int x = 0; x <= k; ++x) {
        for (int y = 0; y <= k; ++y) {
          getMax(ans, f[p][j][x][y]);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
