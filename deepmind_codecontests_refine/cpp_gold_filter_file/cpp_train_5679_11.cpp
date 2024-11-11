#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 2e5 + 10, inf = 0x3f3f3f3f;
struct rec {
  int l, r, s, t, id;
  friend inline bool operator<(const rec &a, const rec &b) { return a.l > b.l; }
} q[M];
int u[M], v[M], dp[N][N], n, m, Q, cnt = 1, ans[M];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> Q;
  for (int i = 1; i <= m; i++) cin >> u[i] >> v[i];
  for (int i = 1; i <= Q; i++) {
    cin >> q[i].l >> q[i].r >> q[i].s >> q[i].t;
    q[i].id = i;
  }
  sort(q + 1, q + Q + 1);
  memset(dp, inf, sizeof dp);
  for (int i = 1; i <= n; i++) dp[i][i] = 0;
  for (int i = m; i >= 1; i--) {
    dp[u[i]][v[i]] = dp[v[i]][u[i]] = i;
    for (int j = 1; j <= n; j++) {
      if (j != u[i]) dp[v[i]][j] = min(dp[v[i]][j], dp[u[i]][j]);
      if (j != v[i]) dp[u[i]][j] = min(dp[u[i]][j], dp[v[i]][j]);
    }
    for (; cnt <= Q && q[cnt].l >= i; cnt++)
      ans[q[cnt].id] = dp[q[cnt].s][q[cnt].t] <= q[cnt].r;
  }
  for (int i = 1; i <= Q; i++)
    if (ans[i])
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  return 0;
}
