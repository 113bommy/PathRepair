#include <bits/stdc++.h>
using namespace std;
long long int mod1 = 1000000007;
long long int mod2 = 67280421310721;
long long int mod3 = 998244353;
long long int INF = 1e18;
long long int pow1(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void sieve() {
  long long int n;
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
long long int pow2(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int ncr(long long int n, long long int k) {
  long long int res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int a[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  }
  long long int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= m; i++) dp[1][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] >= a[i - 1][j])
        dp[i][j] = dp[i - 1][j] + 1;
      else
        dp[i][j] = 1;
    }
  }
  long long int best[n + 1];
  memset(best, 0, sizeof(best));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      best[i] = max(best[i], dp[i][j]);
    }
  }
  long long int q;
  cin >> q;
  while (q--) {
    long long int l, r;
    cin >> l >> r;
    if (best[r] <= (r - l))
      cout << "No\n";
    else
      cout << "Yes\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
