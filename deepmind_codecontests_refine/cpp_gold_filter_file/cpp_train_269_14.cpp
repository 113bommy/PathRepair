#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
double dp[2][51][5005], p[51];
int N, R, F[51], S[51], P[51], U[51], V[51], I;
int main(void) {
  scanf("%d%d", &N, &R);
  for (int i(0); i < N; i++)
    scanf("%d%d%d", F + i, S + i, P + i),
        U[i] = F[i], V[i] = S[i], p[i] = P[i] / 100., S[i] -= F[i], R -= F[i],
        F[i] = 0;
  for (int i(0); i < 51; i++)
    for (int j(0); j < 5005; j++) dp[1][i][j] = int(1e9 + 1);
  I = 1e8 / (N * (R + 1));
  for (int i(0); i < I; i++)
    for (int j = N; ~j; --j)
      for (int k = R; ~k; --k)
        dp[i & 1][j][k] =
            j == N ? 0
                   : min(dp[(i + 1) & 1][0][0],
                         p[j] * (U[j] + (k + F[j] > R
                                             ? dp[(i + 1) & 1][0][0]
                                             : dp[(i)&1][j + 1][k + F[j]])) +
                             (1 - p[j]) *
                                 (V[j] + (k + S[j] > R
                                              ? dp[(i + 1) & 1][0][0]
                                              : dp[(i)&1][j + 1][k + S[j]])));
  printf("%.30lf\n", dp[0][0][0]);
  return 0;
}
