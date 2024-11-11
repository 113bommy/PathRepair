#include <bits/stdc++.h>
using namespace std;
const long long MXN = 1e5 + 10;
const long long Mod = 1e9 + 7;
const long long SQR = 450;
long long power(long long a, long long b) {
  return (!b ? 1 : power(a * a % Mod, b / 2) * (b & 1LL ? a : 1) % Mod);
}
long long inv(long long x) { return power(x, Mod - 2); }
void mkay(int &x) {
  if (x >= Mod) x -= Mod;
}
long long q, k, ts, last;
long long pw[MXN], F[MXN], I[MXN];
int dp[SQR][MXN];
string s;
map<long long, long long> mp;
long long nCr(long long n, long long r) {
  if (r < 0 || r > n) return 0;
  return F[n] * I[r] % Mod * I[n - r] % Mod;
}
void solve() {
  for (int n = k; n < MXN; n++) {
    dp[ts][n] = 26ll * dp[ts][n - 1] % Mod;
    dp[ts][n] += nCr(n - 1, k - 1) * pw[n - k] % Mod;
    mkay(dp[ts][n]);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pw[0] = F[0] = I[0] = 1;
  for (int i = 1; i < MXN; i++) pw[i] = pw[i - 1] * 25 % Mod;
  for (int i = 1; i < MXN; i++) F[i] = F[i - 1] * i % Mod;
  I[MXN - 1] = inv(F[MXN - 1]);
  for (int i = MXN - 2; i; i--) I[i] = I[i + 1] * (i + 1) % Mod;
  cin >> q >> s, k = s.size();
  solve(), mp[k] = last = ts, ts++;
  while (q--) {
    long long t;
    cin >> t;
    if (t == 1) {
      cin >> s, k = s.size();
      if (mp.find(k) == mp.end()) {
        mp[k] = last = ts;
        solve(), ts++;
      } else
        last = mp[k];
    } else {
      long long n;
      cin >> n;
      cout << dp[last][n] << '\n';
    }
  }
  return 0;
}
