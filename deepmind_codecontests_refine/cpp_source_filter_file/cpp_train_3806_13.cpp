#include <bits/stdc++.h>
using namespace std;
int lst[1005], to[20005], pre[20005], w[20005], idx[20005], tot;
int u[10005], v[10005], pre_e[1005], pre_v[1005];
long long dis[1005], ow[10005];
inline void add_edge(int u, int v, int _w, int _idx) {
  to[tot] = v;
  pre[tot] = lst[u];
  w[tot] = _w;
  idx[tot] = _idx;
  lst[u] = tot++;
}
void dij(int s, bool f = false) {
  priority_queue<pair<long long, int> > que;
  que.push(make_pair(s, 0));
  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  while (!que.empty()) {
    long long d = -que.top().first;
    int u = que.top().second;
    que.pop();
    if (d != dis[u]) continue;
    for (int i = lst[u]; ~i; i = pre[i]) {
      if (!w[i] && !f) continue;
      if (dis[to[i]] > dis[u] + ((w[i]) < 0 ? -(w[i]) : (w[i]))) {
        pre_v[to[i]] = u;
        pre_e[to[i]] = i;
        dis[to[i]] = dis[u] + ((w[i]) < 0 ? -(w[i]) : (w[i]));
        que.push(make_pair(-dis[to[i]], to[i]));
      }
    }
  }
}
int main() {
  memset(lst, -1, sizeof(lst));
  int n, m, l, s, t;
  scanf("%d%d%d%d%d", &n, &m, &l, &s, &t);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%lld", u + i, v + i, ow + i);
    add_edge(u[i], v[i], ow[i], i);
    add_edge(v[i], u[i], ow[i], i);
  }
  dij(s);
  if (dis[t] == l) {
    printf("YES\n");
    for (int i = 0; i < m; i++)
      printf("%d %d %lld\n", u[i], v[i], ow[i] ? ow[i] : 1000000000000ll);
    return 0;
  }
  if (dis[t] < l) {
    printf("NO\n");
    return 0;
  }
  for (int i = 0; i < tot; i++) {
    if (!w[i]) {
      w[i] = -1;
      ow[idx[i]] = 1;
    }
  }
  while (true) {
    dij(s, true);
    if (dis[t] == l) break;
    if (dis[t] > l) {
      printf("NO\n");
      return 0;
    }
    int x = t;
    while (x != s) {
      if (-1 == w[pre_e[x]]) {
        w[pre_e[x]] -= l - dis[t];
        w[pre_e[x] ^ 1] -= l - dis[t];
        ow[idx[pre_e[x]]] += l - dis[t];
        break;
      }
      x = pre_v[x];
    }
    if (x == s) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for (int i = 0; i < m; i++)
    printf("%d %d %lld\n", u[i], v[i], ((ow[i]) < 0 ? -(ow[i]) : (ow[i])));
  return 0;
}
