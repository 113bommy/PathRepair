#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e3 + 1;
int a[N], dp[N][N], nxt[N], prv[N], lst[N];
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i], --a[i];
    }
    memset(lst, -1, n * sizeof *lst);
    n = unique(a, a + n) - a;
    memset(prv, -1, n * sizeof *prv);
    memset(nxt, 127, n * sizeof *nxt);
    for (int i = 0; i < n; ++i) {
      if (lst[a[i]] != -1) {
        prv[i] = lst[a[i]];
        nxt[lst[a[i]]] = i;
      }
      lst[a[i]] = i;
    }
    for (int le = 2; le <= n; ++le)
      for (int i = 0; i + le <= n; ++i) {
        int j = i + le - 1;
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        if (nxt[i] - i > j - prv[j]) {
          for (int z = nxt[i]; z <= j; z = nxt[z]) {
            dp[i][j] = max(dp[i][j], dp[i + 1][z - 1] + dp[z][j] + 1);
          }
        } else {
          for (int z = prv[j]; z >= i; z = prv[z]) {
            dp[i][j] = min(dp[i][j], dp[i][z] + dp[z + 1][j - 1] + 1);
          }
        }
      }
    cout << n - dp[0][n - 1] - 1 << '\n';
  }
  return 0;
}
