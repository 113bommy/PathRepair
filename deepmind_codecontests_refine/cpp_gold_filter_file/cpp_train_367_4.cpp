#include <bits/stdc++.h>
const int MAXN = 1000, MAXD = 10;
int n, d, Mod;
int Add(int x, int y) {
  x += y;
  return x >= Mod ? x - Mod : x;
}
int Sub(int x, int y) {
  x -= y;
  return x < 0 ? x + Mod : x;
}
int Quick_pow(int x, int po) {
  int Ans = 1;
  for (; po; po >>= 1, x = 1ll * x * x % Mod)
    if (po & 1) Ans = 1ll * Ans * x % Mod;
  return Ans;
}
int Inverse(int x) { return Quick_pow(x, Mod - 2); }
int Fac[MAXN + 5], Inv[MAXN + 5];
void Init() {
  Fac[0] = 1;
  for (int i = 1; i <= MAXN; i++) Fac[i] = 1ll * Fac[i - 1] * i % Mod;
  Inv[MAXN] = Inverse(Fac[MAXN]);
  for (int i = MAXN; i >= 1; i--) Inv[i - 1] = 1ll * Inv[i] * i % Mod;
}
int C(int n, int m) {
  int Ans = 1;
  for (int i = n; i >= n - m + 1; i--) Ans = 1ll * Ans * i % Mod;
  return 1ll * Ans * Inv[m] % Mod;
}
int dp[MAXN + 5][MAXD + 1][MAXN / 2 + 5];
int dfs(int Sz, int nowd, int MaxSz) {
  if (dp[Sz][nowd][MaxSz] != -1) return dp[Sz][nowd][MaxSz];
  if (Sz == 1) return dp[Sz][nowd][MaxSz] = nowd == 0;
  if (MaxSz == 1) return dp[Sz][nowd][MaxSz] = Sz == nowd + 1;
  int Ans = 0;
  for (int t = 0; t * MaxSz < Sz && t <= nowd; t++)
    Ans = Add(Ans, 1ll * C(dfs(MaxSz, d - 1, MaxSz - 1) + t - 1, t) *
                       dfs(Sz - t * MaxSz, nowd - t, MaxSz - 1) % Mod);
  return dp[Sz][nowd][MaxSz] = Ans;
}
int main() {
  scanf("%d %d %d", &n, &d, &Mod);
  if (n == 1 || n == 2) return printf("1\n") & 0;
  Init();
  memset(dp, -1, sizeof(dp));
  if (n & 1)
    printf("%d\n", dfs(n, d, n / 2));
  else
    printf("%d\n", Sub(dfs(n, d, n / 2), C(dfs(n / 2, d - 1, n / 2 - 1), 2)));
  return 0;
}
