#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
struct edge {
  int x, y;
  long long w;
  inline bool operator<(const edge &y) const { return w < y.w; }
} e[MAXN], E[MAXN];
priority_queue<pair<long long, int> > h;
int i, j, k, N, M, x, y, cnt, st[MAXN], nxt[MAXN << 1], lnk[MAXN << 1],
    wi[MAXN << 1];
int fa[MAXN], pre[MAXN];
long long mi, ans, d[MAXN];
inline void AddEdge(int x, int y, int z) {
  lnk[++cnt] = y, nxt[cnt] = st[x], st[x] = cnt, lnk[++cnt] = x,
  nxt[cnt] = st[y], st[y] = cnt, wi[cnt - 1] = wi[cnt] = z;
}
inline int FindSet(int x) { return fa[x] ? fa[x] = FindSet(fa[x]) : x; }
void init() {
  scanf("%d%d", &N, &M);
  for (i = 1; i <= M; i++) {
    scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
    AddEdge(e[i].x, e[i].y, e[i].w);
  }
  (memset(d, 60, sizeof(d)));
  for (scanf("%d", &k); k--;) {
    scanf("%d", &x);
    d[x] = 0, pre[x] = x, h.push(make_pair(0, x));
  }
}
void work() {
  while (!h.empty()) {
    x = h.top().second, mi = h.top().first, h.pop();
    if (d[x] + mi) continue;
    for (i = st[x]; i; i = nxt[i])
      if (d[x] + wi[i] < d[lnk[i]])
        d[lnk[i]] = d[x] + wi[i], pre[lnk[i]] = pre[x],
        h.push(make_pair(mi - wi[i], lnk[i]));
  }
  for (i = 1; i <= M; i++)
    E[i].x = pre[e[i].x], E[i].y = pre[e[i].y],
    E[i].w = e[i].w + d[e[i].x] + d[e[i].y];
  sort(E + 1, E + M + 1);
  for (i = 1; i <= M; i++) {
    x = FindSet(E[i].x), y = FindSet(E[i].y);
    if (x != y) fa[x] = y, ans += E[i].w;
  }
  printf("%I64d\n", ans + d[1]);
}
int main() {
  init();
  work();
  return 0;
}
