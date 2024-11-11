#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 20, mod = 998244353;
int n, a[N], dp[N][N], sm[N][N];
inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) dp[i][1] = 1;
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    while (ptr < n && a[ptr] * 2 <= a[i]) ptr++;
    for (int j = 1; j <= ptr + 1; j++) {
      add(sm[i][j], sm[i - 1][j]);
      add(dp[i][j], sm[i][j]);
      if (j <= ptr) {
        dp[i][j + 1] = (dp[i][j + 1] + 1ll * dp[i][j] * (ptr + 1 - j)) % mod;
      }
      if (i < n) {
        int p = lower_bound(a, a + n, 2 * a[i]) - a;
        if (p < n) add(sm[p][j + 1], dp[i][j]);
      }
    }
  }
  cout << dp[n - 1][n] << '\n';
}
