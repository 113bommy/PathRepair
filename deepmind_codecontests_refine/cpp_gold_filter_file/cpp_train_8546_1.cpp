#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300;
const int INF = 0x3f3f3f3f;
const long long int LLF = 0x3f3f3f3f3f3f3f3fll;
template <class T>
void Read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = 0;
  while (c < '0' || '9' < c) {
    if (c == '-') flag = 1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = (x + (x << 2) << 1) + c - '0';
    c = getchar();
  }
  if (flag) x = -x;
}
namespace ISAP {
const int MAXP = MAXN * 2;
const int MAXE = MAXN * MAXN * 4;
struct node {
  int v;
  long long int c;
  node *nxt, *bck;
} * adj[MAXP + 10], Edges[MAXE * 2 + 10], *New;
inline void addedges(int u, int v, long long int c) {
  node *p = ++New;
  p->v = v;
  p->c = c;
  p->bck = New + 1;
  p->nxt = adj[u];
  adj[u] = p;
  p = ++New;
  p->v = u;
  p->c = 0;
  p->bck = New - 1;
  p->nxt = adj[v];
  adj[v] = p;
}
int S, T, P;
int d[MAXP + 10], vd[MAXP + 10];
inline void init(int s, int t, int p) {
  S = s, T = t, P = p;
  memset(adj, 0, sizeof(adj));
  New = Edges;
}
long long int aug(int x, long long int augco) {
  if (x == T) return augco;
  long long int delta, augc = augco;
  int Dmin = P - 1;
  for (node *p = adj[x]; p != NULL; p = p->nxt)
    if (p->c) {
      if (d[x] == d[p->v] + 1) {
        delta = min(augc, p->c);
        delta = aug(p->v, delta);
        p->c -= delta;
        p->bck->c += delta;
        augc -= delta;
        if (d[S] >= P) return augco - augc;
        if (!augc) break;
      }
      Dmin = min(Dmin, d[p->v]);
    }
  if (augco == augc) {
    if (!--vd[d[x]]) d[S] = P;
    ++vd[d[x] = Dmin + 1];
  }
  return augco - augc;
}
inline long long int isap() {
  memset(vd, 0, sizeof(vd));
  memset(d, 0, sizeof(d));
  vd[0] = P;
  long long int ret = 0;
  while (d[S] < P) ret += aug(S, LLF);
  return ret;
}
}  // namespace ISAP
int n;
int main() {
  Read(n);
  ISAP::init(n * 2 + 1, n * 2 + 2, n * 2 + 2);
  int a, b;
  for (int i = 1; i <= n; ++i) {
    Read(a);
    while (a--) {
      Read(b);
      ISAP::addedges(i, n + b, INF << 1);
    }
  }
  long long int sum = 0;
  for (int i = 1; i <= n; ++i) {
    Read(a);
    ISAP::addedges(ISAP::S, i, INF - a);
    ISAP::addedges(n + i, ISAP::T, INF);
    sum += INF - a;
  }
  sum = min(0ll, -(sum - ISAP::isap()));
  printf("%I64d\n", sum);
}
