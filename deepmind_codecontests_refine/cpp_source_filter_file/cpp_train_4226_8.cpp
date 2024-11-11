#include <bits/stdc++.h>
using namespace std;
long long Ans = 1000000000000000000LL;
int n, m, num, l, r, u, v, en, now = 0, opp, pp, p, q;
struct Tp {
  int u, v, g, s;
} a[100005];
bool visit[205];
int Head[205], Next[100005], c[100005], f[205];
int ls[205], Edge[100005], Q[205], fa[205], pre[205];
long long G, S;
int getfa(int x) {
  if (f[x] == x) return x;
  f[x] = getfa(f[x]);
  return f[x];
}
void Add(int u, int v, int x) {
  Edge[++num] = v, Next[num] = Head[u], Head[u] = num, c[num] = x;
  Edge[++num] = u, Next[num] = Head[v], Head[v] = num, c[num] = x;
}
int Cmp(const void *a, const void *b) {
  const Tp *A = (const Tp *)a;
  const Tp *B = (const Tp *)b;
  return A->g - B->g;
}
void bfs(int x) {
  Q[l = r = 1] = x, visit[x] = 1, fa[x] = 0;
  for (; l <= r; ++l) {
    u = Q[l];
    for (int k = Head[u]; k; k = Next[k]) {
      v = Edge[k];
      if (!visit[v]) {
        visit[v] = 1, fa[v] = u, pre[v] = c[k];
        if (v == en) return;
        Q[++r] = v;
      }
    }
  }
}
void work(int o) {
  if (!ls[0]) {
    ls[++ls[0]] = o;
    now = a[o].s;
    return;
  }
  memset(Head, 0, sizeof(Head));
  memset(visit, 0, sizeof(visit));
  num = 0;
  for (int i = 1; i <= ls[0]; ++i) Add(a[ls[i]].u, a[ls[i]].v, i);
  en = a[o].v;
  bfs(a[o].u);
  u = a[o].u, v = a[o].v, opp = 0, pp = 0;
  for (; v != u;) {
    if (a[ls[pre[v]]].s > opp) opp = a[ls[pre[v]]].s, pp = pre[v];
    v = fa[v];
  }
  if (opp > a[o].s) {
    ls[pp] = o, now = 0;
    for (int i = 1; i <= ls[0]; ++i) now = max(now, a[ls[i]].s);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%I64d%I64d", &G, &S);
  for (int i = 1; i <= m; ++i)
    scanf("%d%d%d%d", &a[i].u, &a[i].v, &a[i].g, &a[i].s);
  qsort(a + 1, m, sizeof(a[0]), Cmp);
  for (int i = 1; i <= n; ++i) f[i] = i;
  for (int i = 1; i <= m; ++i) {
    p = getfa(a[i].u), q = getfa(a[i].v);
    if (p != q) {
      f[p] = q;
      ls[++ls[0]] = i;
      now = max(now, a[i].s);
    } else if (a[i].u != a[i].v && a[i].s < now)
      work(i);
    if (ls[0] == n - 1) Ans = min(Ans, G * a[i].g + S * now);
  }
  if (ls[0] == n - 1)
    printf("%I64d\n", Ans);
  else
    puts("-1");
  return 0;
}
