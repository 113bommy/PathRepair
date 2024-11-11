#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct Matrix {
  int m[22][22];
  void standard(int n) {
    for (int i = 0; i < (int)n; i++)
      for (int j = 0; j < (int)n; j++) m[i][j] = (i == j);
  }
  void show(int n) {
    for (int i = 0; i < (int)n; i++) {
      for (int j = 0; j < (int)n; j++) cout << m[i][j] << " ";
      cout << endl;
    }
  }
};
int n;
Matrix mul(Matrix A, Matrix B) {
  Matrix C;
  for (int i = 0; i < (int)n; i++)
    for (int j = 0; j < (int)n; j++) {
      C.m[i][j] = 0;
      for (int k = 0; k < (int)n; k++)
        C.m[i][j] = (C.m[i][j] + (long long)A.m[i][k] * B.m[k][j] % mod) % mod;
    }
  return C;
}
Matrix pow_(Matrix A, int c) {
  Matrix ret;
  ret.standard(n);
  while (c > 0) {
    if (c & 1) ret = mul(ret, A);
    A = mul(A, A);
    c >>= 1;
  }
  return ret;
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int r, c, q;
int main() {
  scanf("%d %d %d", &r, &c, &n);
  n = r * c;
  Matrix A;
  A.standard(n);
  for (int i = 0; i < (int)r; i++)
    for (int j = 0; j < (int)c; j++) {
      for (int d = 0; d < (int)4; d++) {
        int ni = i + dx[d], nj = j + dy[d];
        if (ni >= 0 && ni < r && nj >= 0 && nj < c)
          A.m[i * c + j][ni * c + nj] = 1;
      }
    }
  Matrix all, now;
  all.standard(n);
  int pret = 1, vis[22] = {0};
  while (q--) {
    int cmd, x, y, t;
    scanf("%d %d %d %d", &cmd, &x, &y, &t), --x, --y;
    for (int i = 0; i < (int)n; i++)
      for (int j = 0; j < (int)n; j++) {
        if (!vis[i] && !vis[j])
          now.m[i][j] = A.m[i][j];
        else
          now.m[i][j] = 0;
      }
    all = mul(all, pow_(now, t - pret));
    pret = t;
    if (cmd == 2)
      vis[x * c + y] = 1;
    else if (cmd == 3)
      vis[x * c + y] = 0;
    else if (cmd == 1)
      printf("%d\n", all.m[0][x * c + y]);
  }
  return 0;
}
