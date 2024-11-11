#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int v, id, next;
} e[200020 << 1];
int head[200020], eid = 0, father[200020], x[200020], y[200020], w[200020],
                  p[200020], _w[200020], _p[200020];
long long sum[200020];
void addedge(int u, int v, int id) {
  e[++eid].v = v;
  e[eid].id = id;
  e[eid].next = head[u];
  head[u] = eid;
}
bool dfs(int u) {
  sum[u] = 0;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v, id = e[i].id;
    if (father[u] == v) continue;
    father[v] = u;
    if (!dfs(v)) return 0;
    if (p[id] < sum[v]) return 0;
    int delta = min(p[id] - (int)sum[v], w[id] - 1);
    p[id] -= delta;
    w[id] -= delta;
    sum[u] += sum[v] + w[id];
  }
  return 1;
}
int dfs2(int u, long long strenth) {
  int ret = 0, tmp;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v, id = e[i].id;
    if (father[u] == v) continue;
    int delta = (int)min(strenth, (long long)_w[id] - w[id]);
    w[id] += delta;
    p[id] += delta;
    ret += delta;
    strenth -= delta;
    tmp = dfs2(v, min(strenth, p[id] - sum[v]));
    strenth -= tmp;
    ret += tmp;
  }
  return ret;
}
int main() {
  int n, a, b, c, d;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    addedge(a, b, i);
    addedge(b, a, i);
    x[i] = a;
    y[i] = b;
    _w[i] = w[i] = c;
    _p[i] = p[i] = d;
  }
  if (!dfs(1))
    puts("-1");
  else {
    dfs2(1, 0xfffffffffffll);
    printf("%d\n", n);
    for (int i = 1; i < n; ++i) printf("%d %d %d %d\n", x[i], y[i], w[i], p[i]);
  }
  return 0;
}
