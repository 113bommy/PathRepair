#include <bits/stdc++.h>
using namespace std;
const long long P = 1000000007;
int m, len;
long long n;
long long v[61];
struct M {
  long long v[31][31];
  M() { memset(v, 0, sizeof(v)); }
  long long *operator[](const int &a) { return v[a]; }
  M operator*(const M &a) const {
    M b;
    int i, j, k;
    for (i = 0; i <= m; i++)
      for (j = 0; j <= m; j++)
        for (k = 0; k <= m; k++)
          b.v[i][j] = (b.v[i][j] + v[i][k] * a.v[k][j]) % P;
    return b;
  }
} T[60][30], S, s1[60][30], s2[60][30];
int main() {
  scanf("%lld%d", &n, &m);
  v[0] = n;
  while (v[len]) v[len + 1] = v[len] / m, v[len] %= m, len++;
  int i, j, a, b;
  for (i = 0; i <= m; i++) S[0][i] = 1;
  for (i = 0; i < len; i++) {
    for (j = 0; j <= m; j++) T[i][0][j][j] = 1;
    if (!i) {
      for (j = 0; j < m; j++) {
        T[i][j][m][m] = 1;
        for (a = 0; a < m; a++) {
          if (a != j) {
            T[i][j][a][a] = 1;
            continue;
          }
          for (b = 0; b <= m; b++) T[i][j][a][b] = 1;
        }
      }
    } else {
      for (j = 0; j < m; j++) {
        if (!j)
          T[i][j] = s2[i - 1][0];
        else
          T[i][j] = s2[i - 1][j] * s1[i - 1][j - 1];
      }
    }
    for (s1[i][0] = T[i][0], j = 1; j < m; j++)
      s1[i][j] = s1[i][j - 1] * T[i][j];
    for (s2[i][m - 1] = T[i][m - 1], j = m - 2; j >= 0; j--)
      s2[i][j] = T[i][j] * s2[i][j + 1];
  }
  for (i = len - 1, j = 0; i >= 0; i--) {
    while (v[i]--) S = S * T[i][j], j = (j + 1) % m;
  }
  printf("%lld", S[0][m]);
  return 0;
}
