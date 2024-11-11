#include <bits/stdc++.h>
using namespace std;
int m, p;
int n;
long long b[22];
long long e[(1 << 20)];
int dp[2][21][(1 << 20)];
void calc() {
  for (int i = 0; i < n; i++) dp[1][0][i] = e[i];
  for (int i = 0; i < m; i++)
    for (int k = 0; k <= m && k <= i + 1; k++)
      for (int j = 0; j < n; j++)
        dp[i & 1][k][j] = (dp[1 - (i & 1)][k][j] +
                           (k ? dp[1 - (i & 1)][k - 1][j ^ (1 << i)] : 0)) %
                          p;
  memset(e, 0, sizeof(e));
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= m; j++)
      e[i] = (b[j] * dp[1 - (m & 1)][j][i] + e[i]) % p;
}
long long dp2[65][22];
long long v[22][22][22];
long long aux[22];
int main() {
  long long t;
  scanf("%d%I64d%d", &m, &t, &p);
  n = 1 << m;
  for (int i = 0; i <= m; i++) {
    int tgt = (1 << i) - 1;
    for (int j = 0; j < n; j++)
      v[i][__builtin_popcount(j)][__builtin_popcount(j ^ tgt)]++;
  }
  for (int i = 0; i < n; i++) scanf("%I64d", e + i);
  for (int i = 0; i <= m; i++) scanf("%I64d", b + i);
  for (int i = 0; i <= m; i++) dp2[0][i] = b[i];
  for (int i = 1; i < 64; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= m; k++)
        for (int l = 0; l <= m; l++)
          dp2[i][j] = (dp2[i][j] +
                       (v[j][k][l] * (dp2[i - 1][k] * dp2[i - 1][l]) % p) % p) %
                      p;
  int f = 1;
  for (int i = 0; i < 64; i++)
    if (t & (1LL << i)) {
      if (f) {
        f = 0;
        for (int j = 0; j <= m; j++) b[j] = dp2[i][j];
        continue;
      }
      memset(aux, 0, sizeof(aux));
      for (int j = 0; j <= m; j++)
        for (int k = 0; k <= m; k++)
          for (int l = 0; l <= m; l++)
            aux[j] = (aux[j] + (v[j][k][l] * (dp2[i][k] * b[l]) % p) % p) % p;
      for (int j = 0; j <= m; j++) b[j] = aux[j];
    }
  for (int i = 0; i <= m; i++)
    ;
  ;
  calc();
  for (int i = 0; i < n; i++) printf("%I64d\n", e[i]);
}
