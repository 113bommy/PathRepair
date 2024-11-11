#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
int C[105][105], f[2][55][105][105];
inline void U(int &x) {
  if (x >= mo) {
    x -= mo;
  }
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = min(200, C[i - 1][j] + C[i - 1][j - 1]);
    }
  }
  int now = 0, last = 1, ans = 0;
  for (int i = 1; i * 2 <= n; ++i) {
    f[now][i][i * 2][1] = 1;
  }
  for (int a = 1; a < m && (a << 1) <= n; ++a) {
    swap(now, last);
    for (int b = 1; (b << 1) <= n; ++b) {
      for (int c = b << 1; c <= n; ++c) {
        for (int d = 1; d <= k; ++d) {
          if (f[last][b][c][d]) {
            for (int h = 1, t, g; (g = c + (h << 1)) <= n; ++h) {
              if ((t = d * C[b + h - 1][h]) <= k) {
                U(f[now][h][g][t] += f[last][b][c][d]);
              }
            }
            U(ans += (long long)f[last][b][c][d] * (m - a) % mo);
            f[last][b][c][d] = 0;
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
