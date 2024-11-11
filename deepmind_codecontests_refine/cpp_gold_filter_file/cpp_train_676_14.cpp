#include <bits/stdc++.h>
using namespace std;
inline long long mult(long long a, long long b, long long mod) {
  if (b == 0) return 0;
  if (b % 2 == 1) return (mult(a, b - 1, mod) + a) % mod;
  return (mult(a, b / 2, mod) * 2) % mod;
}
inline long long BinPow(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 1) return (mult(BinPow(a, b - 1, mod), a, mod)) % mod;
  long long res = BinPow(a, b / 2, mod);
  return mult(res, res, mod);
}
int n, m, k, w, kol, kol1, w1, sum1;
char a[150][140][130];
int sum;
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int t = 1; t <= k; t++) cin >> a[i][j][t];
  for (int l = 1; l <= n; l++)
    for (int j = 1; j <= m; j++)
      for (int t = 1; t <= k; t++) {
        if (a[l][j][t] == '1') {
          if (a[l - 1][j][t] == '1')
            if (a[l + 1][j][t] == '1') w = 1;
          if (a[l][j - 1][t] == '1')
            if (a[l][j + 1][t] == '1') w = 1;
          if (a[l][j][t - 1] == '1')
            if (a[l][j][t + 1] == '1') w = 1;
          if (a[l - 1][j][t] == '1') {
            if (a[l - 1][j + 1][t] == '0')
              if (a[l][j + 1][t] == '1') w1 = 1;
            if (a[l - 1][j][t + 1] == '0')
              if (a[l][j][t + 1] == '1') w1 = 1;
          }
          if (a[l][j - 1][t] == '1') {
            if (a[l][j - 1][t + 1] == '0')
              if (a[l][j][t + 1] == '1') w1 = 1;
            if (a[l + 1][j - 1][t] == '0')
              if (a[l + 1][j][t] == '1') w1 = 1;
          }
          if (a[l][j][t - 1] == '1') {
            if (a[l][j + 1][t - 1] == '0')
              if (a[l][j + 1][t] == '1') w1 = 1;
            if (a[l + 1][j][t - 1] == '0')
              if (a[l + 1][j][t] == '1') w1 = 1;
          }
          if (w || w1) sum++;
          w1 = w = 0;
        }
      }
  cout << sum;
  return 0;
}
