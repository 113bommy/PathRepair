#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int N = 25;
int matSize;
int n, m, q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cat[N][N];
bool legal(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
int trans(int x, int y) { return x * m + y; }
struct matrix {
  int d[N][N];
  matrix(bool flag = 0) {
    memset(d, 0, sizeof(d));
    if (flag)
      for (int i = 0; i < matSize; i++) d[i][i] = 1;
  }
  matrix operator*(const matrix &I) const {
    matrix ans;
    for (int i = 0; i < matSize; i++) {
      for (int j = 0; j < matSize; j++) {
        for (int k = 0; k < matSize; k++) {
          ans.d[i][j] += (long long)d[i][k] * I.d[k][j];
          ans.d[i][j] %= MOD;
        }
      }
    }
    return ans;
  }
};
matrix modExp(matrix a, int b) {
  matrix t = matrix(1);
  while (b) {
    if (b & 1) t = t * a;
    a = a * a;
    b >>= 1;
  }
  return t;
}
matrix rebuild() {
  matrix ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (cat[i][j]) continue;
      int u = trans(i, j);
      ans.d[u][u] = 1;
      for (int k = 0; k < 4; k++) {
        int p = i + dx[k];
        int q = j + dy[k];
        if (legal(p, q) && !cat[p][q]) ans.d[u][trans(p, q)] = 1;
      }
    }
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  matSize = n * m;
  int t, p, x, y, pre = 1;
  matrix now, go = rebuild();
  now.d[0][0] = 1;
  while (q--) {
    scanf("%d%d%d%d", &p, &x, &y, &t);
    x--;
    y--;
    now = now * modExp(go, t - pre);
    if (p > 1) {
      cat[x][y] ^= 1;
    }
    if (p == 1) {
      int ret = 0;
      for (int i = 0; i < matSize; i++) {
        ret += now.d[i][trans(x, y)];
        ret %= MOD;
      }
      printf("%d\n", ret);
    }
    pre = t;
    go = rebuild();
  }
  return 0;
}
