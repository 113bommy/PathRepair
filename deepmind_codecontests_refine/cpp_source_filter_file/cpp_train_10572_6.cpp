#include <bits/stdc++.h>
using namespace std;
const int N = 1002, B = 10;
short f[N][N][B][B], P[N];
int sum[N][N];
bool a[N][N];
short query(int x1, int y1, int x2, int y2) {
  short dx = P[x2 - x1 + 1], dy = P[y2 - y1 + 1];
  short ans = f[x1][y1][dx][dy];
  ans = max(ans, f[x1][y2 - (1 << dy) + 1][dx][dy]);
  ans = max(ans, f[x2 - (1 << dx) + 1][y2 - (1 << dy) + 1][dx][dy]);
  ans = max(ans, f[x2 - (1 << dx) + 1][y1][dx][dy]);
  return ans;
}
int main() {
  P[1] = 0;
  for (int i = 2; i < N; ++i) {
    P[i] = P[i - 1];
    if ((1 << P[i]) * 2 < i) P[i]++;
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x;
      scanf("%d", &x);
      a[i][j] = x == 1;
      sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = m; j >= 1; --j) {
      if (a[i][j] == 1) {
        f[i][j][0][0] = min(min(f[i + 1][j][0][0], f[i][j + 1][0][0]),
                            f[i + 1][j + 1][0][0]) +
                        1;
      }
    }
  }
  for (int i = 1; (1 << i) <= n; ++i) {
    for (int x = 1; x + (1 << i) - 1 <= n; ++x) {
      for (int y = 1; y <= m; ++y) {
        f[x][y][i][0] =
            max(f[x][y][i - 1][0], f[x + (1 << i - 1)][y][i - 1][0]);
      }
    }
  }
  for (int i = 1; (1 << i) <= m; ++i) {
    for (int y = 1; y + (1 << i) - 1 <= m; ++y) {
      for (int x = 1; x <= n; ++x) {
        f[x][y][0][i] =
            max(f[x][y][0][i - 1], f[x][y + (1 << i - 1)][0][i - 1]);
      }
    }
  }
  for (int i = 1; (1 << i) <= n; ++i) {
    for (int j = 1; (1 << j) <= n; ++j) {
      for (int x = 1; x + (1 << i) - 1 <= n; ++x) {
        for (int y = 1; y + (1 << j) - 1 <= m; ++y) {
          f[x][y][i][j] =
              max(f[x][y][i - 1][j], f[x + (1 << i - 1)][y][i - 1][j]);
        }
      }
    }
  }
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int ans = 0, d = min(x2 - x1 + 1, y2 - y1 + 1);
    int l = 1, r = d;
    while (l <= r) {
      int m = (l + r) / 2;
      int A = query(x1, y1, x2 - m + 1, y2 - m + 1);
      if (A >= m) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    printf("%d\n", ans);
  }
}
