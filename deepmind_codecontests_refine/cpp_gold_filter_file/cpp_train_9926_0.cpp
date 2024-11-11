#include <bits/stdc++.h>
using namespace std;
long long n, m, x, zs[100100], dis[100100], disf[100100], cnt, zz[100100], cntt,
    ans = 2e9, dis1[100100];
struct b {
  long long to, cost;
} a;
struct c {
  long long from;
  b tr;
} nw[400100];
vector<b> p[100100];
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    v;
bool vis[100100], szs[100100];
long long find(long long x) {
  if (zz[x] == x) {
    return x;
  } else
    return zz[x] = find(zz[x]);
}
void hb(long long x, long long y) {
  long long zx = find(x), zy = find(y);
  zz[zx] = zy;
  return;
}
void dij1() {
  for (long long i = 1; i <= n; i++) {
    dis1[i] = 1e14;
  }
  dis1[1] = 0;
  vis[1] = true;
  v.push(make_pair(0, 1));
  while (!v.empty()) {
    long long now = v.top().second;
    v.pop();
    vis[now] = false;
    for (long long i = 0; i < p[now].size(); i++) {
      long long tto = p[now][i].to, ccs = p[now][i].cost;
      if (dis1[now] + ccs < dis1[tto]) {
        dis1[tto] = dis1[now] + ccs;
        if (!vis[tto]) {
          vis[tto] = true;
          v.push(make_pair(dis1[tto], tto));
        }
      }
    }
  }
}
void dij() {
  for (long long i = 1; i <= n; i++) {
    dis[i] = 1e14;
  }
  memset(vis, false, sizeof(vis));
  scanf("%lld", &m);
  for (long long i = 1; i <= m; i++) {
    scanf("%lld", &zs[i]);
    ans = min(ans, dis1[zs[i]]);
    szs[zs[i]] = true;
    dis[zs[i]] = 0;
    disf[zs[i]] = zs[i];
    v.push(make_pair(0, zs[i]));
    vis[zs[i]] = true;
  }
  while (!v.empty()) {
    long long now = v.top().second;
    v.pop();
    vis[now] = false;
    for (long long i = 0; i < p[now].size(); i++) {
      long long tto = p[now][i].to, ccs = p[now][i].cost;
      if (dis[now] + ccs < dis[tto]) {
        dis[tto] = dis[now] + ccs;
        disf[tto] = disf[now];
        if (!vis[tto]) {
          vis[tto] = true;
          v.push(make_pair(dis[tto], tto));
        }
      }
    }
  }
}
bool cmp(c x, c y) { return x.tr.cost < y.tr.cost; }
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= m; i++) {
    scanf("%lld%lld%lld", &x, &a.to, &a.cost);
    p[x].push_back(a);
    swap(x, a.to);
    p[x].push_back(a);
  }
  dij1();
  dij();
  for (long long i = 1; i <= n; i++) {
    zz[i] = i;
    for (long long j = 0; j < p[i].size(); j++) {
      if (dis[i] != 1e14 && dis[p[i][j].to] != 1e14) {
        p[i][j].cost += dis[i] + dis[p[i][j].to];
        p[i][j].to = disf[p[i][j].to];
        nw[++cnt].tr = p[i][j];
        nw[cnt].from = disf[i];
      }
    }
  }
  sort(nw + 1, nw + cnt + 1, cmp);
  cntt = m;
  for (long long i = 1; i <= cnt; i++) {
    if (find(nw[i].from) != find(nw[i].tr.to)) {
      hb(nw[i].from, nw[i].tr.to);
      ans += nw[i].tr.cost;
      cntt--;
      if (cntt == 1) {
        break;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
