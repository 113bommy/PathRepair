#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int read() {
  char ch = getchar();
  int x = 0, f = 1;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch - '0');
  return x * f;
}
int a[1010];
long long f[510][510];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) f[i][i] = 1;
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      f[i][j] = f[i + 1][j];
      for (int k = i + 1; k < j; k++) {
        if (a[i + 1] < a[k + 1])
          f[i][j] += f[i + 1][k] * f[k][j] % 1000000007, f[i][j] %= 1000000007;
      }
    }
  }
  printf("%lld", f[1][n]);
  return 0;
}
