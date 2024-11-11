#include <bits/stdc++.h>
using namespace std;
namespace mat_exp {
int matN = 2;
const int MAX = 2;
void cross(int result[MAX][MAX], int matA[MAX][MAX], int matB[MAX][MAX],
           int mod) {
  for (int i = 0; i < matN; i++)
    for (int j = 0; j < matN; j++) {
      result[i][j] = 0;
      for (int k = 0; k < matN; k++) {
        result[i][j] = (result[i][j] + 1ll * matA[i][k] * matB[k][j]) % mod;
      }
    }
}
void matCopy(int A[MAX][MAX], int B[MAX][MAX]) {
  for (int i = 0; i < matN; i++)
    for (int j = 0; j < matN; j++) {
      A[i][j] = B[i][j];
    }
}
void matExpo(int result[MAX][MAX], int mat[MAX][MAX], long long exponent,
             int mod) {
  for (int i = 0; i < matN; i++)
    for (int j = 0; j < matN; j++) {
      result[i][j] = int(i == j);
    }
  int base[MAX][MAX], tmp[MAX][MAX];
  matCopy(base, mat);
  while (exponent > 0) {
    if (exponent & 1) {
      cross(tmp, result, base, mod);
      matCopy(result, tmp);
    }
    cross(tmp, base, base, mod);
    matCopy(base, tmp);
    exponent >>= 1;
  }
}
int getVal(int mat[MAX][MAX], int *f, long long n, int mod) {
  int ret = 0;
  if (n < matN) {
    return f[n];
  }
  int result[MAX][MAX];
  matExpo(result, mat, n - matN + 1, mod);
  for (int i = 0; i < matN; i++) {
    ret = (ret + 1ll * f[matN - i - 1] * result[0][i]) % mod;
  }
  return ret;
}
}  // namespace mat_exp
int pwr(int base, long long ex, int mod) {
  int ret = 1;
  while (ex > 0) {
    if (ex & 1) {
      ret = 1ll * base * ret % mod;
    }
    ex >>= 1;
    base = 1ll * base * base % mod;
  }
  return ret;
}
using namespace mat_exp;
int main() {
  std::ios_base::sync_with_stdio(false);
  long long n, k;
  int l, m;
  cin >> n >> k >> l >> m;
  int mat[2][2] = {{1 % m, 1 % m}, {1 % m, 0}};
  int f[] = {1 % m, 2 % m};
  int one = __builtin_popcount(k);
  int fn = getVal(mat, f, n, m);
  int tn = pwr(2, n, m);
  int ans = 1ll * pwr((tn - fn + m) % m, one, m) * pwr(fn, l - one, m) % m;
  int o = 1;
  if (l < 64 && (1ull << l) - 1 < 1ull * k) {
    o = 0;
  }
  cout << ans * o << endl;
  return 0;
}
