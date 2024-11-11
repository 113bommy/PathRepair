#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e3 + 5;
const long long INF = 1e18;
const long long MOD = 998244353;
int dp[maxN][maxN];
int res[maxN], iv[maxN];
int modP(int a, int b = MOD - 2) {
  if (!b) return 1;
  int c = modP(a, b >> 1);
  c = (1ll * c * c) % MOD;
  if (b & 1) c = (1ll * a * c) % MOD;
  return c;
}
int main() {
  time_t START = clock();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  scanf("%d", &n);
  int f = 1;
  for (int i = 1; i <= n; i++) f = (1ll * f * i) % MOD;
  iv[n] = modP(f);
  for (int i = n; i > 0; i--) iv[i - 1] = (1ll * i * iv[i]) % MOD;
  dp[1][0] = 1;
  for (int i = 2; i <= n + 1; i++)
    for (int j = 0; j < i; j++) {
      dp[i][j] = (1ll * dp[i - 1][j] * (j + 1) +
                  (j ? 1ll * dp[i - 1][j - 1] * (i - j) : 0ll)) %
                 MOD;
      if (j)
        res[j - 1] =
            (res[j - 1] + 0ll + 1ll * dp[i - 1][j - 1] * f % MOD * iv[i - 1]) %
            MOD;
    }
  for (int i = 0; i < n; i++) printf("%d ", res[i]);
  printf("\n");
  time_t FINISH = clock();
  cerr << "Execution time: "
       << (long double)(FINISH - START) / CLOCKS_PER_SEC * 1000.0
       << " milliseconds.\n";
  return 0;
}
