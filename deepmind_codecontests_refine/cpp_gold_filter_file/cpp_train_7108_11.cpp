#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
const int N = 5e3 + 100, mod = 998244353;
int n, a[N], dp[N][N], pref[N][N], ans;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    int k = -1;
    for (int j = i - 1; j >= 0; j--) {
      if (a[j] * 2 <= a[i]) {
        k = j;
        break;
      }
    }
    dp[i][1] = 1;
    if (i) pref[i][1] = pref[i - 1][1];
    pref[i][1]++;
    if (k == -1) continue;
    for (int j = 2; j <= n; j++) {
      dp[i][j] =
          (1ll * pref[k][j - 1] + 1ll * dp[i][j - 1] * (k - j + 3)) % mod;
      pref[i][j] = (pref[i - 1][j] + dp[i][j]) % mod;
    }
  }
  cout << pref[n - 1][n];
}
