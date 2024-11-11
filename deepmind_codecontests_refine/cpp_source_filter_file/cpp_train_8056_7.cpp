#include <bits/stdc++.h>
using namespace std;
long long pow(long long a, int x) {
  if (x == 0) return 1;
  if (x == 1) return a;
  long long k = x / 2;
  long long temp = pow(a, k);
  if (x % 2 == 0)
    return temp * temp;
  else
    return temp * temp * a;
}
long long n, a[20], f[50][20][20], rr;
char c, r[20];
int main() {
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> c;
    a[i] = c - '0';
  }
  for (int i = 1; i <= 2 * n; i++)
    for (int j = 0; j <= n; ++j)
      for (int k = 0; k <= n; ++k) {
        if (j == 0 && k != 0)
          f[i][j][k] = f[i - 1][j][k - 1] + a[i] * pow(10, n - k);
        if (k == 0 && j != 0)
          f[i][j][k] = f[i - 1][j - 1][k] + a[i] * pow(10, n - j);
        if (j > 0 && k > 0)
          f[i][j][k] = max(f[i - 1][j - 1][k] + a[i] * pow(10, n - j),
                           f[i - 1][j][k - 1] + a[i] * pow(10, n - k));
      }
  int i1 = n * 2;
  int i2 = n;
  int i3 = n;
  int n1 = 1;
  while (i1 >= 1) {
    long long tt = f[i1][i2][i3];
    if (tt == f[i1 - 1][i2 - 1][i3] + a[i1] * pow(10, n - i2) && n1 <= n) {
      r[i1] = 'M';
      --i1;
      --i2;
      ++n1;
    } else if (tt == f[i1 - 1][i2][i3 - 1] + a[i1] * pow(10, n - i3)) {
      r[i1] = 'H';
      --i1;
      --i3;
    }
  }
  for (int i = 1; i <= 2 * n; i++) cout << r[i];
}
