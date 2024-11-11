#include <bits/stdc++.h>
const int MAXN = 305;
const int PSIZE = 40000;
const int ARSIZE = 1200;
const int INF = 0x3f3f3f3f;
int N, L[MAXN], C[MAXN], P[PSIZE], Q[10], totp = 0, DP[ARSIZE];
bool flag[PSIZE] = {0};
void init_prime(int lim);
int main() {
  scanf("%d", &N);
  int i, maxl = 0;
  for (i = 0; i < N; i++) {
    scanf("%d", &L[i]);
    maxl = std::max(maxl, L[i]);
  }
  for (i = 0; i < N; i++) scanf("%d", &C[i]);
  init_prime(int(sqrt(maxl + 0.5)));
  int Li, j, cntp, k, x, MAXS, ans = INF;
  for (i = 0; i < N; i++) {
    memset(DP, 0x3f, sizeof(DP));
    DP[0] = 0;
    for (Li = L[i], j = 0, cntp = 0; j < totp && Li >= P[j]; j++) {
      if (!(Li % P[j])) {
        Q[cntp++] = P[j];
        while (!(Li % P[j])) Li /= P[j];
      }
    }
    if (Li > 1) Q[cntp++] = Li;
    for (j = 0, MAXS = 1 << cntp; j < N; j++) {
      for (k = 0, x = 0; k < cntp; k++)
        if (L[j] % Q[k]) x |= (1 << k);
      for (k = 0; k < MAXS; k++)
        if (DP[k] != INF) DP[k | x] = std::min(DP[k | x], DP[k] + C[j]);
    }
    ans = std::min(ans, DP[MAXS - 1] + C[i]);
  }
  printf("%d\n", ans == INF ? -1 : ans);
  return 0;
}
void init_prime(int lim) {
  int i, j;
  for (i = 2; i <= lim; i++)
    if (!flag[i]) {
      P[totp++] = i;
      for (j = i << 1; j <= lim; j += i) flag[j] = true;
    }
}
