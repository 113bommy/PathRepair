#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
const long long mod = 998244353;
long long powm(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
long long n, k;
long long a[2005];
long long dp[2005][3005];
long long rec(long long i, long long j) {
  if (i == n) {
    if (j > 1000)
      return 1ll;
    else
      return 0ll;
  }
  if (dp[i][j] != -1) return dp[i][j];
  if (a[i] == a[(i + 1) % n]) {
    long long ans = 0;
    ans = rec(i + 1, j) * k;
    ans %= mod;
    return dp[i][j] = ans;
  } else {
    long long ans = 0;
    ans += rec(i + 1, j + 1);
    ans %= mod;
    ans += rec(i + 1, j - 1);
    ans %= mod;
    ans += (k - 2) * rec(i + 1, j);
    ans %= mod;
    return dp[i][j] = ans;
  }
}
void solve() {
  cin >> n >> k;
  for (long long i = 0; i < (n); i++) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  if (k == 1) {
    cout << 0 << endl;
  } else
    cout << rec(0, 1000) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
