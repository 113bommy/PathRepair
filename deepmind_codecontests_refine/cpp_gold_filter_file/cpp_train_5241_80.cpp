#include <bits/stdc++.h>
using namespace std;
const int _x[4] = {1, 0, -1, 0};
const int _y[4] = {0, 1, 0, -1};
const int maxn = 2000 + 5;
int A[maxn][maxn];
int Left[maxn][maxn], Right[maxn][maxn], Bottom[maxn][maxn], Top[maxn][maxn];
bool used[maxn][maxn];
int n;
void dfs(int x, int y) {
  used[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int sx = x + _x[i], sy = y + _y[i];
    if (sx < 0 || sx >= n || sy < 0 || sy >= n || used[sx][sy] || !A[sx][sy]) {
      continue;
    }
    dfs(sx, sy);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &A[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    int l = 0;
    for (int j = 0; j < n; ++j) {
      if (A[i][j] == 0) {
        l = j + 1;
      }
      Left[i][j] = l;
    }
    int r = n - 1;
    for (int j = n - 1; j >= 0; --j) {
      if (A[i][j] == 0) {
        r = j - 1;
      }
      Right[i][j] = r;
    }
    int t = 0;
    for (int j = 0; j < n; ++j) {
      if (A[j][i] == 0) {
        t = j + 1;
      }
      Top[j][i] = t;
    }
    int b = n - 1;
    for (int j = n - 1; j >= 0; --j) {
      if (A[j][i] == 0) {
        b = j - 1;
      }
      Bottom[j][i] = b;
    }
  }
  int q = 0, cir = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!used[i][j] && A[i][j]) {
        ++q;
        dfs(i, j);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (A[i][j] && Right[i][j] - j == j - Left[i][j] &&
          j - Left[i][j] == Bottom[i][j] - i &&
          Bottom[i][j] - i == i - Top[i][j]) {
        int r = Right[i][j] - j;
        if (A[i + r][j + 3] == 0) {
          ++cir;
        }
      }
    }
  }
  q -= cir;
  cout << cir << " " << q << '\n';
  return 0;
}
