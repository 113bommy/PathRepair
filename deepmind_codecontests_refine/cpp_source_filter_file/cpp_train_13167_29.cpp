#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, nxt, id;
  long long w;
} a[300000 * 2 + 5];
int ecnt, pre[300000 + 5], res[300000 + 5];
int n, m, S;
long long dist[1 + 1][300000 + 5], val[300000 + 5];
void add(int u, int v, long long w, int id) {
  a[++ecnt].to = v;
  a[ecnt].nxt = pre[u];
  a[ecnt].id = id;
  a[ecnt].w = w;
  pre[u] = ecnt;
}
void Dij(int s, int kdf) {
  for (int i = 1; i <= n; i++)
    dist[kdf][i] = 1000000000000000000, val[i] = 1000000000000000000;
  dist[kdf][s] = 0;
  val[s] = 0;
  priority_queue<pair<long long, int> > Q;
  Q.push(make_pair(0, s));
  while (!Q.empty()) {
    int x = Q.top().second;
    long long di = -Q.top().first;
    Q.pop();
    if (di != dist[kdf][x]) continue;
    for (int i = pre[x]; i != -1; i = a[i].nxt) {
      int xnt = a[i].to;
      if (dist[kdf][x] + a[i].w < dist[kdf][xnt]) {
        dist[kdf][xnt] = dist[kdf][x] + a[i].w;
        Q.push(make_pair(-dist[kdf][xnt], xnt));
        val[xnt] = a[i].w;
        res[xnt] = a[i].id;
      } else if (dist[kdf][x] + a[i].w == dist[kdf][xnt] && a[i].w < val[xnt]) {
        val[xnt] = a[i].w;
        res[xnt] = a[i].id;
      }
    }
  }
}
int main() {
  memset(pre, -1, sizeof(pre));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    long long w;
    scanf("%d%d%lld", &u, &v, &w);
    add(u, v, w, i);
    add(v, u, w, i);
  }
  scanf("%d", &S);
  Dij(S, 0);
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += val[i];
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    if (i != S) printf("%d ", res[i]);
}
