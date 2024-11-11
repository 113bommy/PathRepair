#include <bits/stdc++.h>
using namespace std;
const int N = 57, M = 1e5 + 7, MOD = 998244353;
int f[N][M], s[M];
int _L[N], _R[N], L[N], R[N];
int primes[M], cnt, mob[M];
bool st[M];
void init() {
  mob[1] = 1;
  for (int i = 2; i <= M - 1; ++i) {
    if (!st[i]) primes[cnt++] = i, mob[i] = -1;
    for (int j = 0; j < cnt && 1ll * primes[j] * i < M; ++j) {
      st[primes[j] * i] = 1;
      if (i % primes[j] == 0) break;
      mob[i * primes[j]] = -mob[i];
    }
  }
}
int dp(int n, int m) {
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j)
      s[j] = ((j > 0 ? s[j - 1] : 0) + f[i - 1][j]) % MOD;
    for (int j = L[i]; j <= m; ++j)
      f[i][j] = (s[j - L[i]] - (j - R[i] <= 0 ? 0 : s[j - R[i] - 1])) % MOD;
  }
  int res = 0;
  for (int j = 0; j <= m; ++j) res = (res + f[n][j]) % MOD;
  return res;
}
int main() {
  init();
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &_L[i], &_R[i]);
  int res = 0;
  for (int d = 1; d <= m; ++d) {
    for (int i = 1; i <= n; ++i) L[i] = (_L[i] + d - 1) / d, R[i] = _R[i] / d;
    res = (res + 1ll * mob[d] * dp(n, m / d) % MOD) % MOD;
    res = (res % MOD + MOD) % MOD;
  }
  printf("%d\n", res);
  return 0;
}
