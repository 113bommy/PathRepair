#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
int k, ans, b[40], f[40][40][2], c[40][40];
int read() {
  int ret = 0, sig = 1;
  char c;
  while (c = getchar(), (c < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    sig = -1;
  else
    ret = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - '0';
  return ret * sig;
}
int main() {
  c[0][0] = 1;
  for (int i = 1; i <= 40; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= 40; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mo;
  }
  k = read();
  while (k) {
    b[++b[0]] = k % 2;
    k /= 2;
  }
  reverse(b + 1, b + 1 + b[0]);
  f[0][0][1] = 1;
  for (int i = 0; i <= b[0] - 1; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k <= 1; k++)
        if (f[i][j][k]) {
          if (b[i + 1] || !k) {
            if (k && b[i + 1])
              f[i + 1][j + 1][1] = (f[i + 1][j + 1][1] + f[i][j][k]) % mo;
            else
              f[i + 1][j + 1][0] = (f[i + 1][j + 1][0] + f[i][j][k]) % mo;
          }
          for (int x = 0; x <= j; x++) {
            int sum = 1LL * c[j][x] * f[i][j][k] % mo;
            if (x % 2) {
              if (b[i + 1] || !k) {
                if (k && b[i + 1])
                  f[i + 1][j][1] = (f[i + 1][j][1] + sum) % mo;
                else
                  f[i + 1][j][0] = (f[i + 1][j][0] + sum) % mo;
              }
            } else {
              if (k && !b[i + 1])
                f[i + 1][j][1] = (f[i + 1][j][1] + sum) % mo;
              else
                f[i + 1][j][0] = (f[i + 1][j][0] + sum) % mo;
            }
          }
        }
  for (int i = 0; i <= b[0]; i++)
    ans = (ans + (f[b[0]][i][0] + f[b[0]][i][1]) % mo) % mo;
  printf("%d\n", ans);
  return 0;
}
