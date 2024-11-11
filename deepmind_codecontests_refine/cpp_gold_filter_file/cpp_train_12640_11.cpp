#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int pow(int a, int n) {
  long long x = 1;
  long long p = a;
  while (n) {
    if (n & 1) x = (x * p) % mod;
    p = (p * p) % mod;
    n /= 2;
  }
  return (int)x;
}
int n, x[111], y[111], f[1111][1111], m;
int fc[2222];
int rc[2222];
int c[2222][2222];
int main() {
  fc[0] = 1;
  rc[0] = 1;
  for (int i = 1; i < 2222; ++i) {
    fc[i] = (int)(((long long)fc[i - 1] * (long long)i) % mod);
    rc[i] = pow(fc[i], mod - 2);
  }
  for (int(i) = 0; (i) < (2222); ++(i)) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      c[i][j] = (int)((c[i - 1][j - 1] + c[i - 1][j]) % mod);
  }
  cin >> m;
  for (int(i) = 0; (i) < (m); ++(i)) {
    cin >> x[i];
    n += x[i];
  }
  for (int(i) = 0; (i) < (m); ++(i)) cin >> y[i];
  memset(f, 0, sizeof(f));
  f[0][0] = fc[n];
  for (int(i) = 0; (i) < (m); ++(i))
    f[0][0] = (int)(((long long)f[0][0] * (long long)rc[x[i]]) % mod);
  for (int i = 0; i < m; ++i)
    for (int j = 0; j <= n; ++j)
      for (int k = 0; k <= y[i] && k <= j + x[i]; ++k) {
        int val = (int)(((long long)f[i][j] * (long long)c[j + x[i]][k]) % mod);
        f[i + 1][j + x[i] - k] = (int)((f[i + 1][j + x[i] - k] + val) % mod);
      }
  cout << f[m][0] << endl;
}
