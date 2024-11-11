#include <bits/stdc++.h>
using namespace std;
int x[20000], y[20000], last[10002][626];
long long f[2][20000];
char str[40000];
int main() {
  int n, m, v, o, p, q;
  cin >> n >> m >> v;
  o = n + m - 2;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) cin >> y[i];
  for (int i = 0; i < n; i++) {
    memset(f[~i & 1], 0, sizeof(long long) * m);
    for (int j = 0; j < m; j++) {
      f[i & 1][j] += (x[i] + y[j]) % v;
      if (i < n - 1 && f[i & 1][j] >= f[~i & 1][j]) {
        f[~i & 1][j] = f[i & 1][j];
        if (i + 1 > n / 2) last[i + 1 - n / 2][j >> 5] |= (1 << (j & 31));
      }
      if (j < m - 1 && f[i & 1][j] >= f[i & 1][j + 1]) {
        f[i & 1][j + 1] = f[i & 1][j];
        if (i > n / 2) last[i - n / 2][(j + 1) >> 5] &= ~(1 << ((j + 1) & 31));
      }
    }
  }
  cout << f[(n - 1) & 1][m - 1] << endl;
  p = n - 1;
  q = m - 1;
  while (p > n / 2)
    if (last[p - n / 2][q >> 5] & (1 << (q & 31))) {
      str[o--] = 'C';
      p--;
    } else {
      str[o--] = 'S';
      q--;
    }
  memset(f[0], 0, sizeof(long long) * (q + 1));
  for (int i = 0; i <= p; i++) {
    memset(f[~i & 1], 0, sizeof(long long) * (q + 1));
    for (int j = 0; j <= q; j++) {
      f[i & 1][j] += (x[i] + y[j]) % v;
      if (i < p && f[i & 1][j] >= f[~i & 1][j]) {
        f[~i & 1][j] = f[i & 1][j];
        last[i + 1][j >> 5] |= (1 << (j & 31));
      }
      if (j < q && f[i & 1][j] >= f[i & 1][j + 1]) {
        f[i & 1][j + 1] = f[i & 1][j];
        last[i][(j + 1) >> 5] &= ~(1 << ((j + 1) & 31));
      }
    }
  }
  while (p | q)
    if (last[p][q >> 5] & (1 << (q & 31))) {
      str[o--] = 'C';
      p--;
    } else {
      str[o--] = 'S';
      q--;
    }
  cout << str + 1 << endl;
  return 0;
}
