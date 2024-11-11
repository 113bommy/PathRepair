#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
long long MOD = 1e6 + 3;
struct Matrix {
  long long mat[105][105];
};
Matrix matMul(Matrix a, Matrix b) {
  Matrix ans;
  int i, j, k;
  for (i = 0; i < 105; i++)
    for (j = 0; j < 105; j++)
      for (ans.mat[i][j] = k = 0; k < 105; k++)
        ans.mat[i][j] =
            (ans.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % MOD) % MOD;
  return ans;
}
Matrix matPow(Matrix base, long long p) {
  Matrix ans;
  int i, j;
  for (i = 0; i < 105; i++)
    for (j = 0; j < 105; j++) ans.mat[i][j] = (i == j);
  while (p) {
    if (p & 1) ans = matMul(ans, base);
    base = matMul(base, base);
    p >>= 1;
  }
  return ans;
}
Matrix a, b;
long long c, w, h;
int main() {
  cin >> c >> w >> h;
  for (int i = 0; i < w + 1; i++) b.mat[i][0] = 1;
  for (int i = 0; i < w; i++) b.mat[i][i + 1] = h;
  b = matPow(b, c);
  long long res = 0;
  for (int i = 0; i < w + 1; i++) res = (res + b.mat[0][i]) % MOD;
  cout << res << endl;
  return 0;
}
