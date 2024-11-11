#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2005;
const int M = 730;
int Head[M * 10], Next[M * 100], vet[M * 100];
int a[N], b[N], d[M * 10], vis[15], p[M][5], dis[M], Dis[M], P[10], len[M],
    U[M][12], D[M][12];
int n, cnt, edgenum;
pair<int, int> c[M];
queue<int> q;
inline int F(int x, int y) { return (x - 1) * cnt + y; }
inline void addedge(int u, int v) {
  edgenum++;
  vet[edgenum] = v;
  Next[edgenum] = Head[u];
  Head[u] = edgenum;
}
int main() {
  scanf("%d", &n);
  int ans = INF;
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
  len[cnt = 1] = 0;
  for (int i = 1; i <= 9; i++) {
    len[++cnt] = 1;
    p[cnt][1] = i;
    for (int j = i; j <= 9; j++) {
      len[++cnt] = 2;
      p[cnt][1] = i, p[cnt][2] = j;
      for (int k = j; k <= 9; k++) {
        len[++cnt] = 3;
        p[cnt][1] = i, p[cnt][2] = j, p[cnt][3] = k;
        for (int t = k; t <= 9; t++)
          len[++cnt] = 4, p[cnt][1] = i, p[cnt][2] = j, p[cnt][3] = k,
          p[cnt][4] = t;
      }
    }
  }
  for (int i = 2; i <= cnt; i++) {
    memset(vis, 0, sizeof(vis));
    for (int j = 1; j <= len[i]; j++) vis[p[i][j]] = 1;
    for (int j = 1; j <= 9; j++) {
      if (!vis[j]) continue;
      int res = j, cur = 0;
      for (int k = 1; k <= len[i]; k++)
        if (p[i][k] == res)
          res = -1;
        else
          P[++cur] = p[i][k];
      for (int k = 1; k <= cnt; k++) {
        if (len[k] != cur) continue;
        bool flag = 1;
        for (int t = 1; t <= cur; t++) flag &= (P[t] == p[k][t]);
        if (flag) {
          D[i][j] = k;
          U[k][j] = i;
          break;
        }
      }
    }
  }
  memset(dis, 0x3f, sizeof(dis));
  dis[1] = a[1] - 1;
  for (int j = 1; j < 9; j++)
    for (int k = 1; k <= cnt; k++)
      addedge(F(j, k), F(j + 1, k)), addedge(F(j + 1, k), F(j, k));
  for (int j = 1; j <= 9; j++)
    for (int k = 1; k <= cnt; k++)
      if (D[k][j]) addedge(F(j, k), F(j, D[k][j]));
  for (int i = 1; i <= n; i++) {
    memset(Dis, 0x3f, sizeof(Dis));
    for (int j = 1; j <= cnt; j++)
      if (U[j][b[i]]) Dis[U[j][b[i]]] = min(Dis[U[j][b[i]]], dis[j] + 1);
    for (int j = 1; j <= cnt; j++) dis[j] = Dis[j];
    memset(d, 0x3f, sizeof(d));
    for (int j = 1; j <= cnt; j++)
      d[F(a[i], j)] = dis[j], c[j] = make_pair(dis[j], j);
    sort(c + 1, c + 1 + cnt);
    for (int j = 1; j <= cnt; j++)
      if (c[j].first != INF) q.push(F(a[i], c[j].second));
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int e = Head[u]; e; e = Next[e]) {
        int v = vet[e];
        if (d[v] > d[u] + 1) d[v] = d[u] + 1, q.push(v);
      }
    }
    if (i == n)
      for (int j = 1; j <= 9; j++) ans = min(ans, d[F(j, 1)]);
    else
      for (int j = 1; j <= cnt; j++) dis[j] = d[F(a[i + 1], j)];
  }
  printf("%d\n", ans);
  return 0;
}
