#include <bits/stdc++.h>
using namespace std;
int n, k;
struct mat {
  long long x[90][90];
  mat() { memset(x, 0, sizeof(x)); }
  mat(int k) {
    memset(x, 0, sizeof(x));
    for (int i = 0; i < 90; i++) x[i][i] = 1;
  }
};
mat operator*(mat &a, mat &b) {
  mat res;
  for (int i = 0; i < 90; i++) {
    for (int j = 0; j < 90; j++) {
      long long aux = 0;
      for (int k = 0; k < 90; k++)
        aux = (aux + (a.x[i][k] * b.x[k][j]) % 1000000007) % 1000000007;
      res.x[i][j] = aux % 1000000007;
    }
  }
  return res;
}
mat pot(mat a, long long k) {
  mat res(1);
  while (k > 0) {
    if (k & 1) res = res * a;
    a = a * a;
    k >>= 1;
  }
  return res;
}
void imp(mat a) {
  for (int i = 0; i <= 2 * k + 2; i++) {
    for (int j = 0; j <= 2 * k + 2; j++) cout << a.x[i][j] << " ";
    cout << endl;
  }
}
long long tc[50][50];
long long comb(int a, int b) {
  long long &ret = tc[a][b];
  if (ret != -1) return ret;
  if (a == b) return ret = 1;
  if (b == 0) return ret = 1;
  return ret = (comb(a - 1, b) + comb(a - 1, b - 1)) % 1000000007;
}
long long fs() {
  if (n == 1) return 1;
  mat res;
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= i; j++) {
      res.x[i][j + k + 1] = comb(i, j);
      res.x[i + k + 1][j] = comb(i, j);
      res.x[i + k + 1][j + k + 1] = comb(i, j);
    }
  for (int i = 0; i <= k; i++) res.x[2 * k + 2][i + k + 1] = comb(k, i);
  res.x[2 * k + 2][2 * k + 2] = 1;
  res = pot(res, n - 1);
  long long resp = 0;
  for (int i = 0; i <= k; i++) resp = (resp + res.x[2 * k + 2][i]) % 1000000007;
  for (int i = 0; i <= k; i++)
    resp = (resp + 2LL * res.x[2 * k + 2][i + k + 1]) % 1000000007;
  resp = (resp + 1) % 1000000007;
  return resp;
}
int main() {
  memset(tc, -1, sizeof(tc));
  cin >> n >> k;
  cout << fs() << endl;
}
