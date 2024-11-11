#include <bits/stdc++.h>
const int MaxL = 600;
const int Size = 605;
const int oo = 0x3fffffff;
using namespace std;
struct Edge {
  int v, f, w;
  Edge* next;
  Edge* opp;
} P[Size], E[605 * Size], *pre[Size];
int f[MaxL], a[MaxL];
int n, m, s, t;
int El, ans;
int top, mark[MaxL], last[MaxL];
char ret[1010][30];
void insert(int a, int b, int c, int w) {
  Edge* e = &E[El++];
  e->v = b, e->f = c, e->w = w, e->next = P[a].next, P[a].next = e;
}
void addEdge(int a, int b, int c, int w) {
  insert(a, b, c, w), insert(b, a, 0, -w);
  P[a].next->opp = &E[El - 1];
  P[b].next->opp = &E[El - 2];
}
int dist[Size];
bool spfa() {
  for (int i = s; i <= t; i++) dist[i] = oo;
  dist[s] = 0;
  for (int x = s, flag = 1; x < t && flag; x++) {
    flag = 0;
    for (int i = s; i <= t; i++) {
      for (Edge* e = P[i].next; e != NULL; e = e->next) {
        if (e->f <= 0) continue;
        int k = e->v;
        if (dist[i] + e->w < dist[k]) {
          dist[k] = dist[i] + e->w, pre[k] = e;
          flag = 1;
        }
      }
    }
  }
  return (dist[t] < oo);
}
void work() {
  int k = t, Min = oo;
  Edge* e = NULL;
  while (k != s) {
    e = pre[k];
    if (e->f < Min) Min = e->f;
    k = e->opp->v;
  }
  k = t;
  while (k != s) {
    e = pre[k];
    e->f -= Min;
    e->opp->f += Min;
    k = e->opp->v;
  }
  ans += Min * dist[t];
}
int calc(int n) {
  if (n == 0) return 0;
  int ans = 0;
  for (; n; n -= (n & -n)) ans++;
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    f[i] = calc(a[i]);
  }
  s = 0, t = m + 2 * n + 1, ans = 0, top = 0;
  ;
  El = 0;
  for (int i = s; i <= t; i++) P[i].next = NULL;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++)
      if (a[i] == a[j])
        addEdge(i, j + n + m, 1, 0);
      else
        addEdge(i, j + n + m, 1, f[j]);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) addEdge(i + n, j + n + m, 1, f[j]);
  for (int i = 1; i <= n + m; i++) addEdge(s, i, 1, 0);
  for (int i = 1; i <= n; i++) addEdge(i + n + m, t, 1, 0);
  while (spfa()) work();
  memset(mark, -1, sizeof(mark));
  memset(last, -1, sizeof(last));
  for (int i = 1; i <= m; i++)
    for (Edge* e = P[i + n].next; e; e = e->next) {
      if (e->v == s) continue;
      int k = e->v - n - m;
      if (e->opp->f) mark[k] = i;
    }
  for (int i = 1; i <= n; i++)
    for (Edge* e = P[i].next; e; e = e->next) {
      if (e->v == s) continue;
      int k = e->v - n - m;
      if (e->opp->f) mark[k] = mark[i];
    }
  for (int i = 1; i <= n; i++) {
    char ch = 'a' + mark[i] - 1;
    if (last[mark[i]] != a[i]) sprintf(ret[top++], "%c=%d", ch, a[i]);
    sprintf(ret[top++], "print(%c)", ch);
    last[mark[i]] = a[i];
  }
  printf("%d %d\n", top, ans);
  for (int i = 0; i < top; i++) puts(ret[i]);
  return 0;
}
