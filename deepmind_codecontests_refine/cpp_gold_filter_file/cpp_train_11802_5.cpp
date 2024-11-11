#include <bits/stdc++.h>
using namespace std;
long long m, l, r, k;
long long base[2][2] = {1, 1, 1, 0};
void mult(long long a[2][2], long long b[2][2], long long c[2][2]) {
  memset(c, 0, sizeof base);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % m;
}
void pow(long long pot, long long mat[2][2]) {
  if (pot == 1) {
    memcpy(mat, base, sizeof base);
    return;
  }
  if (pot & 1) {
    long long aux[2][2];
    pow(pot - 1, aux);
    mult(aux, base, mat);
  } else {
    long long aux[2][2];
    pow(pot / 2, aux);
    mult(aux, aux, mat);
  }
}
long long fibo(long long low) {
  if (low == 1) return 1 % m;
  long long mat[2][2];
  pow(low - 1, mat);
  return mat[0][0] % m;
}
long long calc(long long num) { return r / num - (l - 1) / num; }
long long solve() {
  long long lim = sqrt(r) + 1;
  long long res = 0;
  for (long long i = 1; i <= lim; ++i) {
    if (calc(i) >= k) res = max(res, i);
    if (calc(r / i) >= k) res = max(res, r / i);
  }
  return fibo(res);
}
int main() {
  cin >> m >> l >> r >> k;
  cout << solve() << endl;
  return 0;
}
