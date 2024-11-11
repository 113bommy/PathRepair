#include <bits/stdc++.h>
using std::max;
using std::min;
int n, s[77], f[77][77][77][3], idx[3][77], cnt[3], ccnt[3][77],
    ans = 0x3f3f3f3f;
char tmp[77];
int main() {
  scanf("%d", &n);
  scanf("%s", tmp);
  for (int i = 1; i <= n; ++i) {
    s[i] = tmp[i - 1] == 'Y' ? 2 : (tmp[i - 1] == 'K' ? 1 : 0);
    ++cnt[s[i]], idx[s[i]][cnt[s[i]]] = i;
    ccnt[0][i] = cnt[0];
    ccnt[1][i] = cnt[1];
    ccnt[2][i] = cnt[2];
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      for (int k = 0; k <= n; ++k)
        for (int t = 0; t < 3; ++t) f[i][j][k][t] = 0x3f3f3f3f;
  f[0][0][0][0] = f[0][0][0][1] = f[0][0][0][2] = 0;
  for (int i = 0; i <= n; ++i)
    for (int j = std::max(0, i - cnt[0] - cnt[1]); j <= min(i, cnt[2]); ++j)
      for (int k = std::max(0, i - cnt[2] - cnt[1]); k <= min(i - j, cnt[0]);
           ++k) {
        f[i + 1][j][k][1] = min(f[i + 1][j][k][1],
                                f[i][j][k][0] + idx[1][i + 1 - j - k] - i - 1 +
                                    max(0, j - ccnt[2][idx[1][i + 1 - j - k]]) +
                                    max(0, k - ccnt[0][idx[1][i + 1 - j - k]]));
        f[i + 1][j][k][1] = min(f[i + 1][j][k][1],
                                f[i][j][k][1] + idx[1][i + 1 - j - k] - i - 1 +
                                    max(0, j - ccnt[2][idx[1][i + 1 - j - k]]) +
                                    max(0, k - ccnt[0][idx[1][i + 1 - j - k]]));
        f[i + 1][j][k + 1][0] =
            min(f[i + 1][j][k + 1][0],
                f[i][j][k][0] + idx[0][k + 1] - i - 1 +
                    max(0, j - ccnt[2][idx[0][k + 1]]) +
                    max(0, i - j - k - ccnt[1][idx[0][k + 1]]));
        f[i + 1][j][k + 1][0] =
            min(f[i + 1][j][k + 1][0],
                f[i][j][k][1] + idx[0][k + 1] - i - 1 +
                    max(0, j - ccnt[2][idx[0][k + 1]]) +
                    max(0, i - j - k - ccnt[1][idx[0][k + 1]]));
        f[i + 1][j][k + 1][0] =
            min(f[i + 1][j][k + 1][0],
                f[i][j][k][2] + idx[0][k + 1] - i - 1 +
                    max(0, j - ccnt[2][idx[0][k + 1]]) +
                    max(0, i - j - k - ccnt[1][idx[0][k + 1]]));
        f[i + 1][j + 1][k][2] =
            min(f[i + 1][j + 1][k][2],
                f[i][j][k][2] + idx[2][j + 1] - i - 1 +
                    max(0, k - ccnt[0][idx[2][j + 1]]) +
                    max(0, i - j - k - ccnt[1][idx[2][j + 1]]));
        f[i + 1][j + 1][k][2] =
            min(f[i + 1][j + 1][k][2],
                f[i][j][k][0] + idx[2][j + 1] - i - 1 +
                    max(0, k - ccnt[0][idx[2][j + 1]]) +
                    max(0, i - j - k - ccnt[1][idx[2][j + 1]]));
        f[i + 1][j + 1][k][2] =
            min(f[i + 1][j + 1][k][2],
                f[i][j][k][1] + idx[2][j + 1] - i - 1 +
                    max(0, k - ccnt[0][idx[2][j + 1]]) +
                    max(0, i - j - k - ccnt[1][idx[2][j + 1]]));
      }
  for (int j = std::max(0, n - cnt[0] - cnt[1]); j <= min(n, cnt[2]); ++j) {
    for (int k = std::max(0, n - cnt[2] - cnt[1]); k <= min(n - j, cnt[0]); ++k)
      for (int t = 0; t < 3; ++t) ans = min(ans, f[n][j][k][t]);
  }
  printf("%d", ans);
  return 0;
}
