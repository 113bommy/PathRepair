#include <bits/stdc++.h>
using namespace std;
const int B = 11;
const int maxn = 3003;
const int mod = 998244353;
int n, m, K;
int a[maxn], P[maxn], Inv[maxn];
int dp[maxn][maxn];
int f[maxn], cnt[maxn];
int g[maxn][1 << B | 1];
inline int Pow(int a, int n) {
  int ans = 1;
  for (; n; n >>= 1, a = a * 1ll * a % mod)
    if (n & 1) ans = ans * 1ll * a % mod;
  return ans;
}
inline void Run_1() {
  int Lim = (1 << m) - 1;
  g[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = K; j >= 0; j--) {
      dp[j + 1][i] = g[j][Lim ^ (1 << a[i] - 1)];
      for (int S = Lim - 1; S >= 0; S--) {
        if ((S | (1 << a[i] - 1)) == Lim)
          (g[j + 1][0] += g[j][S]) %= mod;
        else
          (g[j][S | (1 << a[i] - 1)] += g[j][S]) %= mod;
      }
    }
  }
}
int num[maxn][maxn];
inline void Run_2() {
  dp[0][0] = 1;
  for (int r = 1; r <= n; r++) {
    memset(cnt, 0, sizeof(int) * (m + 3));
    ++cnt[a[r]];
    int Bas = 1, C = 1;
    for (int l = r - 1; l >= 0; l--) {
      if (C == m) num[l + 1][r] = Bas;
      if (a[l] != a[r]) {
        C += (!cnt[a[l]]);
        Bas =
            Bas * 1ll * Inv[cnt[a[l]]] % mod * (P[++cnt[a[l]]] - 1 + mod) % mod;
      }
    }
  }
  static unsigned long long Inf = 17e18;
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= n; j++) {
      int Bas = 1, C = 1;
      unsigned long long tmp = 0;
      for (int k = j - 1; k >= 0; k--)
        if (dp[i - 1][k] && num[k + 1][j]) {
          tmp += dp[i - 1][k] * 1ll * num[k + 1][j];
          if (tmp > Inf) tmp %= mod;
        }
      dp[i][j] = tmp % mod;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  K = n / m;
  P[0] = Inv[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]), P[i] = P[i - 1] * 2 % mod;
    Inv[i] = Pow(P[i] - 1 + mod, mod - 2);
  }
  if (m <= B)
    Run_1();
  else
    Run_2();
  for (int i = 1; i <= K; i++)
    for (int j = 1; j <= n; j++)
      (f[i] += dp[i][j] * 1ll * P[n - j] % mod) %= mod;
  f[0] = (P[n] - 1 + mod) % mod;
  for (int i = 0; i <= n; i++) printf("%d ", (f[i] - f[i + 1] + mod) % mod);
  return 0;
}
