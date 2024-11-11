#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct red {
  int l, r, d, w, id;
  bool operator<(const red &a) const {
    if (w != a.w) return w < a.w;
    return d < a.d;
  }
} R[N];
struct line {
  int x, op, id;
} op[N * 3];
int go[N];
int64_t dp[2][N][2];
int nex[N];
int main() {
  int T = 1;
  while (T--) {
    int n, m, k, tot = 0;
    int ks;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
      int l, r, d, w;
      cin >> l >> r >> d >> w;
      R[i] = {l, r, d, w, i};
      op[++tot] = {l, 1, i};
      op[++tot] = {r + 1, -1, i};
    }
    sort(op + 1, op + tot + 1,
         [](const line &a, const line &b) { return a.x < b.x; });
    multiset<red> se;
    memset(go, 0, sizeof go);
    memset(nex, 0, sizeof nex);
    for (int i = 1, p = 1; i <= n; ++i) {
      while (p <= tot && op[p].x == i) {
        if (op[p].op == 1) {
          se.insert(R[op[p].id]);
        } else {
          se.erase(se.lower_bound(R[op[p].id]));
        }
        p++;
      }
      if (se.size()) go[i] = se.rbegin()->id;
    }
    for (int i = 1; i <= n; ++i) {
      if (!go[i]) continue;
      int p = i + 1;
      while (p <= n && go[p] == 0) p++;
      for (int j = i; j <= p; ++j) nex[j] = p;
      i = p - 1;
    }
    for (int i = 1; i <= n; ++i)
      if (go[i]) nex[i] = i;
    int pos = 1;
    while (pos <= n && go[pos] == 0) pos++;
    memset(dp, 0x7f, sizeof(dp));
    int rt = 0;
    int64_t ans = 1e18;
    for (int j = 0; j <= m; ++j) {
      rt ^= 1;
      memset(dp[rt], 0x7f7f7f7f7f7f7f7f, sizeof dp[rt]);
      if (j == 1) dp[rt][pos][1] = 0;
      if (j == 0) dp[rt][pos][0] = R[go[pos]].w;
      for (int i = pos; i <= n; ++i) {
        if (go[i]) {
          int p = nex[R[go[i]].d + 1];
          dp[rt][p][0] = min(dp[rt][p][0], dp[rt][i][0] + R[go[p]].w);
          if (j >= 1) dp[rt][p][1] = min(dp[rt][p][1], dp[rt ^ 1][i][0]);
          p = nex[i + 1];
          dp[rt][p][0] = min(dp[rt][p][0], dp[rt][i][1] + R[go[p]].w);
          if (j >= 1) dp[rt][p][1] = min(dp[rt][p][1], dp[rt ^ 1][i][1]);
        }
      }
      ans = min(ans, min(dp[rt][n + 1][0], dp[rt][n + 1][1]));
    }
    cout << ans << '\n';
  }
  return 0;
}
