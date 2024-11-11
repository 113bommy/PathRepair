#include <bits/stdc++.h>
using std::min;
const int MAXN = 305;
const int MOD = 1000000007;
int N, A[MAXN], size[MAXN], tot_s = 0, DP[MAXN][MAXN], C[MAXN][MAXN], Fac[MAXN];
bool grp[MAXN] = {0};
inline bool pfct_sq(long long x) {
  long long sqr = floor(sqrt(x + 0.5));
  return sqr * sqr == x;
}
inline void updata(int& x, int d) { x = ((long long)x + d) % MOD; }
void init();
int main() {
  scanf("%d", &N);
  int i = 0, j;
  for (i = 0; i < N; i++) scanf("%d", &A[i]);
  for (i = 0; i < N; i++)
    if (!grp[i]) {
      for (grp[i] = true, size[tot_s] = 1, j = i + 1; j < N; j++)
        if (A[i] == A[j] || pfct_sq((long long)A[i] * A[j]))
          grp[j] = true, size[tot_s]++;
      tot_s++;
    }
  init();
  int total = 0, k, lim_k, l, lim_l;
  for (i = 0, DP[0][0] = 1; i < tot_s; total += size[i++])
    for (j = 0; j <= total; j++)
      if (DP[i][j]) {
        for (k = 1, lim_k = size[i]; k <= lim_k; k++)
          for (l = 0, lim_l = min(k, j); l <= lim_l; l++)
            updata(DP[i + 1][j - l + size[i] - k],
                   (long long)DP[i][j] * Fac[size[i]] % MOD *
                       C[size[i] - 1][k - 1] % MOD * C[j][l] % MOD *
                       C[total - j + 1][k - l] % MOD);
      }
  printf("%d\n", DP[tot_s][0]);
  return 0;
}
void init() {
  int i, j;
  for (C[0][0] = 1, i = 1; i <= N; i++)
    for (C[i][0] = 1, j = 1; j <= i; j++)
      C[i][j] = ((long long)C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  for (Fac[0] = i = 1; i <= N; i++) Fac[i] = (long long)i * Fac[i - 1] % MOD;
}
