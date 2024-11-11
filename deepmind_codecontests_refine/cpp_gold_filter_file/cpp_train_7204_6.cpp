#include <bits/stdc++.h>
long long A[10][512][512];
int k, t, ans, B[10][512][512];
int main() {
  scanf("%d", &k);
  int n = 1 << k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) scanf("%lld", &A[0][i][j]);
  scanf("%d", &t);
  for (int i = 0, x, y; i < t; ++i) scanf("%d%d", &x, &y), B[0][x - 1][y - 1]++;
  const int R = n - 1;
  for (int f = 0; f < k; ++f)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (B[f][i][j])
          for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
              A[f + 1][i + x & R][j + y & R] ^= A[f][x][y],
                  B[f + 1][i + x & R][j + y & R] ^= B[f][x][y];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) ans += A[k][i][j] ? 1 : 0;
  printf("%d", ans);
}
