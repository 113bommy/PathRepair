#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
int head[1010];
bool IsIn[1010];
int n, m;
struct EDGE {
  int u, v, c, next;
};
EDGE edg[1010], prit[1010];
int e, cnt;
void AddEdge(int u, int v, int c) {
  edg[e].u = u;
  edg[e].v = v;
  edg[e].c = c;
  edg[e].next = head[u];
  head[u] = e;
}
void dfs(int i, int maxd) {
  if (head[i] == -1) {
    prit[cnt].v = i;
    prit[cnt++].c = maxd;
    return;
  }
  for (int ne = head[i]; ne != -1; ne = edg[ne].next) {
    dfs(edg[ne].v, min(maxd, edg[ne].c));
    break;
  }
}
int main() {
  int d, u, v;
  memset(head, -1, sizeof(head));
  memset(IsIn, 0, sizeof(IsIn));
  scanf("%d %d", &n, &m);
  for (e = 0; e < m; e++) {
    scanf("%d %d %d", &u, &v, &d);
    AddEdge(u, v, d);
    IsIn[v] = true;
  }
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!IsIn[i]) {
      prit[cnt].u = i;
      dfs(i, INF);
      if (prit[cnt - 1].v == i) cnt--;
    }
  }
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) {
    printf("%d %d %d\n", prit[i].u, prit[i].v, prit[i].c);
  }
  return 0;
}
