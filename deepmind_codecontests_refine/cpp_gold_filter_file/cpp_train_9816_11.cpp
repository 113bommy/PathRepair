#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int n, q, m, used[20];
long long dp[MAXN], a[MAXN], f[20];
void get_perm(long long x) {
  for (int i = 1; i < 20; i++) used[i] = 0;
  for (int i = 1; i < m; i++) {
    long long ti = x / f[m - i];
    x %= f[m - i];
    int k = 1;
    while (ti > 0) {
      if (!used[k]) ti--;
      k++;
    }
    while (used[k] == 1) k++;
    a[i] = k;
    used[k] = 1;
  }
  int k = 1;
  while (used[k]) k++;
  a[m] = k;
  for (int i = 1; i <= m; i++) dp[i + n - m] = dp[i + n - m - 1] + a[i] + n - m;
}
void solve() {
  f[1] = 1;
  for (int i = 2; i <= 15; i++) f[i] = (f[i - 1] * (long long)(i));
  cin >> n >> q;
  for (int i = 1; i <= n; i++) dp[i] = dp[i - 1] + (long long)(i);
  m = min(n, 15);
  int t;
  long long sx = 0;
  while (q--) {
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      cout << dp[r] - dp[l - 1] << '\n';
    } else {
      long long x;
      cin >> x;
      sx += x;
      get_perm(sx);
    }
  }
}
int main() {
  fast_io();
  int t = 1;
  while (t--) solve();
  return 0;
}
