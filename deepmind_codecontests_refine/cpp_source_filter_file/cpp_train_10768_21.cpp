#include <bits/stdc++.h>
using namespace std;
const int N = 20005;
map<pair<int, int>, int> ch;
int n, m;
int totV = 1;
int S = 0;
int T = 1;
int tot = 1;
int head[N], np[N * 20], flow[N * 20], p[N * 20];
int A[55], B[55], C[55], l[55], r[55];
const int inf = 1e9;
const int Max = 1e6;
inline void link(int a, int b, int c) {
  tot++;
  p[tot] = b;
  np[tot] = head[a];
  head[a] = tot;
  flow[tot] = c;
  tot++;
  p[tot] = a;
  np[tot] = head[b];
  head[b] = tot;
  flow[tot] = 0;
}
int q[N], dis[N];
int BFS() {
  memset(dis, -1, sizeof dis);
  q[q[0] = 1] = S;
  dis[S] = 0;
  for (int i = (1); i <= (int)q[0]; i++) {
    int x = q[i];
    for (int u = head[x]; u; u = np[u])
      if (flow[u] && dis[p[u]] == -1) {
        dis[p[u]] = dis[x] + 1;
        q[++q[0]] = p[u];
      }
  }
  return dis[T];
}
int dinic(int x, int fl) {
  int ret = 0;
  if (x == T) return fl;
  for (int u = head[x]; u; u = np[u])
    if (flow[u] && dis[p[u]] == dis[x] + 1) {
      int tmp = dinic(p[u], min(fl, flow[u]));
      flow[u] -= tmp;
      flow[u ^ 1] += tmp;
      ret += tmp;
      fl -= tmp;
    }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (int)n; i++) scanf("%d%d%d", &A[i], &B[i], &C[i]);
  for (int i = (1); i <= (int)n; i++) scanf("%d%d", &l[i], &r[i]);
  for (int i = (1); i <= (int)n; i++) {
    for (int j = (l[i] - 1); j <= (int)r[i]; j++) {
      pair<int, int> fuck = pair<int, int>(i, j);
      ch[fuck] = ++totV;
      if (j == l[i] - 1)
        link(S, totV, inf);
      else
        link(totV - 1, totV, Max - (A[i] * j * j + B[i] * j + C[i]));
    }
    link(totV, T, inf);
  }
  while (m--) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    for (int i = (l[u]); i <= (int)r[u]; i++)
      if (i - d >= l[v] && i - d <= r[v]) {
        pair<int, int> f1 = pair<int, int>(u, i);
        pair<int, int> f2 = pair<int, int>(v, i - d);
        link(ch[f1], ch[f2], inf);
      }
  }
  int ans = 0;
  while (BFS() != -1) {
    ans += dinic(S, inf);
  }
  printf("%d\n", Max * n - ans);
  return 0;
}
