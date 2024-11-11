#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MOD = (int)1e9 + 7;
const int N = (int)3e6;
int T;
int n, q, first;
int f[N + 5], invf[N + 5];
long long ans[N + 5][3];
int lgput(int n, int p) {
  int ans = 1, first = n;
  while (p) {
    if (p & 1) ans = 1LL * ans * first % MOD;
    first = 1LL * first * first % MOD;
    p >>= 1;
  }
  return ans;
}
void precalc() {
  f[0] = invf[0] = 1;
  for (int i = 1; i <= N; i++) f[i] = 1LL * f[i - 1] * i % MOD;
  invf[N] = lgput(f[N], MOD - 2);
  for (int i = N - 1; i >= 1; i--) invf[i] = 1LL * invf[i + 1] * (i + 1) % MOD;
}
int comb(int n, int k) {
  if (k < 0 || n < 0 || n < k) return 0;
  int ans = 1LL * f[n] * invf[k] % MOD;
  return 1LL * ans * invf[n - k] % MOD;
}
void solve() {
  cin >> n >> q;
  ans[0][0] = n + 1;
  ans[0][1] = n;
  ans[0][2] = n;
  for (int i = 1; i <= 3 * n; i++) {
    int s = (comb(3 * n + 1, i + 1) + 2LL * comb(3 * n + 1, i)) % MOD;
    ans[i][0] = (s - ans[i - 1][1] + MOD) % MOD;
    ans[i][0] = (ans[i][0] - 2LL * ans[i - 1][0] + 2LL * MOD) % MOD;
    ans[i][0] = 1LL * lgput(3, MOD - 2) * ans[i][0] % MOD;
    ans[i][1] = (ans[i][0] + ans[i - 1][0]) % MOD;
    ans[i][1] = (ans[i][1] - comb(3 * n + 1, i) + MOD) % MOD;
    ans[i][2] = (ans[i][1] + ans[i - 1][1]) % MOD;
  }
  for (; q; q--) {
    cin >> first;
    cout << ans[first][0] << "\n";
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  precalc();
  for (; T; T--) {
    solve();
  }
  return 0;
}
