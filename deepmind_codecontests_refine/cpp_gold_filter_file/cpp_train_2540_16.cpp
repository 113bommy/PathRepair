#include <bits/stdc++.h>
int m, n;
int a[2002], b[2002];
int c[2002][2002], f[2002][2002];
using namespace std;
void nhap() {
  int i, j;
  cin >> j;
  for (i = 1; i <= j; i++) {
    cin >> a[i];
    b[a[i]] = 1;
  }
  for (i = 1; i <= j; i++)
    if (b[i] == 0) {
      if (a[i] == -1)
        m++;
      else
        n++;
    }
}
void khoitao() {
  int i, j, k;
  k = max(m, n);
  for (i = 0; i <= k; i++) {
    c[0][i] = 1;
    c[1][i] = i;
    c[i][i] = 1;
  }
  for (i = 2; i <= k; i++)
    for (j = 2; j <= i - 1; j++)
      c[j][i] = (c[j - 1][i - 1] + c[j][i - 1]) % 1000000007;
}
void lam() {
  int i, j, k;
  f[1][0] = 0;
  f[2][0] = 1;
  for (i = 3; i <= m; i++)
    f[i][0] = ((long long)(i - 1) * (f[i - 1][0] + f[i - 2][0])) % 1000000007;
  f[0][0] = 1;
  for (i = 1; i <= n; i++) f[0][i] = ((long long)f[0][i - 1] * i) % 1000000007;
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++) {
      k = ((long long)j * j) % 1000000007;
      f[i][j] = ((long long)f[i][j - 1] * j) % 1000000007;
      k = ((long long)i * j) % 1000000007;
      f[i][j] = (f[i][j] + (long long)f[i - 1][j] * i) % 1000000007;
    }
  cout << f[m][n];
}
int main() {
  nhap();
  khoitao();
  lam();
}
