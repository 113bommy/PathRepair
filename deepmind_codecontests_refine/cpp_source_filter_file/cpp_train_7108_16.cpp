#include <bits/stdc++.h>
using namespace std;
const int N = 5005, lg = 30, mod = 998244353;
int n, a[N], dp[N][lg];
long long ans;
void p(int x, int y) {
  if (dp[x][y] == 0 || 1) return;
  cout << x << " " << y << " : " << dp[x][y] << endl;
}
void read() {
  cin >> n;
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  a[0] = 2e9;
}
void solve() {
  dp[0][0] = 1;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < i; j++)
      for (int k = 0; k < lg; k++) {
        if (a[i] * 2 <= a[j]) dp[i][k + 1] = (dp[i][k + 1] + dp[j][k]) % mod;
        dp[j][k] = 1ll * dp[j][k] * (i - 2 + (a[i] * 2 <= a[j])) % mod;
        p(j, k);
      }
    for (int k = 0; k < lg; k++) p(i, k);
  }
  for (int i = 0; i < n + 1; i++)
    for (int k = 0; k < lg; k++) ans = (ans + dp[i][k]) % mod;
  cout << ans;
}
int main() {
  read();
  solve();
}
