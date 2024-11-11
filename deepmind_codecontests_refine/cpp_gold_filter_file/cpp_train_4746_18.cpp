#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
char s[1050][1050];
bool h[251][251], v[251][251];
long long f[251], d[251][251];
int dv[251];
int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= 4 * n; ++i) scanf("%s", s[i]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int p = (i - 1) * 4 + 1, q = (j - 1) * 4 + 1, t = 0;
      for (int k = 0; k < 3; ++k)
        for (int l = 0; l < 3; ++l)
          if (s[p + k][q + l] == 'O') ++t;
      if ((t == 2) || (t == 3)) {
        if (s[p][q] == 'O')
          h[i][j] = true;
        else
          v[i][j] = true;
      } else if (t == 6) {
        if (s[p][q + 1] == 'O')
          h[i][j] = true;
        else
          v[i][j] = true;
      } else {
        h[i][j] = true;
        v[i][j] = true;
      }
    }
  }
  for (int j = 1; j <= m; ++j) {
    if (n % 2 != 0) {
      dv[j] = 0;
      continue;
    }
    dv[j] = 1;
    for (int i = 1; i <= n; ++i) {
      if (!v[i][j]) {
        dv[j] = 0;
        break;
      }
    }
  }
  for (int i = 1; i < m; ++i) {
    d[i][0] = 1;
    if ((h[1][i]) && (h[1][i + 1]))
      d[i][1] = 1;
    else
      d[i][1] = 0;
    for (int j = 2; j <= n; ++j) {
      d[i][j] = 0;
      if ((h[j][i]) && (h[j][i + 1])) d[i][j] = (d[i][j] + d[i][j - 1]) % p;
      if ((v[j - 1][i]) && (v[j][i]) && (v[j - 1][i + 1]) && (v[j][i + 1]))
        d[i][j] = (d[i][j] + d[i][j - 2]) % p;
    }
  }
  f[0] = 1;
  f[1] = dv[1];
  for (int i = 2; i <= m; ++i)
    f[i] = ((f[i - 2] * d[i - 1][n]) % p - (f[i - 2] * dv[i] * dv[i - 1]) % p +
            (f[i - 1] * dv[i]) % p + p) %
           p;
  printf("%I64d\n", f[m]);
  return 0;
}
