#include <bits/stdc++.h>
using namespace std;
long long n, K;
long long f[80][80];
long long lmt[80][80];
char opt[80];
signed main() {
  scanf("%lld%lld", &n, &K);
  for (long long i = 1; i <= K; i++) {
    long long u, v;
    scanf("%lld%s%lld", &u, opt + 1, &v);
    long long len = strlen(opt + 1);
    if (opt[1] == '<' && len == 1) lmt[u][v] = 1, lmt[v][u] = 5;
    if (opt[1] == '<' && len == 2) lmt[u][v] = 2, lmt[v][u] = 4;
    if (opt[1] == '=') lmt[u][v] = lmt[v][u] = 3;
    if (opt[1] == '>' && len == 2) lmt[u][v] = 4, lmt[v][u] = 2;
    if (opt[1] == '>' && len == 1) lmt[u][v] = 5, lmt[v][u] = 1;
  }
  for (long long i = 1; i < (n << 1); i++)
    if (lmt[i][i + 1] != 1 && lmt[i][i + 1] != 5) f[i][i + 1] = 1;
  for (long long len = 2; len < (n << 1); len += 2)
    for (long long i = 1, j = len; j <= (n << 1); i++, j++) {
      if (i > 1 && j < (n << 1))
        if (lmt[i - 1][j + 1] != 1 && lmt[i - 1][j + 1] != 5) {
          bool fl = true;
          for (long long k = i; k <= j; k++)
            if (lmt[i - 1][k] > 2 || lmt[j + 1][k] > 2) fl = false;
          if (fl) f[i - 1][j + 1] += f[i][j];
        }
      if (i > 2)
        if (lmt[i - 2][i - 1] != 1 && lmt[i - 2][i - 1] != 5) {
          bool fl = true;
          for (long long k = i; k <= j; k++)
            if (lmt[i - 2][k] > 2 || lmt[i - 1][k] > 2) fl = false;
          if (fl) f[i - 2][j] += f[i][j];
        }
      if (j < (n << 1) - 1)
        if (lmt[j + 1][j + 2] != 1 && lmt[j + 1][j + 2] != 5) {
          bool fl = true;
          for (long long k = i; k <= j; k++)
            if (lmt[j + 1][k] > 2 || lmt[j + 2][k] > 2) fl = false;
          if (fl) f[i][j + 2] += f[i][j];
        }
    }
  printf("%lld", f[1][n << 1]);
  return 0;
}
