#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
using ll = long long;
int n, m, vis[N], sum[N], b[N], ptr = 2, rt;
struct Node {
  int x, y;
} a[N];
struct Edge {
  int v, w, rnk, nxt;
  double theta;
} e[N * 2];
map<pair<int, int>, int> id;
int head[N];
vector<int> pre[N];
inline void add_edge(int uu, int vv) {
  e[ptr].v = vv;
  e[ptr].nxt = head[uu];
  head[uu] = id[{uu, vv}] = ptr++;
}
int dfs(int pos) {
  int flow = vis[pos] = 1, fl = 0;
  for (int i = head[pos]; i != -1; i = e[i].nxt)
    if (!vis[e[i].v])
      fl = dfs(e[i].v), e[i].w += fl, e[i ^ 1].w -= fl, flow += fl;
  return flow;
}
void solve() {
  int kk, ans;
  cin >> kk;
  ans = kk;
  ll tt = 0;
  for (int i = 0; i < kk; i++) cin >> b[i];
  for (int i = 0; i < kk; i++)
    tt += a[b[i]].x * ll(a[b[(i + 1) % kk]].y) -
          a[b[i]].y * ll(a[b[(i + 1) % kk]].x);
  if (tt < 0) reverse(b, b + kk);
  for (int i = 0, l, r; i < kk; i++) {
    l = e[id[{b[i], b[(i + 1) % kk]}]].rnk;
    r = e[id[{b[i], b[(i + kk - 1) % kk]}]].rnk;
    ans += pre[b[i]][r] - pre[b[i]][l - 1];
    if (l > r) ans += sum[b[i]];
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  memset(head, -1, sizeof(head));
  int t1, t2;
  for (int i = 1; i <= m; i++)
    cin >> t1 >> t2, add_edge(t1, t2), add_edge(t2, t1);
  for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  for (int i = rt = 1; i <= n; i++)
    if (a[i].x < a[rt].x) rt = i;
  dfs(rt);
  for (int i = 1; i <= n; i++) {
    pre[i].push_back(0);
    for (int j = head[i]; j != -1; j = e[j].nxt)
      pre[i].push_back(j), sum[i] += e[j].w,
          e[j].theta = atan2(a[e[j].v].y - a[i].y, a[e[j].v].x - a[i].x);
    sort(pre[i].begin(), pre[i].end(), [](int i, int j) {
      return !i ? 1 : !j ? 0 : e[i].theta < e[j].theta;
    });
    for (int j = 1; j < int(pre[i].size()); j++)
      e[pre[i][j]].rnk = j, pre[i][j] = pre[i][j - 1] + e[pre[i][j]].w;
  }
  int q;
  cin >> q;
  while (q--) solve();
  return 0;
}
