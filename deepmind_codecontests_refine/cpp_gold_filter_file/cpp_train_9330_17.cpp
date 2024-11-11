#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
int n, k;
long long dp[N], s[N], g[N], rev[N];
void Enter() { cin >> n >> k; }
inline void Add(long long &a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
long long Power(long long a, long long b) {
  long long res = 1;
  for (long long d = a; b; d = d * d % MOD, b /= 2)
    if (b & 1) res = res * d % MOD;
  return res;
}
long long AA(int i, int t) { return g[t] / g[t - i]; }
void Process() {
  g[0] = rev[0] = 1;
  for (int i = (1), _b = (n); i <= _b; ++i) g[i] = g[i - 1] * i % MOD;
  for (int i = (1), _b = (n); i <= _b; ++i) rev[i] = Power(g[i], MOD - 2);
  if (k >= n) {
    cout << 0 << '\n';
    return;
  }
  dp[k + 1] = g[k];
  s[k + 1] = dp[k + 1] * rev[k + 1] % MOD;
  for (int i = (k + 2), _b = (n - 1); i <= _b; ++i) {
    Add(dp[i], (i - k) * g[i - 1] % MOD);
    Add(dp[i], (s[i - 1] - s[i - k - 1] + MOD) * g[i - 1] % MOD);
    s[i] = (s[i - 1] + dp[i] * rev[i]) % MOD;
  }
  long long res = 0;
  res = s[n - 1] * g[n - 1] % MOD;
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Enter();
  Process();
  return 0;
}
