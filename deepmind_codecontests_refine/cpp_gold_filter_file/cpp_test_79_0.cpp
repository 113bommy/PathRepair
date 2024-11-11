#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
vector<pair<int, int> > g[maxn << 2];
int id[maxn << 2];
int le[maxn << 2];
int be[maxn * 4];
void build(int rt, int l, int r) {
  if (l == r) {
    id[l] = rt;
    le[rt] = 1;
    be[rt] = l;
    return;
  }
  build(rt << 1, l, ((l + r) >> 1));
  build(rt << 1 | 1, ((l + r) >> 1) + 1, r);
  g[rt].push_back(pair<int, int>(rt << 1, 0));
  g[rt].push_back(pair<int, int>(rt << 1 | 1, 0));
  return;
}
void add(int rt, int l, int r, int L, int R, int u) {
  if (L <= l && r <= R) {
    g[u].push_back(pair<int, int>(rt, 1));
    return;
  }
  if (L <= ((l + r) >> 1)) add(rt << 1, l, ((l + r) >> 1), L, R, u);
  if (R > ((l + r) >> 1)) add(rt << 1 | 1, ((l + r) >> 1) + 1, r, L, R, u);
  return;
}
int n;
int a[maxn], b[maxn];
int dis[maxn << 4], pre[maxn << 4];
int q[maxn * 40], head = 0, tail = 0;
int vis[maxn << 4];
const int inf = 0x3f3f3f3f;
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n + 1; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n + 1; ++i) scanf("%d", &b[i]);
  build(1, 0, n);
  int tot = 0;
  for (int i = 0; i <= n; ++i) tot = max(tot, id[i]);
  for (int i = 1; i <= n; ++i) {
    int l = i - a[i], r = i - 1;
    if (l <= r) add(1, 0, n, l, r, tot + i);
    g[id[i]].push_back(pair<int, int>(tot + i + b[i], 0));
    be[tot + i] = i;
  }
  memset(dis, 0x3f, sizeof dis);
  head = tail = maxn * 20;
  q[tail++] = id[n];
  dis[id[n]] = 0;
  while (head < tail) {
    int u = q[head++];
    if (vis[u]) continue;
    vis[u] = 1;
    for (pair<int, int> p : g[u]) {
      int v, w;
      tie(v, w) = p;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (w)
          q[tail++] = v;
        else
          q[--head] = v;
        pre[v] = u;
      }
    }
  }
  if (dis[id[0]] == inf) {
    puts("-1");
  } else {
    vector<int> ans;
    int cur = id[0];
    ans.push_back(0);
    while (cur != id[n]) {
      int nxt = pre[cur];
      if (le[nxt]) {
        ans.push_back(be[nxt]);
      }
      cur = nxt;
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int x : ans) printf("%d ", x);
  }
  return 0;
}
