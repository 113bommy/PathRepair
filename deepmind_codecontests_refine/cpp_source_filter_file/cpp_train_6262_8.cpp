#include <bits/stdc++.h>
using namespace std;
const int MN = 5005, inf = 1000000005, mod = 998244353;
const long long INF = 1000000000000000005LL;
long long dp[MN][MN], rev[MN];
int ile[MN];
long long pot(long long a, long long b) {
  if (b == 0LL) return 1LL;
  long long ret = pot(a, (b >> 1));
  ret = (ret * ret) % mod;
  if (b & 1LL) ret = (ret * a) % mod;
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    ++ile[a];
  }
  for (int i = 1; i <= n; ++i) rev[i] = pot(i, mod - 2);
  dp[0][0] = 1LL;
  long long res = 0LL;
  for (int moves = 1; moves <= n; ++moves) {
    long long suma = 0LL;
    for (int j = 0; j <= n; ++j) {
      long long curFra = ((long long)ile[j] * rev[n - moves + 1]) % mod;
      dp[moves][j] = (suma * curFra) % mod;
      if (ile[j] > 1) {
        long long resFra = ((long long)(ile[j] - 1) * rev[n - moves]);
        res += dp[moves][j] * resFra;
        res %= mod;
      }
      suma += dp[moves - 1][j];
      suma %= mod;
    }
  }
  printf("%lld", res);
}
