#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
long long mod = 998244353;
long long powm(long long a, long long b, long long md = mod) {
  b = b / md + b % md;
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % md;
    a = (a * a) % md;
    b = b >> 1;
  }
  return ans;
}
string s, t;
long long n, m;
long long dp[3001][3001];
long long get(long long i, long long j) {
  if (i == n) return (j == 0);
  if (j + i > n) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  if (j == 0) {
    if (i >= m) return dp[i][j] = n - i + 1;
    dp[i][j] = 0;
    if (s[i] == t[i]) dp[i][j] = get(i + 1, 0);
    return dp[i][j];
  }
  if (j == m) {
    dp[i][j] = (2 * get(i + 1, m)) % mod;
    if (t[m - 1] == s[i]) dp[i][j] = (dp[i][j] + get(i + 1, m - 1)) % mod;
    return dp[i][j];
  }
  dp[i][j] = 0;
  if (s[i] == t[j - 1]) dp[i][j] = get(i + 1, j - 1);
  if (j + i >= m || s[i] == t[j + i])
    dp[i][j] = (dp[i][j] + get(i + 1, j)) % mod;
  return dp[i][j];
}
void solve() {
  memset(dp, -1, sizeof(dp));
  cin >> s >> t;
  n = s.length();
  m = t.length();
  long long ans = get(1, m);
  for (long long i = 0; i < m; i++)
    if (s[0] == t[i]) ans += get(1, i);
  cout << (2 * ans) % mod << '\n';
}
signed main() {
  auto start = high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(15);
  long long t = 1;
  while (t--) solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "duration.count()"
       << " is " << duration.count() << '\n';
  ;
  return 0;
}
