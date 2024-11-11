#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  int ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void rt(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10)
    rt(x / 10), putchar(x % 10 + '0');
  else
    putchar(x + '0');
}
const int maxn = 16005, V = 100005, inf = 100, maxm = 1000000;
int g[10], h[maxn], id[V], a[maxn], dsc[maxn], m;
int n, S, T, ndc = 0;
int to[maxm], nx[maxm], hd[maxn], cap[maxm], cost[maxm], cnt;
void addedge(int u, int v, int cp, int w) {
  to[cnt] = v;
  nx[cnt] = hd[u];
  cap[cnt] = cp;
  cost[cnt] = w;
  hd[u] = cnt++;
  to[cnt] = u;
  nx[cnt] = hd[v];
  cap[cnt] = 0;
  cost[cnt] = -w;
  hd[v] = cnt++;
}
void newnode(int &x) {
  int y = ++ndc;
  addedge(x, y, inf, 0);
  x = y;
}
int que[maxn], he, ta;
int dist[maxn], p[maxn];
bool vis[maxn];
bool upd(int &x, int y) {
  if (y > x) return x = y, 1;
  return 0;
}
void spfa() {
  he = 1, ta = 0;
  que[++ta] = S;
  memset(dist, 160, sizeof dist);
  dist[S] = 0;
  while (he <= ta) {
    int u = que[(he++) % maxn];
    vis[u] = 0;
    for (int i = hd[u]; ~i; i = nx[i]) {
      int v = to[i];
      if (cap[i] && upd(dist[v], dist[u] + cost[i])) {
        p[v] = i;
        if (!vis[v]) vis[v] = 1, que[(++ta) % maxn] = v;
      }
    }
  }
}
int mcmf() {
  int ret = 0;
  for (int it = int(1); it <= (int)(4); it++) {
    spfa();
    ret += dist[T];
    int nw = T;
    while (nw != S) {
      cap[p[nw]]--, cap[p[nw] ^ 1]++;
      nw = to[p[nw] ^ 1];
    }
  }
  return ret;
}
int main() {
  n = rd();
  for (int i = int(1); i <= (int)(n); i++) a[i] = rd();
  for (int i = int(1); i <= (int)(n); i++) dsc[++m] = a[i];
  sort(dsc + 1, dsc + m + 1);
  m = unique(dsc + 1, dsc + m + 1) - dsc - 1;
  for (int i = int(1); i <= (int)(m); i++) id[dsc[i]] = i;
  memset(hd, -1, sizeof hd);
  cnt = 0;
  S = 0;
  T = 16000;
  ndc = 2 * n;
  for (int i = int(0); i <= (int)(6); i++) newnode(g[i]);
  for (int i = int(1); i <= (int)(m); i++) newnode(h[i]);
  for (int i = int(1); i <= (int)(n); i++) {
    int inn = i * 2 - 1, otn = i * 2, x = id[a[i]];
    addedge(inn, otn, 1, 1);
    addedge(otn, T, 1, 0);
    if (x > 1 && dsc[x - 1] + 1 == dsc[x]) addedge(h[x - 1], inn, 1, 0);
    if (x < m && dsc[x + 1] - 1 == dsc[x]) addedge(h[x + 1], inn, 1, 0);
    addedge(g[a[i] % 7], inn, 1, 0);
    newnode(h[x]);
    addedge(otn, h[x], 1, 0);
    newnode(g[a[i] % 7]);
    addedge(otn, g[a[i] % 7], 1, 0);
  }
  rt(mcmf()), putchar('\n');
}
