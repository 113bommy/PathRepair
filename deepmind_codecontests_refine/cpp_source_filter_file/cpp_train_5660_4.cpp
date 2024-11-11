#include <bits/stdc++.h>
using namespace std;
const long long ModNum = (long long)1e9 + 7, maxn = 100 + 5;
long long d[maxn][maxn * maxn], c[maxn][maxn][5];
long long quickM(long long x, long long y) {
  long long t = 1;
  while (y > 0) {
    while (y % 2 == 0 && y > 0) {
      x = (x * x) % ModNum;
      y >>= 2;
    }
    t = (t * x) % ModNum;
    y--;
  }
  return t;
}
int main() {
  long long n, m, k, p;
  cin >> n >> m >> k;
  p = m / n;
  for (int i = 0; i <= n; i++) {
    c[i][0][0] = 1;
    c[i][0][1] = quickM(c[i][0][0], p);
    c[i][0][2] = quickM(c[i][0][0], p + 1);
    for (int j = 1; j <= i; j++) {
      c[i][j][0] = (c[i - 1][j][0] + c[i - 1][j - 1][0]) % ModNum;
      c[i][j][1] = quickM(c[i][j][0], p);
      c[i][j][2] = quickM(c[i][j][0], p + 1);
    }
  }
  memset(d, 0, sizeof(d));
  d[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int expo;
    m % n >= i ? expo = 2 : expo = 1;
    for (int j = 0; j <= k; j++)
      for (int h = 0; h <= n && h <= j; h++)
        d[i][j] = (d[i][j] + d[i - 1][j - h] * c[n][h][expo]) % ModNum;
  }
  cout << d[n][k];
  return 0;
}
