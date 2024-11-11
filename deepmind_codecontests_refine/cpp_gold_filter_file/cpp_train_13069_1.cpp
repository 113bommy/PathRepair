#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200040;
struct Edge {
  int to, d;
  Edge* next;
} e[MAXN * 4], *head[MAXN];
int n;
void addedge(int f, int to, int d) {
  if (to == 0 || to == n + 1) return;
  static int ne = 0;
  e[ne].to = to, e[ne].d = d;
  e[ne].next = head[f];
  head[f] = e + ne++;
}
int dis[MAXN], q[MAXN], l, r;
bool in[MAXN];
void spfa() {
  memset(in, 0, sizeof in);
  for (int i = 1; i <= n; ++i) dis[i] = MAXN;
  dis[1] = 0, in[1] = 1;
  l = 0, r = 1;
  q[0] = 1;
  while (l ^ r) {
    int now = q[l++], ndis = dis[now];
    in[now] = 0;
    if (l == MAXN) l = 0;
    for (Edge* p = head[now]; p; p = p->next)
      if (dis[p->to] > ndis + p->d) {
        dis[p->to] = ndis + p->d;
        if (!in[p->to]) {
          q[r++] = p->to;
          in[p->to] = 1;
          if (r == MAXN) r = 0;
        }
      }
  }
}
int main() {
  scanf("%d", &n);
  int t;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t);
    addedge(i, t, 1);
    addedge(i, i + 1, 1);
    addedge(i, i - 1, 1);
  }
  spfa();
  for (int i = 1; i <= n; ++i) printf("%d%c", dis[i], i == n ? '\n' : ' ');
  return 0;
}
