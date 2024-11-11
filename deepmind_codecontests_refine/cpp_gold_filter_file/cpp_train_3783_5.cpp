#include <bits/stdc++.h>
using namespace std;
int X[500][500];
int S[501][501];
int D[250][500][500];
int main(void) {
  int n, m, i, j, k, r;
  int best = -1000000000;
  cin >> n >> m;
  r = min(n, m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) cin >> X[i][j];
  for (i = 0; i <= 500; i++) S[0][i] = S[i][0] = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      S[i + 1][j + 1] = S[i][j + 1] + S[i + 1][j] - S[i][j] + X[i][j];
  for (i = 0; i <= n - 3; i++)
    for (j = 0; j <= m - 3; j++) {
      D[0][i][j] = S[i + 3][j + 3] - S[i + 3][j] - S[i][j + 3] + S[i][j] -
                   X[i + 1][j] - X[i + 1][j + 1];
      if (D[0][i][j] > best) best = D[0][i][j];
    }
  for (i = 0; i <= n - 5; i++)
    for (j = 0; j <= m - 5; j++) {
      D[1][i][j] = S[i + 5][j + 5] - S[i + 5][j] - S[i][j + 5] + S[i][j] -
                   (S[i + 4][j + 4] - S[i + 4][j + 1] - S[i + 1][j + 4] +
                    S[i + 1][j + 1]) -
                   X[i + 1][j] + X[i + 2][j + 1] + X[i + 2][j + 2];
      if (D[1][i][j] > best) best = D[1][i][j];
    }
  for (k = 7; k <= r; k += 2) {
    for (i = 0; i <= n - k; i++) {
      for (j = 0; j <= m - k; j++) {
        D[(k - 3) / 2][i][j] =
            D[(k - 7) / 2][i + 2][j + 2] +
            (S[i + k][j + k] - S[i + k][j] - S[i][j + k] + S[i][j]) -
            (S[i + k - 1][j + k - 1] - S[i + k - 1][j + 1] -
             S[i + 1][j + k - 1] + S[i + 1][j + 1]) -
            X[i + 1][j] + X[i + 2][j + 1];
        if (D[(k - 3) / 2][i][j] > best) best = D[(k - 3) / 2][i][j];
      }
    }
  }
  cout << best;
  return 0;
}
