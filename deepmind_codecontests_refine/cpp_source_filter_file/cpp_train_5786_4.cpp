#include <bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 17;
char ch[N];
int n, r[N], b[N];
int sr, sb, red[1 << N], blue[1 << N], f[1 << N][123];
int main() {
  std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> ch[i] >> r[i] >> b[i];
    sr += r[i];
    sb += b[i];
  }
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i & (1 << (j - 1))) {
        if (ch[j] == 'R')
          ++red[i];
        else
          ++blue[i];
      }
    }
  }
  memset(f, -1, sizeof(f));
  f[0][0] = 0;
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j <= 17; ++j) {
      if (f[i][j] == -1) continue;
      for (int k = 1; k <= n; ++k) {
        if (i & (1 << (k - 1))) continue;
        int T = i | (1 << (k - 1));
        f[T][j + std::min(r[k], red[i])] =
            std::max(f[T][j + std::min(r[k], red[i])],
                     f[i][j] + std::min(b[k], blue[i]));
      }
    }
  }
  int res = 1e9;
  for (int i = 0; i <= 17; ++i) {
    if (f[(1 << n) - 1][i] == -1) continue;
    res = std::min(res, std::max(sr - i, sb - f[(1 << n) - 1][i]));
  }
  cout << res + n << '\n';
  return 0;
}
