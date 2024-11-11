#include <bits/stdc++.h>
using namespace std;
vector<int> g[300010];
int n, m, q;
vector<pair<int, int> > que[300010];
int vis[300010], l[300010];
long long ans[300010];
stack<int> second;
void dfs(int u, int fa) {
  second.push(u);
  vis[u] = 1;
  for (int v : g[u])
    if (v != fa) {
      if (!vis[v])
        dfs(v, u);
      else if (vis[v] == 1) {
        int mi = 300010, mx = 0;
        while (!second.empty()) {
          int w = second.top();
          second.pop();
          mi = min(mi, w);
          mx = max(mx, w);
          if (w == v) break;
        }
        l[mx] = mi;
      }
    }
  if (!second.empty() && second.top() == u) second.pop();
  vis[u] = 2;
}
long long sum[300010 << 2], tg[300010];
void push_up(int o) { sum[o] = sum[o << 1] + sum[o << 1 | 1]; }
void push_down(int l, int r, int o) {
  if (!tg[o]) return;
  int m = (l + r) >> 1;
  sum[o << 1] += (m - l + 1) * tg[o], sum[o << 1 | 1] += (r - m) * tg[o];
  tg[o << 1] += tg[o], tg[o << 1 | 1] += tg[o];
  tg[o] = 0;
}
void update(int l, int r, int o, int ql, int qr, int d) {
  if (ql <= l && r <= qr) {
    sum[o] += (long long)(r - l + 1) * (long long)d, tg[o] += (long long)d;
    return;
  }
  push_down(l, r, o);
  int m = (l + r) >> 1;
  if (ql <= m) update(l, m, o << 1, ql, qr, d);
  if (qr > m) update(m + 1, r, o << 1 | 1, ql, qr, d);
  push_up(o);
}
long long query(int l, int r, int o, int ql, int qr) {
  if (ql <= l && r <= qr) return sum[o];
  push_down(l, r, o);
  long long ret = 0;
  int m = (l + r) >> 1;
  if (ql <= m) ret += query(l, m, o << 1, ql, qr);
  if (qr > m) ret += query(m + 1, r, o << 1 | 1, ql, qr);
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y), g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i, 0);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, l[i]);
    l[i] = mx + 1;
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    que[r].push_back(make_pair(i, l));
  }
  for (int i = 1; i <= n; i++) {
    update(1, n, 1, l[i], i, 1);
    for (pair<int, int> v : que[i]) ans[v.first] = query(1, n, 1, v.second, i);
  }
  for (int i = 1; i <= q; i++) printf("%I64d\n", ans[i]);
  return 0;
}
