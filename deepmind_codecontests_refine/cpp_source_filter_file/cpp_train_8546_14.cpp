#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
long long getint() {
  long long ret = 0;
  bool f = 0;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f ^= 1;
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return f ? -ret : ret;
}
using namespace std;
const int MAXN = 600;
namespace ISAP {
const int MAXM = MAXN * MAXN;
struct edge {
  int v, c;
  edge *nxt, *other;
  edge() {}
  edge(int _v, int _c, edge *_nxt, edge *_other) {
    v = _v;
    c = _c;
    nxt = _nxt;
    other = _other;
  }
} E[2 * MAXM + 10], *cnte = E, *fir[MAXN + 10];
void addedge(int u, int v, int c) {
  *cnte = edge(v, c, fir[u], cnte + 1);
  fir[u] = cnte++;
  *cnte = edge(u, 0, fir[v], cnte - 1);
  fir[v] = cnte++;
}
int dis[MAXN + 10], num[MAXN + 10], myq[MAXN + 10];
bool vis[MAXN + 10];
int s, t;
int aug(int u, int augc) {
  if (u == t) return augc;
  int stream, augs = 0, mindis = MAXN + 1, v;
  for (edge *p = fir[u]; p; p = p->nxt)
    if (p->c > 0) {
      v = p->v;
      if (dis[v] + 1 == dis[u]) {
        stream = min(p->c, augc - augs);
        stream = aug(v, stream);
        p->c -= stream;
        p->other->c += stream;
        augs += stream;
        if (dis[s] > MAXN || augs == augc) return augs;
      }
      mindis = min(mindis, dis[v]);
    }
  if (!augs) {
    if (!(--num[dis[u]])) dis[s] = MAXN + 1;
    ++num[dis[u] = mindis + 1];
  }
  return augs;
}
void prepare() {
  memset(dis, 0x3f, sizeof dis);
  int l = 0, r = 0;
  myq[++r] = t;
  vis[t] = 1;
  dis[t] = 0;
  num[0] = 1;
  while (l < r) {
    int u = myq[++l], v;
    for (edge *p = fir[u]; p; p = p->nxt)
      if (!vis[v = p->v]) {
        vis[v] = 1;
        ++num[dis[v] = dis[u] + 1];
        myq[++r] = v;
      }
  }
}
int work(int _s, int _t) {
  s = _s;
  t = _t;
  prepare();
  int ret = 0;
  while (dis[s] <= MAXN) ret += aug(s, INF);
  return ret;
}
}  // namespace ISAP
using ISAP::addedge;
using ISAP::work;
int val[MAXN + 10];
int main() {
  int n = getint();
  for (int i = 1; i <= n; ++i) {
    int m = getint();
    while (m--) {
      int j = getint();
      addedge(i, j + n, INF);
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; ++i) sum += max(0, val[i] = getint());
  int s = 2 * n + 1, t = 2 * n + 2;
  int w = 1;
  for (int i = 1; i <= n; ++i) {
    addedge(s, i, sum - val[i]);
    addedge(i + n, t, sum);
    w += sum - val[i];
  }
  printf("%d\n", work(s, t) - w);
}
