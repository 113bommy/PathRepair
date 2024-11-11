#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[100005];
int u[100005], v[100005], w[100005];
long long dis[100005];
bool f[100005];
int st[100005];
struct graph {
  int tot;
  int hd[100005];
  int nxt[200005], to[200005], dt[200005];
  void add(int uu, int vv, int ww) {
    nxt[++tot] = hd[uu];
    hd[uu] = tot;
    to[tot] = vv;
    dt[tot] = ww;
    return;
  }
} g;
struct node {
  int ss, num;
  long long val;
  friend bool operator<(node x, node y) { return x.val > y.val; }
};
priority_queue<node> q;
int cnt;
struct side {
  int uu, vv;
  long long ww;
} a[200005];
bool cmp(side x, side y) { return x.ww < y.ww; }
struct bin {
  int fa[200005];
  bin() {
    for (int i = 0; i < 200005; i++) fa[i] = i;
    return;
  }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
} b;
long long ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
    g.add(u[i], v[i], w[i]);
    g.add(v[i], u[i], w[i]);
  }
  memset(v, 0x3f, sizeof(v));
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &c[i]);
    q.push((node){c[i], c[i], 0});
    dis[c[i]] = 0;
  }
  while (!q.empty()) {
    node now = q.top();
    q.pop();
    if (f[now.num] == true) continue;
    f[now.num] = true;
    st[now.num] = now.ss;
    for (int i = g.hd[now.num]; i; i = g.nxt[i])
      if (dis[g.to[i]] > dis[now.num] + g.dt[i]) {
        dis[g.to[i]] = dis[now.num] + g.dt[i];
        q.push((node){now.ss, g.to[i], dis[g.to[i]]});
      }
  }
  for (int i = 1; i <= n; i++)
    for (int j = g.hd[i]; j; j = g.nxt[j])
      a[++cnt] = (side){st[i], st[g.to[j]], dis[i] + g.dt[j] + dis[g.to[j]]};
  sort(a + 1, a + cnt + 1, cmp);
  for (int i = 1; i <= cnt; i++)
    if (b.find(a[i].uu) != b.find(a[i].vv)) {
      ans += a[i].ww;
      b.fa[b.find(a[i].uu)] = b.find(a[i].vv);
    }
  printf("%lld\n", ans + dis[1]);
  return 0;
}
