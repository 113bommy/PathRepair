#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007, N = 55, T = 2505, G = 3;
inline void add(long long &a, long long b) { a = (a + b % P) % P; }
long long f[N], a[N][T], bc[N][N][T], dp[N][N][N][G + 1], cnt[G + 1], tt[G + 1];
int main() {
  int n, T;
  scanf("%d%d", &n, &T);
  a[0][0] = bc[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int t, g;
    scanf("%d%d", &t, &g);
    g--;
    if (g) {
      for (int c1 = cnt[1]; c1 >= 0; c1--)
        for (int c2 = cnt[2]; c2 >= 0; c2--)
          for (int j = 0; j <= tt[1] + tt[2]; j++)
            add(bc[c1 + (g == 1)][c2 + (g == 2)][j + t], bc[c1][c2][j]);
    } else {
      for (int c0 = cnt[0]; c0 >= 0; c0--)
        for (int j = 0; j <= tt[0]; j++) add(a[c0 + 1][j + t], a[c0][j]);
    }
    ++cnt[g];
    tt[g] += t;
  }
  dp[0][0][0][3] = 1;
  for (int i = 0; i <= cnt[0]; i++)
    for (int j = 0; j <= cnt[1]; j++)
      for (int k = 0; k <= cnt[2]; k++)
        for (int l = 0; l <= G; l++)
          if (dp[i][j][k][l])
            for (int n = 0; n <= 2; n++)
              if (n != l && (n == 0 ? i : (n == 1 ? j : k)) < cnt[n])
                add(dp[i + (n == 0)][j + (n == 1)][k + (n == 2)][n],
                    dp[i][j][k][l]);
  f[0] = 1;
  for (int i = 1; i <= N - 5; i++) f[i] = f[i - 1] * i % P;
  long long ans = 0;
  for (int i = 0; i <= cnt[0]; i++)
    for (int t0 = 0; t0 <= tt[0]; t0++)
      if (T >= t0)
        for (int j = 0; j <= cnt[1]; j++)
          for (int k = 0; k <= cnt[2]; k++) {
            long long tmp = a[i][t0] * bc[j][k][T - t0] % P;
            for (int l = 0; l <= 2; l++)
              tmp = tmp * f[(l == 0 ? i : (l == 1 ? j : k))] % P;
            for (int l = 0; l <= 2; l++)
              if ((l == 0 ? i : (l == 1 ? j : k)))
                add(ans, tmp * dp[i][j][k][l]);
          }
  cout << ans << endl;
  return 0;
}
