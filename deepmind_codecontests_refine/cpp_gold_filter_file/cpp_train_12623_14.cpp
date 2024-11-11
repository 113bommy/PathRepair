#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, Q = 600, K = 3e6 + 7;
bool fl[N];
int n, q, k, wn, sn, blk = 256, dp[N], dg[N], ans[N], c[N], l[N], r[N], p[N],
                     g[N], z[N], s[20][260][260], h[520][260][260];
vector<int> ft[N], gt[N];
struct node {
  int a, b;
} e[K];
inline void solve(int l, int r, int t) {
  if (r - l + 1 <= 4) {
    c[0] = 0, ft[t].resize(0);
    for (int i = l; i <= r; i++) c[++c[0]] = g[i];
    sort(c + 1, c + c[0] + 1);
    for (int i = 1; i <= c[0]; i++) ft[t].push_back(c[i]);
    for (int i = 1; i <= c[0]; i++)
      for (int j = i; j <= c[0]; j++) {
        if (i == j) {
          h[t][i][j] = c[i];
        } else {
          dg[0] = 0;
          for (int x = i; x <= j; x++) dg[++dg[0]] = p[c[x]];
          sort(dg + 1, dg + dg[0] + 1);
          int y = g[dg[1]];
          for (int x = 2; x <= dg[0]; x++)
            k++, e[k].a = y, e[k].b = g[dg[x]], y = k;
          h[t][i][j] = k;
        }
      }
    return;
  }
  int d = (l + r) >> 1;
  solve(l, d, t << 1), solve(d + 1, r, t << 1 | 1);
  c[0] = 0, ft[t].resize(0);
  for (int i = l; i <= r; i++) c[++c[0]] = g[i];
  sort(c + 1, c + c[0] + 1);
  for (int i = 1; i <= c[0]; i++) ft[t].push_back(c[i]);
  for (int i = 0; i < ft[t << 1].size(); i++) z[ft[t << 1][i]] = i + 1;
  for (int i = 0; i < ft[t << 1 | 1].size(); i++) z[ft[t << 1 | 1][i]] = i + 1;
  for (int i = 1; i <= c[0]; i++) {
    int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
    for (int j = i; j <= c[0]; j++) {
      if (p[c[j]] <= d) {
        if (l1 == 0 && r1 == 0)
          l1 = r1 = z[c[j]];
        else
          r1 = z[c[j]];
      } else {
        if (l2 == 0 && r2 == 0)
          l2 = r2 = z[c[j]];
        else
          r2 = z[c[j]];
      }
      if (l1 == 0 && r1 == 0)
        h[t][i][j] = h[t << 1 | 1][l2][r2];
      else if (l2 == 0 && r2 == 0)
        h[t][i][j] = h[t << 1][l1][r1];
      else
        h[t][i][j] = ++k, e[k].a = h[t << 1][l1][r1],
        e[k].b = h[t << 1 | 1][l2][r2];
    }
  }
}
int main() {
  cin >> n >> q, sn = (n - 1) / blk + 1, k = n;
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]), g[p[i]] = i;
  for (int i = 1; i <= sn; i++) {
    l[i] = r[i - 1] + 1, r[i] = min(i * blk, n), solve(l[i], r[i], 1);
    for (int j = 1; j <= r[i] - l[i] + 1; j++)
      for (int k = j; k <= r[i] - l[i] + 1; k++) s[i][j][k] = h[1][j][k];
    gt[i].resize(ft[1].size());
    for (int j = 0; j < ft[1].size(); j++) gt[i][j] = ft[1][j];
  }
  int t = 0;
  while (t < q) {
    int l, r;
    scanf("%d%d", &l, &r);
    for (int i = 1; i <= sn; i++) {
      int lt = 0, rt = gt[i].size() - 1, pa = gt[i].size() + 1, pb = -1;
      while (lt <= rt) {
        int d = (lt + rt) >> 1;
        if (gt[i][d] >= l)
          pa = d, rt = d - 1;
        else
          lt = d + 1;
      }
      lt = 0, rt = gt[i].size() - 1;
      while (lt <= rt) {
        int d = (lt + rt) >> 1;
        if (gt[i][d] <= r)
          pb = d, lt = d + 1;
        else
          rt = d - 1;
      }
      if (pa > pb)
        dp[i] = 0;
      else
        dp[i] = s[i][pa + 1][pb + 1];
    }
    int pot = 0;
    for (int i = 1; i <= sn; i++) {
      if (dp[i] == 0) continue;
      if (pot == 0)
        pot = dp[i];
      else
        k++, e[k].a = pot, e[k].b = dp[i], pot = k;
    }
    ans[t + 1] = pot, t++;
  }
  cout << k << endl;
  for (int i = n + 1; i <= k; i++) printf("%d %d\n", e[i].a, e[i].b);
  for (int i = 1; i <= q; i++) printf("%d ", ans[i]);
}
