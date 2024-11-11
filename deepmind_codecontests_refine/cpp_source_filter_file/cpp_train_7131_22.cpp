#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200, MAXS = 5e4;
int f[MAXN][MAXS], N, K, S, r = 1e9;
int main() {
  memset(f, 63, sizeof(f));
  for (int i = 0; i < MAXS; i++) f[0][i] = 0;
  scanf("%d%d%d", &N, &K, &S);
  for (int i = 1, x; i <= N; i++) {
    scanf("%d", &x);
    for (int n = min(i, K); n >= 1; n--)
      for (int s = MAXS - 1; s >= i; s--)
        f[n][s] = min(f[n][s], f[n - 1][s - i] + x);
  }
  printf("%d\n", f[K][K * (K + 1) / 2 + min(S, K * (K + 1) / 2)]);
}
