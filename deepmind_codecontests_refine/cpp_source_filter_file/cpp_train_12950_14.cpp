#include <bits/stdc++.h>
const int N = 35;
int n, m, A[N][N];
bool F[N][N];
int main() {
  scanf("%d", &n);
  m = (n + 1) >> 1;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &A[i][j]);
      ans += A[i][j];
    }
  memset(F, 0, sizeof(F));
  for (int stat = 0; stat < 1 << m; stat++) {
    int sum = 0;
    for (int i = 1; i <= m; i++) {
      F[m][i] = stat >> (i - 1) & 1;
      sum += (F[m][i] ? -A[m][i] : A[m][i]);
    }
    for (int i = m + 1; i <= n; i++) {
      F[m][i] = F[m][i - m] ^ F[m][m];
      sum += (F[m][i] ? -A[m][i] : A[m][i]);
    }
    for (int i = 1; i < m; i++) {
      int s;
      for (int j = 0; j < 2; j++, F[i][m] ^= 1) {
        F[i][i + m] = F[i][m] ^ F[m][m];
        int ts = (F[i][m] ? -A[i][m] : A[i][m]) +
                 (F[i + m][m] ? -A[i + m][m] : A[i + m][m]);
        for (int k = 1; k < m; k++) {
          int t;
          for (int l = 0; l < 2; l++, F[i][k] ^= 1) {
            F[i][k + m] = F[i][k] ^ F[i][m];
            F[i + m][k] = F[i][k] ^ F[m][k];
            F[i + m][k + m] = F[i][k + m] ^ F[m][k + m];
            t = l ? (t > ((F[i][k] ? -A[i][k] : A[i][k]) +
                          (F[i + m][k] ? -A[i + m][k] : A[i + m][k]) +
                          (F[i][k + m] ? -A[i][k + m] : A[i][k + m]) +
                          (F[i + m][k + m] ? -A[i + m][k + m]
                                           : A[i + m][k + m]))
                         ? t
                         : ((F[i][k] ? -A[i][k] : A[i][k]) +
                            (F[i + m][k] ? -A[i + m][k] : A[i + m][k]) +
                            (F[i][k + m] ? -A[i][k + m] : A[i][k + m]) +
                            (F[i + m][k + m] ? -A[i + m][k + m]
                                             : A[i + m][k + m])))
                  : ((F[i][k] ? -A[i][k] : A[i][k]) +
                     (F[i + m][k] ? -A[i + m][k] : A[i + m][k]) +
                     (F[i][k + m] ? -A[i][k + m] : A[i][k + m]) +
                     (F[i + m][k + m] ? -A[i + m][k + m] : A[i + m][k + m]));
          }
          ts += t;
        }
        s = F[i][m] ? (s > ts ? s : ts) : ts;
      }
      sum += s;
    }
    ans = (ans > sum ? ans : sum);
  }
  printf("%d\n", ans);
  return 0;
}
