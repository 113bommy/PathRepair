#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5;
int n, all, tot = 0, m;
int pre[MaxN + 5], other[MaxN + 5], last[MaxN + 5], father[MaxN + 5],
    seq[MaxN + 5], ind[MaxN + 5];
struct node {
  int u, v;
} edge[MaxN + 5];
void build(int u, int v) {
  pre[++all] = last[u];
  last[u] = all;
  other[all] = v;
}
bool bfs() {
  int head = 1, tail = 0;
  for (int i = 1; i <= n; i++)
    if (ind[i] == 0) seq[++tail] = i;
  if (tail > 1) return 0;
  while (head <= tail) {
    int now = seq[head];
    int ed = other[now];
    int num = 0;
    while (ed != -1) {
      int dr = other[ed];
      if (--ind[dr] == 0) {
        father[dr] = now;
        seq[++tail] = dr;
        num++;
      }
      ed = pre[ed];
    }
    if (num > 1) return 0;
    head++;
  }
  return 1;
}
int main() {
  memset(last, -1, sizeof(last));
  all = -1;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    edge[i].u = x, edge[i].v = y;
    build(x, y);
    ind[y]++;
  }
  if (!bfs()) {
    printf("-1\n");
  } else {
    int ans = -1;
    for (int i = m; i >= 0; i--) {
      if (father[edge[i].v] == edge[i].u) {
        ans = i;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
