#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int cnt, deg[N], n;
double tim[N];
struct node {
  int v, id;
  node *next;
} pool[N << 1], *h[N];
void add(int u, int v, int id) {
  node *p = &pool[++cnt], *q = &pool[++cnt];
  p->v = v;
  p->next = h[u];
  h[u] = p;
  p->id = id;
  q->v = u;
  q->next = h[v];
  h[v] = q;
  q->id = id;
}
void pt(int u, int v, int id) {
  double t = tim[v];
  while (t >= 2.0) t -= 2.0;
  printf("%d %d ", 1, id);
  if (t <= 1.0)
    printf("%d %d %.6lf\n", u, v, 1 - t);
  else
    printf("%d %d %.6lf\n", v, u, t - 1);
}
void dfs(int u, int fa) {
  int d = deg[u], cur = 1;
  for (node *t = h[u]; t; t = t->next)
    if (t->v ^ fa) {
      tim[t->v] = tim[u] + cur * 2.0 / deg[u];
      pt(u, t->v, t->id);
      cur++;
      dfs(t->v, u);
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++)
    scanf("%d%d", &u, &v), add(u, v, i), deg[u]++, deg[v]++;
  int cur = 0;
  printf("%d\n", n - 1);
  for (node *t = h[1]; t; t = t->next) {
    tim[t->v] = 2.0 * cur / deg[1];
    pt(1, t->v, t->id);
    cur++;
    dfs(t->v, 1);
  }
}
