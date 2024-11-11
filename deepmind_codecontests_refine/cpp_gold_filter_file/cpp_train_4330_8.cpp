#include <bits/stdc++.h>
int n, m;
int len[(1010)], val[(1010)], mxl[(1010)], cost[(1010)], dp[(1010)][(1010)];
char a[(1010)], b[(1010)][(1010)];
std::pair<int, int> lab[(1010)];
int main() {
  scanf("%s", a);
  m = strlen(a);
  std::reverse(a, m + a);
  for (int i = m; i < (1002) + 1; ++i) {
    a[i] = '0';
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", b[i]);
    len[i] = strlen(b[i]);
    std::reverse(b[i], len[i] + b[i]);
    for (int j = len[i]; j < (1002) + 1; ++j) {
      b[i][j] = '0';
    }
  }
  for (int i = 0; i < 10; ++i) {
    scanf("%d", cost + i);
  }
  memset(dp, 0xee, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    lab[i] = {0, i};
  }
  for (int i = 0; i < (1002) + 1; ++i) {
    int l = 0, r = 9;
    if (i == m - 1) {
      l = 1;
    }
    if (isdigit(a[i])) {
      l = r = a[i] - '0';
    }
    for (int j = 0; j < n; ++j) {
      val[j] = b[lab[j].second][i] - '0';
      mxl[j] = std::max(m, len[lab[j].second]);
    }
    for (int k = l; k < r + 1; ++k) {
      int c2 = 0, d2 = 0;
      for (int j = 0; j < n; ++j) {
        c2 += (val[j] + k >= 10);
        d2 += (i >= mxl[j]) ? 0 : cost[(val[j] + k) % 10];
      }
      for (int j = 0; j < n + 1; ++j) {
        dp[i + 1][c2] = std::max(dp[i + 1][c2], dp[i][j] + d2);
        if (j < n) {
          c2 -= (val[j] + k >= 10),
              d2 -= (i >= mxl[j]) ? 0 : cost[(val[j] + k) % 10];
          c2 += (val[j] + k + 1 >= 10), d2 += cost[(val[j] + k + 1) % 10];
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      lab[j] = {val[j] * (n + 1) + n - j, lab[j].second};
    }
    std::sort(lab, n + lab, std::greater<std::pair<int, int> >());
  }
  printf("%d\n", dp[(1002) + 1][0]);
  return 0;
}
