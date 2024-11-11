#include <bits/stdc++.h>
using namespace std;
const long long inv = 500000004;
const int p = 1e9 + 7;
const int N = 55;
int n, m;
long long c[N][N];
long long f[N][N][2];
long long mo(long long x) { return x >= p ? x % p : x; }
void pre() {
  c[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; ++j) c[i][j] = mo(c[i - 1][j - 1] + c[i - 1][j]);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  if ((m < n / 3 || m > n / 2) && (n != 4)) {
    puts("0");
    return 0;
  }
  pre();
  f[1][0][0] = 1;
  f[0][0][1] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      for (int L = 0; L <= i; ++L) {
        int R = i - 1 - L;
        if (R < L) break;
        long long tmp = c[i - 1][L];
        if (L == R) tmp *= inv;
        if (L)
          tmp = tmp * L % p * R;
        else
          tmp = tmp * R;
        tmp %= p;
        for (int k = 0; k <= j; ++k) {
          f[i][j][0] =
              mo(f[i][j][0] + tmp * f[L][k][1] % p * f[R][j - k][1] % p);
          if (k == j) continue;
          f[i][j][1] =
              mo(f[i][j][1] + tmp * f[L][k][1] % p * f[R][j - k - 1][0] % p);
          f[i][j][1] =
              mo(f[i][j][1] + tmp * f[L][k][0] % p * f[R][j - k - 1][1] % p);
          f[i][j][1] =
              mo(f[i][j][1] + tmp * f[L][k][0] % p * f[R][j - k - 1][0] % p);
        }
      }
  cout << (f[n][m][0] + f[n][m][1]) % p;
  return 0;
}
