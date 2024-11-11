#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0, b = getchar(), c = 1;
  while (!isdigit(b)) c = b == '-' ? -1 : 1, b = getchar();
  while (isdigit(b)) a = a * 10 + b - '0', b = getchar();
  return a * c;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  int y = x % 10 + '0';
  if (x >= 10) print(x / 10);
  putchar(y);
}
int n, m, l, r, a[1105], b[1105], dp[2][1105][50][50];
int main() {
  n = read(), m = read(), l = read();
  r = read();
  for (int i = 1; i <= r; i++) {
    int x = read();
    a[x] = 1;
  }
  r = read();
  for (int i = 1; i <= r; i++) {
    int x = read();
    b[x] = 1;
  }
  m = min(m, 2 * n / l + 1);
  int x = 0, y = 1, z;
  for (int i = 1; i <= n; i++) {
    swap(x, y);
    for (int j = 0; j <= m; j++)
      for (int p = 0; p <= l; p++)
        for (int q = 0; q <= l; q++) {
          int &k = dp[x][j][p][q];
          z = (p and a[i]) or (q and b[i]);
          k = dp[y][j][p - (p > 0)][q - (q > 0)] + z;
          if (j and !p) k = max(k, dp[x][j - 1][l][q]);
          if (j and !q) k = max(k, dp[x][j - 1][p][l]);
        }
  }
  print(dp[x][m][0][0]);
  return 0;
}
