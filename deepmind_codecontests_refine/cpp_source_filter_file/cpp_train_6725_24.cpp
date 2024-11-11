#include <bits/stdc++.h>
using namespace std;
int md = 1e9 + 7, dp[2][51][51][51][51], x[50];
inline void ad(int &x, int y) {
  if ((x += y) >= md) x -= md;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", x + i);
  if (x[0] == 2) {
    if (x[1] == 2)
      dp[1][1][1][0][0] = 1;
    else
      dp[1][1][0][0][1] = 1;
  } else if (x[1] == 2)
    dp[1][0][1][1][0] = 1;
  else
    dp[1][0][0][1][1] = 1;
  for (int v = 1; v < (int)(n - 1); ++v) {
    int o = v & 1 ^ 1;
    for (int i = 0; i < (int)(n); ++i)
      for (int j = 0; j < (int)(n); ++j)
        for (int k = 0; k < (int)(n); ++k)
          for (int w = 0; w < (int)(n); ++w) dp[o][i][j][k][w] = 0;
    for (int i = 0; i < (int)(n); ++i)
      for (int j = 0; j < (int)(n); ++j)
        for (int k = 0; k < (int)(n); ++k)
          for (int w = 0; w < (int)(n); ++w) {
            int &r = dp[v & 1][i][j][k][w];
            if (!r) continue;
            if (x[v + 1] == 2) {
              if (i) ad(dp[o][i - 1][j + 1][k][w], (long long)i * r % md);
              if (j && i == 0 && k == 0)
                ad(dp[o][j - 1][1][w][0], (long long)j * r % md);
              if (k) ad(dp[o][i + 1][j + 1][k - 1][w], (long long)k * r % md);
              if (w && i == 0 && k == 0)
                ad(dp[o][j + 1][1][w - 1][0], (long long)w * r % md);
              if (i && j)
                ad(dp[o][i - 1][j - 1][k][w], (long long)j * i * r % md);
              if (i && w)
                ad(dp[o][i - 1][j + 1][k][w - 1], (long long)w * i * r % md);
              if (k && j)
                ad(dp[o][i + 1][j - 1][k - 1][w], (long long)k * j * r % md);
              if (k && w)
                ad(dp[o][i + 1][j + 1][k - 1][w - 1],
                   (long long)k * w * r % md);
            } else {
              if (i) ad(dp[o][i - 1][j][k][w + 1], (long long)i * r % md);
              if (j && i == 0 && k == 0)
                ad(dp[o][j - 1][0][w][1], (long long)j * r % md);
              if (k) ad(dp[o][i + 1][j][k - 1][w + 1], (long long)k * r % md);
              if (w && i == 0 && k == 0)
                ad(dp[o][j + 1][0][w - 1][1], (long long)w * r % md);
              if (i && j) ad(dp[o][i - 1][j][k][w], (long long)j * i * r % md);
              if (i && j >= 2)
                ad(dp[o][i - 1][j - 2][k][w],
                   (long long)j * (j - 1) / 2 * i * r % md);
              if (i && w)
                ad(dp[o][i - 1][j + 2][k][w - 1], (long long)w * i * r % md);
              if (i && w >= 2)
                ad(dp[o][i - 1][j + 2][k][w - 2],
                   (long long)w * (w - 1) / 2 * i * r % md);
              if (i && j && w)
                ad(dp[o][i - 1][j][k][w - 1], (long long)i * j * w * r % md);
              if (k && j)
                ad(dp[o][i + 1][j][k - 1][w], (long long)k * j * r % md);
              if (k && j >= 2)
                ad(dp[o][i + 1][j - 2][k - 1][w],
                   (long long)k * j * (j - 1) / 2 * r % md);
              if (k && w)
                ad(dp[o][i + 1][j + 2][k - 1][w - 1],
                   (long long)k * w * r % md);
              if (k && w >= 2)
                ad(dp[o][i + 1][j + 2][k - 1][w - 2],
                   (long long)k * w * (w - 1) / 2 * r % md);
              if (k && j && w)
                ad(dp[o][i + 1][j][k - 1][w - 1],
                   (long long)i * j * w * r % md);
            }
          }
  }
  printf("%d\n", dp[n & 1 ^ 1][0][0][0][0]);
}
