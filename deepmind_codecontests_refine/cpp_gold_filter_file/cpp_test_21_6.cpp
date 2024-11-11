#include <bits/stdc++.h>
using namespace std;
const int N = 100;
long long f[N + 5][N + 5][N + 5];
long long fac[N + 5], C[N + 5][N + 5];
long long mod;
long long dfs(int n, int m, int k) {
  if (n == 0) return k == 0;
  if (m == 1) return k == 1 ? fac[n] : 0;
  if (n == 1) return k == 0;
  if (2 * k > n + 1) return 0;
  if (m > n) return k == 0 ? fac[n] : 0;
  if (f[n][m][k] != -1) return f[n][m][k];
  if (m * k > 3000) return 0;
  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= k; j++)
      ans = (ans + C[n - 1][i] * dfs(i, m - 1, j) % mod *
                       dfs(n - i - 1, m - 1, k - j) % mod) %
            mod;
  return f[n][m][k] = ans;
}
int main() {
  memset(f, 0xff, sizeof(f));
  int n, m, k;
  scanf("%d%d%d%lld", &n, &m, &k, &mod);
  for (int i = 0; i <= N; i++) C[i][0] = C[i][i] = 1;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  fac[0] = fac[1] = 1;
  for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % mod;
  printf("%lld", dfs(n, m, k));
  return 0;
}
