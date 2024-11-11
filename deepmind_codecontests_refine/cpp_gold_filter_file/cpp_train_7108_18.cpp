#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 5005;
long long dp[maxn], fac[maxn], ifac[maxn];
int pos[maxn], arr[maxn];
long long ksm(long long a, long long b) {
  long long ret = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ret = ret * a % mod;
  return ret;
}
void init(int n) {
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  ifac[n] = ksm(fac[n], mod - 2);
  for (int i = n; i; i--) ifac[i - 1] = i * ifac[i] % mod;
}
long long P(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return fac[a] * ifac[a - b] % mod;
}
void solve() {
  int n;
  cin >> n;
  init(n);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  sort(arr + 1, arr + 1 + n);
  dp[0] = 1, pos[0] = -1;
  int ptr = 1;
  for (int i = 1; i <= n; i++) {
    while (arr[ptr] * 2 <= arr[i]) ptr++;
    pos[i] = ptr - 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= pos[i]; j++)
      dp[i] = (dp[i] + dp[j] * P(n - 2 - pos[j], pos[i] - pos[j] - 1)) % mod;
  cout << (pos[n] == n - 1 ? dp[n] : 0) << '\n';
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
