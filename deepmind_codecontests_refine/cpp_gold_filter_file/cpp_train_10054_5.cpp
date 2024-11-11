#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 7 + 100000;
long long f[MAX_N][4], d[MAX_N][4];
int dig[MAX_N][4];
int main() {
  int n;
  scanf("%d", &n);
  for (int j = 1; j <= 3; j++)
    for (int i = 1; i <= n; i++) scanf("%d", &dig[i][j]);
  long long ans = 0;
  d[1][1] = dig[1][1];
  d[1][3] = dig[1][3];
  f[1][1] = dig[1][1];
  f[1][2] = f[1][1] + dig[1][2];
  f[1][3] = f[1][2] + dig[1][3];
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= 3; j++)
      d[i][j] = f[i][j] = f[i - 1][j] + (long long)dig[i][j];
    f[i][1] = max(f[i][1], d[i][2] + (long long)dig[i][1]);
    f[i][1] =
        max(f[i][1], d[i][3] + (long long)dig[i][2] + (long long)dig[i][1]);
    f[i][2] = max(f[i][2], d[i][1] + (long long)dig[i][2]);
    f[i][2] = max(f[i][2], d[i][3] + (long long)dig[i][2]);
    f[i][3] = max(f[i][3], d[i][2] + (long long)dig[i][3]);
    f[i][3] =
        max(f[i][3], d[i][1] + (long long)dig[i][2] + (long long)dig[i][3]);
    long long tmp = 0;
    for (int k = 0; k <= 1; k++)
      for (int j = 1; j <= 3; j++) tmp += dig[i - k][j];
    f[i][1] = max(f[i][1], tmp + f[i - 2][3]);
    f[i][3] = max(f[i][3], tmp + f[i - 2][1]);
  }
  printf("%I64d", f[n][3]);
}
