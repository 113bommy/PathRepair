#include <bits/stdc++.h>
using namespace std;
const int MAX = 51;
int main() {
  int N, M;
  cin >> N >> M;
  int z[MAX][MAX] = {0};
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) {
      cin >> z[i][j];
    }
  int k = min(M, N);
  int ans = -1000000000;
  int p[MAX][MAX][2] = {0};
  int gor[MAX][MAX] = {0};
  int ver[MAX][MAX] = {0};
  for (int j = 0; j < M; ++j) {
    ver[0][j] = z[0][j];
    if (j == 0)
      gor[0][j] = z[0][j];
    else
      gor[0][j] = gor[0][j - 1] + z[0][j];
  }
  for (int i = 1; i < N; ++i) {
    gor[i][0] = z[i][0];
    ver[i][0] = ver[i - 1][0] + z[i][0];
    for (int j = 1; j < M; ++j) {
      ver[i][j] = ver[i - 1][j] + z[i][j];
      gor[i][j] = gor[i][j - 1] + z[i][j];
    }
  }
  for (int i = 0; i <= N - 3; ++i) {
    for (int j = 0; j <= M - 3; ++j) {
      p[i][j][1] = z[i][j] + z[i][j + 1] + z[i][j + 2] + z[i + 1][j + 2] +
                   z[i + 2][j + 2] + z[i + 2][j + 1] + z[i + 2][j];
      if (ans < p[i][j][1]) ans = p[i][j][1];
    }
  }
  for (int i = 0; i <= N - 5; ++i) {
    for (int j = 0; j <= M - 5; ++j) {
      p[i][j][0] = gor[i][j + 4] - gor[i][j] + z[i][j] + ver[i + 4][j + 4] -
                   ver[i][j + 4] + gor[i + 4][j + 3] - gor[i + 4][j] +
                   ver[i + 4][j] - ver[i + 1][j] + z[i + 2][j + 1] +
                   z[i + 2][j + 2];
      if (ans < p[i][j][0]) ans = p[i][j][0];
    }
  }
  for (int r = 7; r < k; r += 2) {
    for (int i = 0; i <= N - r; ++i)
      for (int j = 0; j <= M - r; ++j) {
        int l = ((r - 1) / 2) % 2;
        p[i][j][l] = p[i + 2][j + 2][l] + gor[i][j + r - 1] - gor[i][j] +
                     z[i][j] + ver[i + r - 1][j + r - 1] - ver[i][j + r - 1] +
                     gor[i + r - 1][j + r - 2] - gor[i + r - 1][j] +
                     ver[i + r - 1][j] - ver[i + 1][j] + z[i + 2][j + 1];
        if (ans < p[i][j][l]) ans = p[i][j][l];
      }
  }
  cout << ans << endl;
  return 0;
}
