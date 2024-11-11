#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const int MQ = 333, MN = 1e5 + MQ, MOD = 1e9 + 7;
int dp[MQ][MN], fact[MN], lfact[MN];
int n, m, x;
void ok(int &x) {
  if (x >= MOD) x -= MOD;
}
int f(int a, int b) { return a * m + b; }
int bpw(int a, int b) {
  if (b == 0) return 1;
  int t = bpw(a, b / 2);
  t = 1ll * t * t % MOD;
  if (b & 1) return 1ll * a * t % MOD;
  return t;
}
int C(int a, int b) {
  if (b > a) return 0;
  return 1ll * fact[a] * lfact[a - b] % MOD * lfact[b] % MOD;
}
void prep() {
  fact[0] = 1;
  for (int i = 1; i < MN; ++i) fact[i] = 1ll * fact[i - 1] * i % MOD;
  for (int i = 0; i < MN; ++i) lfact[i] = bpw(fact[i], MOD - 2);
  dp[0][f(0, 0)] = 1;
  for (int i = 1; i <= m; ++i) {
    dp[0][f(0, i)] = 1;
    for (int j = 1; j <= n && j <= i; ++j)
      for (int l = 0; l <= j; ++l) {
        if (l == 0) {
          dp[j][f(l, i)] = dp[j][f(1, i - 1)] + dp[j][f(0, i - 1)];
          ok(dp[j][f(l, i)]);
          continue;
        }
        dp[j][f(l, i)] =
            (l ? dp[j - 1][f(l - 1, i - 1)] : 0) + dp[j - 1][f(l, i - 1)];
        ok(dp[j][f(l, i)]);
        dp[j][f(l, i)] += dp[j][f(l + 1, i - 1)];
        ok(dp[j][f(l, i)]);
        dp[j][f(l, i)] += dp[j][f(l, i - 1)];
        ok(dp[j][f(l, i)]);
      }
  }
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> x;
  if (n > m) return cout << 0 << '\n', 0;
  prep();
  int ans = 0;
  for (int E = x; E <= m; ++E)
    for (int A = 0; A < n; ++A)
      if (A <= x - 1 && n - 1 - A <= m - E) {
        int B = n - 1 - A;
        int vA = 0, vB = 0;
        for (int a = 0; a <= A && a <= E - x + 1; ++a) {
          vA += 1ll * dp[A][f(a, x - 1)] * C(E - x + 1, a) % MOD, ok(vA);
        }
        for (int b = 0; b <= B && b <= E - x + 1; ++b) {
          vB += 1ll * dp[B][f(b, m - E)] * C(E - x + 1, b) % MOD, ok(vB);
        }
        ans += 1ll * vA * vB % MOD;
        ok(ans);
      }
  cout << 1ll * ans * fact[n] % MOD << '\n';
  return 0;
}
