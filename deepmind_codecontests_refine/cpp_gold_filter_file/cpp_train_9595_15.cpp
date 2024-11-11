#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long mod = 998244353;
long long f[1009], inv[1009];
void pre() {
  f[0] = f[1] = 1;
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= (1007); ++i) {
    f[i] = f[i - 1] * i % mod;
    inv[i] = mod - (mod / i) * inv[mod % i] % mod;
  }
  for (int i = 2; i <= (1007); ++i) inv[i] = inv[i - 1] * inv[i] % mod;
}
long long C(int n, int r) {
  if (r < 0 || r > n) return 0;
  return f[n] * inv[r] % mod * inv[n - r] % mod;
}
long long dp[1009][1009];
int vis[1009][1009];
long long ans[300009];
int b[1009], nxt[1009];
int t;
long long solve(int n, int k) {
  if (k == 0) return 1;
  if (k > n) return 0;
  if (vis[n][k] == t) return dp[n][k];
  dp[n][k] = solve(n - 1, k);
  while (b[n] - b[nxt[n]] < t) nxt[n]--;
  dp[n][k] += solve(nxt[n], k - 1);
  dp[n][k] %= mod;
  vis[n][k] = t;
  return dp[n][k];
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, k;
  cin >> n >> k;
  pre();
  for (int i = 1; i <= (n); ++i) cin >> b[i];
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= (n); ++i) nxt[i] = i - 1;
  b[0] = -2e6;
  ans[0] = C(n, k);
  long long fns = 0;
  for (int i = 1; i <= (100009); ++i) {
    if (1ll * i * (k - 1) > 300009) {
      fns += 1ll * (i - 1) * (ans[i - 1] - ans[i]) % mod;
      break;
    }
    t = i;
    ans[i] = solve(n, k);
    fns += 1ll * (i - 1) * (ans[i - 1] - ans[i]) % mod;
  }
  cout << (fns % mod + mod) % mod;
  return 0;
}
