#include <bits/stdc++.h>
const int INF = 0x1f1f1f1f;
int n, m, c, k, s[210], sz, first[610], next[300000], tail[300000], len[300000],
    h, heap[610], idx[610], dist[610][610], ss, vis[1000], from[1000];
void addedge(int u, int v, int l);
int hungary();
int match(int u);
void dijkstra();
void push(int k);
int pop();
void up(int u);
void down(int u);
void swap(int u, int v);
int main() {
  scanf("%d%d%d%d", &n, &m, &c, &k);
  int i, j;
  for (i = 1; i <= c; i++) scanf("%d", &s[i]);
  memset(first, 0, sizeof(first));
  int u, v, l;
  for (sz = 0, i = 1; i <= m; i++) {
    scanf("%d%d%d", &u, &v, &l);
    addedge(u, v, l);
    addedge(v, u, l);
  }
  for (i = 1; i <= c; i++) {
    ss = s[i];
    dijkstra();
  }
  int mint = 0, maxt = INF, mid;
  while (mint < maxt) {
    mid = (mint + maxt) / 2;
    memset(first, 0, sizeof(first));
    for (sz = 0, i = 1; i <= c; i++)
      for (j = 1; j <= n; j++)
        if (dist[s[i]][j] <= mid) addedge(i, j, 0);
    if (hungary() >= k)
      maxt = mid;
    else
      mint = mid + 1;
  }
  if (mint < INF)
    printf("%d\n", mint);
  else
    printf("-1\n");
  return 0;
}
void addedge(int u, int v, int l) {
  sz++;
  tail[sz] = v;
  len[sz] = l;
  next[sz] = first[u];
  first[u] = sz;
}
int hungary() {
  int ret = 0, i;
  memset(from, 0, sizeof(from));
  for (i = 1; i <= c; i++) {
    memset(vis, 0, sizeof(vis));
    if (match(i)) ret++;
  }
  return ret;
}
int match(int u) {
  int v, e;
  for (e = first[u]; e; e = next[e]) {
    v = tail[e];
    if (vis[v]) continue;
    vis[v] = 1;
    if (!from[v] || match(from[v])) {
      from[v] = u;
      return 1;
    }
  }
  return 0;
}
void dijkstra() {
  memset(dist[ss], 0x1f, sizeof(dist[ss]));
  dist[ss][ss] = 0;
  int i, u, v, e;
  for (h = 0, i = 1; i <= n; i++) push(i);
  while (h) {
    u = pop();
    for (e = first[u]; e; e = next[e]) {
      v = tail[e];
      if (dist[ss][u] + len[e] < dist[ss][v]) {
        dist[ss][v] = dist[ss][u] + len[e];
        up(idx[v]);
      }
    }
  }
}
void push(int k) {
  h++;
  heap[h] = k;
  idx[k] = h;
  up(h);
}
int pop() {
  int res = heap[1];
  heap[1] = heap[h--];
  down(1);
  return res;
}
void up(int u) {
  if (u > 1 && dist[ss][heap[u]] > dist[ss][heap[u / 2]]) {
    swap(u, u / 2);
    up(u / 2);
  }
}
void down(int u) {
  if (u * 2 > h) return;
  int v = u * 2;
  if (v + 1 <= h && dist[ss][heap[v + 1]] > dist[ss][heap[v]]) v++;
  if (dist[ss][heap[v]] > dist[ss][heap[u]]) {
    swap(u, v);
    down(v);
  }
}
void swap(int u, int v) {
  int t1, t2;
  t1 = heap[u];
  t2 = heap[v];
  heap[u] = t2;
  heap[v] = t1;
  idx[t1] = v;
  idx[t2] = u;
}
