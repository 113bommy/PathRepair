#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, M = 5100;
int n, m, P, L[N], Mx, A[M];
int g[M][M], dp[M], jc[M], f[N], w[M];
int main() {
  cin >> n >> m >> P;
  for (int i = 1; i <= n; i++) scanf("%d", &L[i]), Mx = max(Mx, L[i]);
  g[0][0] = jc[0] = A[0] = 1;
  for (int j = 1; j <= Mx; j++)
    for (int i = 1; i <= Mx; i++)
      g[j][i] = (g[j - 1][i - 1] + 1ll * g[j][i - 1] * (j - 1) % P);
  for (int i = 1; i <= Mx; i++)
    jc[i] = 1ll * jc[i - 1] * i % P, A[i] = 1ll * A[i - 1] * (m - i + 1) % P;
  dp[0] = f[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= min(L[i], m); j++) {
      dp[j] = 0;
      (dp[j] += 1ll * f[i - 1] * A[j] % P * g[j][L[i]] % P) %= P;
      if (j <= L[i - 1])
        (dp[j] += P - 1ll * w[j] * jc[j] % P * g[j][L[i]] % P) %= P;
      w[j] = dp[j];
      (f[i] += dp[j]) %= P;
    }
  cout << f[n] << endl;
}
