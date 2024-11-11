#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, dp[18][N], st, depth[N], in[N], out[N], last = 1, v[2 * N], root[N], at,
                                               bef, bada, badb, rem, k;
vector<int> g[N];
struct node {
  int sum, l, r;
  node(int a = 0, int b = 0, int c = 0) {
    sum = a;
    l = b;
    r = c;
  }
} seg[20 * N];
void dfs(int u, int p) {
  dp[0][u] = p;
  v[last] = u;
  in[u] = ++last;
  for (auto i : g[u])
    if (i != p) depth[i] = depth[u] + 1, dfs(i, u);
  v[last] = u;
  out[u] = ++last;
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = 17; i + 1; i--)
    if (depth[u] - (1 << i) >= depth[v]) u = dp[i][u];
  if (u == v) return u;
  for (int i = 17; i + 1; i--)
    if (dp[i][u] != dp[i][v]) u = dp[i][u], v = dp[i][v];
  return dp[0][u];
}
int build(int c, int l, int r) {
  if ((l > in[at] || r < in[at]) && (l > out[at] || r < out[at])) return c;
  int temp = ++rem;
  if (l == r) {
    seg[temp].sum = l == in[at] ? 1 : -1;
    return temp;
  }
  seg[temp].l = build(seg[c].l, l, (l + r) / 2);
  seg[temp].r = build(seg[c].r, (l + r) / 2 + 1, r);
  seg[temp].sum = seg[seg[temp].l].sum + seg[seg[temp].r].sum;
  return temp;
}
int get(int a, int b, int l, int r, int s, int e) {
  if (l > e || r < s) return 0;
  if (l >= s && r <= e) return seg[a].sum - seg[b].sum;
  return get(seg[a].l, seg[b].l, l, (l + r) / 2, s, e) +
         get(seg[a].r, seg[b].r, (l + r) / 2 + 1, r, s, e);
}
int getgood(int a, int b) {
  return depth[b] - depth[a] + 1 -
         get(root[at], root[bef], 1, last, in[a], in[b]);
}
int getkth(int a, int b) {
  for (int i = 17; i + 1; i--)
    if (depth[b] - (1 << i) >= depth[a] && getgood(a, dp[i][b]) > k)
      b = dp[i][b];
  if (dp[0][b] != -1 && depth[a] <= depth[dp[0][b]] &&
      getgood(a, dp[0][b]) >= k)
    b = dp[0][b];
  return b;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, a; i <= n; i++) {
    scanf("%d", &a);
    if (a)
      g[a].push_back(i);
    else
      st = i;
  }
  dfs(st, -1);
  for (int i = 1; i < 18; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = dp[i - 1][j] == -1 ? -1 : dp[i - 1][dp[i - 1][j]];
  scanf("%d", &n);
  int q[N] = {}, size = 0;
  for (int i = 1, a, b, y, t; i <= n; i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d", &at);
      root[i] = build(root[q[size]], 1, last);
      q[++size] = i;
    } else {
      scanf("%d%d%d%d", &a, &b, &k, &y);
      q[size] = q[size++];
      int c = lca(a, b);
      at = q[size];
      bef = q[y];
      bada = getgood(a, a);
      badb = getgood(b, b);
      int first = getgood(c, a);
      int second = getgood(c, b);
      int lcagood = getgood(c, c);
      k += bada;
      if (first + second - lcagood < k)
        puts("-1");
      else {
        int ans;
        if (first >= k) {
          k = first - k + 1;
          ans = getkth(c, a);
        } else {
          k += lcagood - first;
          ans = getkth(c, b);
        }
        printf("%d\n", ans == a || ans == b ? -1 : ans);
      }
    }
  }
}
